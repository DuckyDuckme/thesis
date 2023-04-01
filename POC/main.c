#include"lib/lwe.h"

int main(){
	size_t n = 4;
	size_t m = 4;
	size_t p=17;
	keyPair key = keyInit(n, m);
	keyGen(n, m, p, &key);
	printKey(&key);

	freeKey(&key);
	return 0;
}
