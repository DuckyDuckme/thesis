#include"lwe.h"

keyPair keyInit(int n, int m){
	keyPair key;

	key.secretKey = gsl_vector_ulong_alloc(n);// * sizeof(unsigned long int));
	key.publicKey = gsl_matrix_ulong_alloc(n, m);// * sizeof(unsigned long int));

	return key;
}


void keyGen(int n, int m, unsigned long int q, keyPair *key){
	// setup the gsl rng
	const gsl_rng_type *T;
	gsl_rng *r;
	gsl_rng_env_setup();
	T = gsl_rng_default;	

	r = gsl_rng_alloc(T);

    for (int i = 0; i < n; i++) {
		gsl_vector_ulong_set(key->secretKey, i, gsl_rng_uniform_int(r, q));
            for (int j = 0; j < m; j++){
            gsl_matrix_ulong_set(key->publicKey, i, j, gsl_rng_uniform_int(r, q));
		}
    }
	// we don't need the rng anymore, free it
	gsl_rng_free(r);

    return;
}

void freeKey(keyPair* key) {
	gsl_vector_ulong_free(key->secretKey);
	gsl_matrix_ulong_free(key->publicKey);
	return;
}

int encrypt(){

    return 0;
}

int decrypt(){
    return 0;
}

