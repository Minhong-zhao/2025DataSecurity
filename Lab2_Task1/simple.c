#include <stdio.h>

int main() {
    char username[10];
    int allow = 0;
    char password[10];

    printf("Enter username.\n");
    gets(username);

    while (!allow) {
        printf("Enter password.\n");
        gets(password);
        // allow = (hash(password)==xxx);

        printf("allow: %d", allow);
    }
    
    printf("Welcome.\n");

}

