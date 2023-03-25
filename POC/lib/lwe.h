#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<gsl/gsl_rng.h>
#include<gsl/gsl_vector.h>
#include<gsl/gsl_matrix.h>

typedef struct keyPair{
	gsl_vector_ulong *secretKey;
	gsl_matrix_ulong *publicKey;
} keyPair;

keyPair keyInit(int n, int m);
void keyGen(int n, int m, unsigned long int q, keyPair *key);
void freeKey(keyPair *key);
int encrypt();
int decrypt();
