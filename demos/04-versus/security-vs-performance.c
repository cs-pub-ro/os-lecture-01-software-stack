#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

#define PASSWORD_LENGTH 12
#define ITERATIONS 10000000

// Function to generate a random password
void generate_password(char* password) {
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
	for (int i = 0; i < PASSWORD_LENGTH; i++) {
		password[i] = charset[rand() % (sizeof(charset) - 1)];
	}
	password[PASSWORD_LENGTH] = '\0';
}

// Function to perform a simple hash (less secure, but faster)
void simple_hash(const char* input, char* output) {
	unsigned long hash = 5381;
	int c;
	while ((c = *input++)) {
		hash = ((hash << 5) + hash) + c;
	}
	sprintf(output, "%lu", hash);
}

// Function to perform a secure hash (more secure, but slower)
void secure_hash(const char* input, char* output) {
	unsigned char hash[SHA256_DIGEST_LENGTH];
	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	SHA256_Update(&sha256, input, strlen(input));
	SHA256_Final(hash, &sha256);
	for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
		sprintf(output + (i * 2), "%02x", hash[i]);
	}
	output[SHA256_DIGEST_LENGTH * 2] = '\0';
}

int main() {
	char password[PASSWORD_LENGTH + 1];
	char simple_hash_result[20];
	char secure_hash_result[SHA256_DIGEST_LENGTH * 2 + 1];
	clock_t start, end;
	double cpu_time_used;

	// Generate a random password
	srand(time(NULL));
	generate_password(password);
	printf("Generated password: %s\n", password);

	// Measure time for simple hash
	start = clock();
	for (int i = 0; i < ITERATIONS; i++) {
		simple_hash(password, simple_hash_result);
	}
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken for simple hash (%d iterations): %f seconds\n", ITERATIONS, cpu_time_used);
	printf("Simple hash result: %s\n", simple_hash_result);

	// Measure time for secure hash
	start = clock();
	for (int i = 0; i < ITERATIONS; i++) {
		secure_hash(password, secure_hash_result);
	}
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken for secure hash (%d iterations): %f seconds\n", ITERATIONS, cpu_time_used);
	printf("Secure hash result: %s\n", secure_hash_result);

	return 0;
}
