#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "monocypher.h"
#include "keys.h"
#include "message1.h"
#include "message2.h"
#include "message3.h"

void try_decrypt(const char* label, const uint8_t* sender_pk, const uint8_t* rx_sk,
                 const uint8_t* nonce, const uint8_t* mac, const uint8_t* ciphertext, size_t len) {
    // Buffer to store the shared symmetric key calculated from the key exchange
    uint8_t shared_key[32];
    // Perform key exchange to get the shared symmetric key
    crypto_key_exchange(shared_key, rx_sk, sender_pk);
    // Buffer to store the decrypted message
    uint8_t decrypted[len];
    // Decrypt the ciphertext using the shared key, nonce and MAC
    int ok = crypto_unlock(decrypted, shared_key, nonce, mac, ciphertext, len);
    // Print the label of the message
    printf("\n%s:\n", label);
    if (ok == 0) {
        printf("Decryption successful:\n%.*s\n", (int)len, decrypted);
    } else {
        printf("Decryption failed (MAC invalid or corrupted message).\n");
    }
}

int main() {
    // Decrypt the  message
    try_decrypt("Message 1", tx1_pk, rx_sk, nonce1, mac1, cipher_text1, sizeof(cipher_text1));
    try_decrypt("Message 2", tx2_pk, rx_sk, nonce2, mac2, cipher_text2, sizeof(cipher_text2));
    try_decrypt("Message 3", tx3_pk, rx_sk, nonce3, mac3, cipher_text3, sizeof(cipher_text3));
    return 0;
}
