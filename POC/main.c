#include"lib/lwe.h"

int main(int argc, char **argv){
	/*
	// the first argument is the dimension
	int n = argv[1] - '0';
	// the second argument is m
	int m = argv[2] - '0';
	// the third argument is the modulus p
	int p = argv[3] - '0';
	*/

	int n = 10;
	int m = 10;
	unsigned long int p=17;
	keyPair key = keyInit(n, m);
	keyGen(n, m, p, &key);
	printf("secret:\n[");
	
	//gsl_vector_ulong_fprintf(stdout, key.secretKey, "%d,");
	for (size_t i = 0; i < key.secretKey->size - 1; i++){
		printf("%lu, ", gsl_vector_ulong_get(key.secretKey, i));
	}

	printf("%lu]\n", gsl_vector_ulong_get(key.secretKey, key.secretKey->size -1));

	printf("public:\n");
	for (size_t i = 0; i < key.publicKey->size1; i++){
		printf("[");
		for (size_t j = 0; j < key.publicKey->size2; j++){
			printf("%2lu ", gsl_matrix_ulong_get(key.publicKey, i, j));
		}
		printf("]\n");
	}
	//printf("%lu]\n", gsl_matrix_ulong_get(key.publicKey, n, m));

	freeKey(&key);
	return 0;
}
