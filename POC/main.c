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

	int n = 4;
	int m = 4;
	unsigned long int p=17;
	keyPair key = keyInit(n, m);
	keyGen(n, m, p, &key);
	printKey(&key);

	freeKey(&key);
	return 0;
}
