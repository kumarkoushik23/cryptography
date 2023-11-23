#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decryptAdditiveCipher(const char *ciphertext, int key, char *plaintext) {
    int len = strlen(ciphertext);

    for (int i = 0; i < len; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = ((ciphertext[i] - 'A' - key + 26) % 26) + 'A';
        } else {
            plaintext[i] = ciphertext[i];
        }
    }

    plaintext[len] = '\0';
}
void calculateLetterFrequency(const char *text, int *frequency) {
    int len = strlen(text);

    for (int i = 0; i < len; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            frequency[text[i] - 'A']++;
        }
    }
}

// Function to find the key based on the most common letter frequency
int findKey(int *frequency) {
    int maxFrequency = 0;
    int maxIndex = 0;

    for (int i = 0; i < 26; i++) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            maxIndex = i;
        }
    }
    int key = (maxIndex - ('E' - 'A') + 26) % 26;
    return key;
}

int main() {
    const char *ciphertext = "WKLVLVDOOVRPHWKLQJLQIRUWKHHVWDWHLVWUXVWHHSLQHVV";
    char plaintext[100]; 
    int frequency[26] = {0};

    calculateLetterFrequency(ciphertext, frequency);

    int key = findKey(frequency);

    decryptAdditiveCipher(ciphertext, key, plaintext);

    printf("Ciphertext: %s\n", ciphertext);
    printf("Key: %d\n", key);
    printf("Decrypted Plaintext: %s\n", plaintext);

    return 0;
}

