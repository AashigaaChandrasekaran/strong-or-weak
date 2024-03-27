#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_strong_password(char *password) {
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    int length = strlen(password);
    if (length <= 8)
        return 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i]))
            has_upper = 1;
        else if (islower(password[i]))
            has_lower = 1;
        else if (isdigit(password[i]))
            has_digit = 1;
        else if (!isalnum(password[i]))
            has_special = 1;
    }

    return (has_upper && has_lower && has_digit && has_special);
}

int main() {
    char password[100];
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; // Removing trailing newline

    if (is_strong_password(password))
        printf("Strong password.\n");
    else
        printf("Weak password.\n");

    return 0;
}
