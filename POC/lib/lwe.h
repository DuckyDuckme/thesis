#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<gsl/gsl_rng.h>
#include<gsl/gsl_vector.h>
#include<gsl/gsl_matrix.h>
#include<math.h>
#include<gsl/gsl_blas.h>
#include<gsl/gsl_randist.h>
#include<time.h>

// i define my own here because compiler keeps complaining M_PI is undefined even with linking against math library
#define PI 3.14159265358979323846

typedef struct keyPair{
	gsl_vector_ulong *secretKey;
	gsl_matrix_ulong *A;
	gsl_vector_ulong *b;
} keyPair;

typedef unsigned long int ulong;

keyPair keyInit(int n, int m);
void keyGen(int n, int m, unsigned long int q, keyPair *key);
void freeKey(keyPair *key);
//int encrypt();
//int decrypt();
void multiply(const gsl_matrix_ulong* A, const gsl_vector_ulong* x, gsl_vector_ulong* y);
void printKey(keyPair *key);
