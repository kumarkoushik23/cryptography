#include <stdio.h>
#include <stdint.h>

// S-DES functions
void generateRoundKeys(uint8_t key, uint8_t roundKeys[2]);
uint8_t feistel(uint8_t data, uint8_t key);
uint8_t encrypt(uint8_t plaintext, uint8_t key, uint8_t counter);
uint8_t decrypt(uint8_t ciphertext, uint8_t key, uint8_t counter);

int main() {
    // Test data
    uint8_t plaintext = 0b00000010;
    uint8_t key = 0b0111111101;
    uint8_t counter = 0b00000000;

    // Encryption
    uint8_t ciphertext = encrypt(plaintext, key, counter);
    printf("Encrypted: %02x\n", ciphertext);

    // Decryption
    uint8_t decryptedText = decrypt(ciphertext, key, counter);
    printf("Decrypted: %02x\n", decryptedText);

    return 0;
}

void generateRoundKeys(uint8_t key, uint8_t roundKeys[2]) {
    // Implementation of key generation (you need to implement this function)
}

uint8_t feistel(uint8_t data, uint8_t key) {
    // Implementation of the Feistel function (you need to implement this function)
}

uint8_t encrypt(uint8_t plaintext, uint8_t key, uint8_t counter) {
    uint8_t roundKeys[2];
    generateRoundKeys(key, roundKeys);

    // XOR the plaintext with the counter
    uint8_t input = plaintext ^ counter;

    // Initial permutation (you need to implement this function)
    // uint8_t initialPermuted = initialPermutation(input);

    // Split the 8-bit data into two 4-bit halves
    uint8_t left = (input >> 4) & 0x0F;
    uint8_t right = input & 0x0F;

    // Perform two rounds of Feistel network
    for (int i = 0; i < 2; ++i) {
        uint8_t temp = right;
        right = left ^ feistel(right, roundKeys[i]);
        left = temp;
    }

    // Final permutation (you need to implement this function)
    // uint8_t finalPermuted = finalPermutation((left << 4) | right);

    // Return the result
    return (left << 4) | right;
}

uint8_t decrypt(uint8_t ciphertext, uint8_t key, uint8_t counter) {
    // Decryption is the same as encryption in counter mode
    return encrypt(ciphertext, key, counter);
}

