#include <stdio.h>
#include <string.h>

// Function to XOR encrypt/decrypt a string
void xor_encrypt_decrypt(char *input, char *key, char *output) {
    int input_len = strlen(input);
    int key_len = strlen(key);

    for (int i = 0; i < input_len; i++) {
        output[i] = input[i] ^ key[i % key_len];  // XOR each byte with the key
    }
    output[input_len] = '\0';  // Null-terminate the result
}

int main() {
    char input[] = "Hello, World!";
    char key[] = "key";  // This is the encryption key
    char output[sizeof(input)];  // Buffer for encrypted/decrypted data

    // Encrypt the input
    xor_encrypt_decrypt(input, key, output);
    printf("Encrypted: %s\n", output);

    // Decrypt the encrypted output (since XOR is symmetric)
    xor_encrypt_decrypt(output, key, output);
    printf("Decrypted: %s\n", output);

    return 0;
}
