#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateCipherAlphabet(char keyword[], char cipherAlphabet[]) {
    int keywordLength = strlen(keyword);
    int i, j;

    for (i = 0; i < keywordLength; i++) {
        cipherAlphabet[i] = toupper(keyword[i]);
    }
    char currentLetter = 'A';
    for (i = keywordLength; i < 26; i++) {
        int found = 0;
        for (j = 0; j < keywordLength; j++) {
            if (toupper(currentLetter) == cipherAlphabet[j]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            cipherAlphabet[i] = currentLetter;
            currentLetter++;
        } else {
            currentLetter++;
            i--; 
        }
    }
}
void encryptMonoalphabetic(char plaintext[], char cipherAlphabet[], char ciphertext[]) {
    int length = strlen(plaintext);
    int i;

    for (i = 0; i < length; i++) {
        if (isalpha(plaintext[i])) {
            char originalChar = toupper(plaintext[i]);
            if (isupper(plaintext[i])) {
                ciphertext[i] = cipherAlphabet[originalChar - 'A'];
            } else {
                ciphertext[i] = tolower(cipherAlphabet[originalChar - 'A']);
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[i] = '\0';
}

int main() {
    char keyword[] = "CIPHER";
    char plaintext[] = "Hello, World!";

    for (int i = 0; i < strlen(keyword); i++) {
        keyword[i] = toupper(keyword[i]);
    }

    char cipherAlphabet[26];
    generateCipherAlphabet(keyword, cipherAlphabet);

    char ciphertext[strlen(plaintext) + 1];
    encryptMonoalphabetic(plaintext, cipherAlphabet, ciphertext);

    printf("Plaintext:  %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

