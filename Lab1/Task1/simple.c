#include <stdio.h>

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

int main() {
    printf("Printing output:\n");
    fwrite(input, 1, input_size, stdout);
    printf("Dumping hex:\n");
    dump_hex_var("output", input, input_size);
}

