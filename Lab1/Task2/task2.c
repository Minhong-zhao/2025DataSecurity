#include <stdio.h>
#include "comic.h"
#include "monocypher.h"

// Hard-coded message.
char input[] = "Hello world!\n";
// Compute size of message (including any terminating null byte).
int input_size = sizeof(input)/sizeof(input[0]);

// Print out hex encoding of a buffer.
void dump_hex(char* buf, int s) {
    for (int n = 0; n < s; n++) {
        printf("0x%02hhx, ", buf[n]);
    }
}

// Print out hex encoding of a buffer as a C variable definition.
void dump_hex_var(char* name, char* buf, int s) {
    printf("char %s[] = {", name);
    dump_hex(buf, s);
    printf("};\n");
}

int main()
{
int len = sizeof(cipher_text);
char p_text[sizeof(cipher_text)];
crypto_unlock(p_text, key, nonce, mac, cipher_text, len);
printf("p_text is: %s", p_text);
printf("\nLength of cipher_text is: %d", len);
return 0;
}
