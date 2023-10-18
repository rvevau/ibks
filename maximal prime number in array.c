#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

long long int is_prime(long long int x) {

	unsigned short int checker = 0;

	for (long long int i = 2; i < (x / 2) + 1; i++) {
	
		if (x % i == 0) {

			checker++;
			break;

			
		}

	}

	return checker;
}


int main() {

	unsigned short int n;
	long long int array[20][20], prime_array[20][20], maximal_prime = 0, max = -1;

	scanf("%hu", &n);

	for (unsigned short int i = 0; i < n; i++) {

		for (unsigned short int j = 0; j < n; j++) {

			prime_array[i][j] = 0;

		}

	}

	for (unsigned short int i = 0; i < n; i++) {

		for (unsigned short int j = 0; j < n; j++) {

			scanf("%lli", &array[i][j]);

		}

	}


	for (unsigned short int i = 0; i < n; i++) {

		for (unsigned short int j = 0; j < n; j++) {

			if (is_prime(array[i][j]) == 0) {
			
				prime_array[i][j] = array[i][j];

			}

		}

	}

	for (unsigned short int i = 0; i < n; i++) {

		for (unsigned short int j = 0; j < n; j++) {

			if (prime_array[i][j] > max) {

				max = prime_array[i][j];

			}

		}

	}

	printf("%lli", max);
	
	return 0;
}