#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to calculate letter frequencies in the ciphertext
void calculateFrequency(const char *ciphertext, int frequency[ALPHABET_SIZE]) {
    for (size_t i = 0; i < strlen(ciphertext); i++) {
        char currentChar = tolower(ciphertext[i]);
        if (isalpha(currentChar)) {
            frequency[currentChar - 'a']++;
        }
    }
}

// Function to print the top N likely plaintexts based on letter frequencies
void printTopPlaintexts(int frequency[ALPHABET_SIZE], int topN) {
    printf("Top %d likely plaintexts:\n", topN);

    // Create a mapping of letters to their frequencies
    char letterFrequency[ALPHABET_SIZE];
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        letterFrequency[i] = i + 'a';
    }

    // Sort the letters based on frequencies (descending order)
    for (int i = 0; i < ALPHABET_SIZE - 1; i++) {
        for (int j = i + 1; j < ALPHABET_SIZE; j++) {
            if (frequency[j] > frequency[i]) {
                // Swap letters
                char tempChar = letterFrequency[i];
                letterFrequency[i] = letterFrequency[j];
                letterFrequency[j] = tempChar;

                // Swap frequencies
                int tempFreq = frequency[i];
                frequency[i] = frequency[j];
                frequency[j] = tempFreq;
            }
        }
    }

    // Print the top N likely plaintexts
    for (int i = 0; i < topN; i++) {
        printf("%c: %d occurrences\n", letterFrequency[i], frequency[i]);
    }
}

int main() {
    // Example ciphertext
    const char *ciphertext = "Lqyrkz zj Kjhzk Pjzye!";
    
    // Initialize the frequency array
    int frequency[ALPHABET_SIZE] = {0};

    // Calculate letter frequencies in the ciphertext
    calculateFrequency(ciphertext, frequency);

    // Specify the number of top likely plaintexts to display
    int topN = 10;

    // Print the top N likely plaintexts
    printTopPlaintexts(frequency, topN);

    return 0;
}
 
