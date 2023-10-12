#include <stdio.h>

int main() {

	int i = 1, ii = 0;
	char c = 1, cc = 0;
	short int h = 1, hh = 0;
	long int l = 1, ll1 = 0; 
	long long int ll = 1, ll2 = 0;

	for (i = 1; i != 0; i *= 2) {
		ii++;
	}

	printf("int = %i\n", ii/8);

	for (c = 1; c != 0; c *= 2) {
		cc++;
	}

	printf("char = %i\n", cc / 8);
	
	for (h = 1; h != 0; h *= 2) {
		hh++;
	}

	printf("short int = %i\n", hh / 8);

	for (l = 1; l != 0; l *= 2) {
		ll1++;
	}

	printf("long int = %i\n", ll1 / 8);

	for (ll = 1; ll != 0; ll *= 2) {
		ll2++;
	}

	printf("long long int = %i\n", ll2 / 8);
	
	return 0;
}