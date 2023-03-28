#include"lwe.h"

keyPair keyInit(int n, int m){
	keyPair key;

	key.secretKey = gsl_vector_ulong_alloc(n);
	key.A = gsl_matrix_ulong_alloc(n, m);
	key.b = gsl_vector_ulong_alloc(m);

	return key;
}


void keyGen(int n, int m, ulong q, keyPair *key){
	// setup the gsl rng
	gsl_rng_env_setup();
	gsl_rng *r;
	r = gsl_rng_alloc(gsl_rng_default);
	gsl_rng_set(r, time(NULL));

    for (int i = 0; i < n; i++) {
		// this is our secret key, just uniformly random elements modulo q
		gsl_vector_ulong_set(key->secretKey, i, gsl_rng_uniform_int(r, q));
            for (int j = 0; j < m; j++){
				gsl_matrix_ulong_set(key->A, i, j, gsl_rng_uniform_int(r, q));
		}
    }

	// this is a working variable
	gsl_vector_ulong *b = gsl_vector_ulong_alloc(m);
	// here we obtain b by multiplying A with the secret key
	multiply(key->A, key->secretKey, b);

	// some other working variables
	double alpha = 1.0 / (sqrt(n) * log2(log2(n)));
	double e = 0.0;
	int error = 0;
	ulong b_i = 0;

	for (int i = 0; i < m; i++) {
		// this is our error reduced modulo 1
		e = fmod(gsl_ran_gaussian(r, alpha / sqrt(2 * PI)), 1.0);
		// we now discretize e, i.e. multiply by q, round to the nearest integer and reduce mod q
		error = (ulong) lround(e * q) % q;
		b_i = gsl_vector_ulong_get(b, i);
		// finally, store the result in the b vector of public key matrix
		gsl_vector_ulong_set(key->b, i, (b_i + error) % q);
	}

	// we don't need stuff anymore, free it
	gsl_rng_free(r);
	gsl_vector_ulong_free(b);

    return;
}

void freeKey(keyPair* key) {
	gsl_vector_ulong_free(key->secretKey);
	gsl_matrix_ulong_free(key->A);
	gsl_vector_ulong_free(key->b);
	return;
}

void multiply(const gsl_matrix_ulong* A, const gsl_vector_ulong* x, gsl_vector_ulong* y)
{
    size_t m = A->size1;
    size_t n = A->size2;

    for (size_t i = 0; i < m; i++) {
        ulong sum = 0;
        for (size_t j = 0; j < n; j++) {
            sum += gsl_matrix_ulong_get(A, i, j) * gsl_vector_ulong_get(x, j);
        }
        gsl_vector_ulong_set(y, i, sum);
    }
}

void printKey(keyPair *key){
	printf("secret:\n[");

	for (size_t i = 0; i < key->secretKey->size - 1; i++){
			printf("%3lu, ", gsl_vector_ulong_get(key->secretKey, i));
	}

	printf("%lu]\n", gsl_vector_ulong_get(key->secretKey, key->secretKey->size - 1));

	printf("public:\n");
	printf("A:\n");
	for (size_t i = 0; i < key->A->size1; i++){
			printf("[");
			for (size_t j = 0; j < key->A->size2; j++){
					printf("%3lu ", gsl_matrix_ulong_get(key->A, i, j));
			}
			printf("]\n");
	}

	printf("b:\n[");
	for (size_t i = 0; i < key->secretKey->size - 1; i++){
			printf("%3lu, ", gsl_vector_ulong_get(key->b, i));
	}
	printf("%lu]\n", gsl_vector_ulong_get(key->b, key->b->size - 1));
	return;
}

/*
// message is only 1 bit
gsl_vector_ulong *encrypt(short int message, keyPair *key){
	gsl_rng_env_setup();
	gsl_rng r = gsl_rng_alloc(gsl_rng_default);
	gsl_rng_set(time(NULL));
	 
	gsl_ran_choose(r, );

	// this is our output its the size of
	gsl_vector_ulong *encryption = gsl_vector_calloc(key->b->size);
	gsl_vector_ulong *a_i = gsl_vector_alloc(key->b->size);

	// sum the m columns
	for (int i = 0; i < m; i++){
		a_i = gsl_matrix_const_column(key->A, i);
		gsl_vector_ulong_add(encryption, a_i);
	}

	gsl_vector_ulong_


    return encryption;
}

int decrypt(key *keyPair, gsl_vector_ulong* encryption){
    return 0;
}
*/
