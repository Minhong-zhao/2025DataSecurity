#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "monocypher.h"
#include "keys.h"  // rx_sk
#include "devurandom_windows.h"
void hex_dump(const uint8_t *data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("0x%02x, ", data[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n");
}
int main() {
    // Step 1: Generate private + public key
    uint8_t my_sk[32];
    uint8_t my_pk[32];
    randombytes(my_sk, 32);
    crypto_key_exchange_public_key(my_pk, my_sk);
    // Step 2: Generate shared key
    uint8_t shared_key[32];
    crypto_key_exchange(shared_key, my_sk, rx_sk); // receiver's public key from keys.h
    // Step 3: Generate nonce
    uint8_t nonce[24];
    randombytes(nonce, 24);
    // Step 4: Encrypt message
    const char* msg = "Don't rush, feel the way.";
    size_t msg_len = strlen(msg);
    uint8_t ciphertext[msg_len];
    uint8_t mac[16];
    crypto_lock(mac, ciphertext, shared_key, nonce, (const uint8_t*)msg, msg_len);
    // Step 5: Print results
    printf("My original message:\n");
    printf("%s\n", msg);
    printf("\nEncrypted message:\n");
    hex_dump(ciphertext, msg_len);
    printf("\nMAC:\n");
    hex_dump(mac, 16);
    printf("Nonce:\n");
    hex_dump(nonce, 24);
    return 0;
}
