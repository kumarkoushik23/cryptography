#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to calculate letter frequencies in the given text
void calculateFrequencies(const char *text, int *frequencies) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char letter = tolower(text[i]);
            frequencies[letter - 'a']++;
        }
    }
}

// Function to display the frequencies of letters
void displayFrequencies(const int *frequencies) {
    printf("Letter Frequencies:\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        printf("%c: %d\n", 'a' + i, frequencies[i]);
    }
    printf("\n");
}

// Function to perform a letter frequency attack
void frequencyAttack(const char *ciphertext) {
    int frequencies[ALPHABET_SIZE] = {0};
    calculateFrequencies(ciphertext, frequencies);
    displayFrequencies(frequencies);

    // Create a writable copy of the ciphertext
    char plaintext[1024];
    strcpy(plaintext, ciphertext);

    // Sorting frequencies in descending order
    for (int i = 0; i < ALPHABET_SIZE - 1; i++) {
        for (int j = i + 1; j < ALPHABET_SIZE; j++) {
            if (frequencies[i] < frequencies[j]) {
                // Swap frequencies
                int temp = frequencies[i];
                frequencies[i] = frequencies[j];
                frequencies[j] = temp;

                // Swap corresponding letters in the plaintext copy
                char tempChar = 'a' + i;
                for (int k = 0; plaintext[k] != '\0'; k++) {
                    if (tolower(plaintext[k]) == tempChar) {
                        plaintext[k] = 'a' + j;
                    } else if (tolower(plaintext[k]) == 'a' + j) {
                        plaintext[k] = tempChar;
                    }
                }
            }
        }
    }

    printf("Possible Plaintexts:\n");
    printf("%s\n", plaintext);
}

int main() {
    // Example ciphertext
    const char *ciphertext = "Gur Checbfr bs gur Pbyhzaf";

    frequencyAttack(ciphertext);

    return 0;
}

