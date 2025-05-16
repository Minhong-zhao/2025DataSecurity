#include <stdio.h>

int check_password() {
    char password[10];
    gets(password);
    return 0;
}

int main() {
    char username[10];
    int allow = 0;

    printf("Enter username.\n");
    fgets(username, 10, stdin);

    while (!allow) {
        printf("Enter password.\n");
        allow = check_password();
    }
    
    printf("Welcome.\n");

}

