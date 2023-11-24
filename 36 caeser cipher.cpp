#include <stdio.h>
#include <ctype.h>

// Function to encrypt a single character using affine cipher
char encryptChar(int a, int b, char ch) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        return (char)(((a * (ch - base) + b) % 26 + 26) % 26 + base);
    } else {
        return ch;
    }
}

// Function to encrypt a string using affine cipher
void encryptString(int a, int b, char *plaintext, char *ciphertext) {
    int i = 0;
    while (plaintext[i] != '\0') {
        ciphertext[i] = encryptChar(a, b, plaintext[i]);
        i++;
    }
    ciphertext[i] = '\0';
}

int main() {
    int a, b;

    // Get user input for key values a and b
    printf("Enter the values of a and b for the affine cipher (space-separated): ");
    scanf("%d %d", &a, &b);

    // Check if 'a' is coprime with 26
    if (a % 2 == 0 || a % 13 == 0) {
        printf("Invalid value of 'a'. It must be coprime with 26.\n");
        return 1;
    }

    // Flush the input buffer
    while (getchar() != '\n');

    // Get user input for plaintext
    char plaintext[1000];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove trailing newline character from fgets
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    // Encrypt the plaintext
    char ciphertext[1000];
    encryptString(a, b, plaintext, ciphertext);

    // Display the encrypted text
    printf("Encrypted Text: %s\n", ciphertext);

    return 0;
}

