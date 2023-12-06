#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

long long int prime_check(long long int x) {
  unsigned short int checker = 0, i = 0;
  
  for (i = 2; i < (x / 2) + 1; i++) {
    if (x % i == 0) {
      checker++;
      break;
    }
  }

  return checker;
}

void array(int mass[50][50], int n, int* x, int* y) {
  unsigned long int mx_i = 1, mx_j = 1, mx = 0;
  
  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int j = 0; j < n; j++) {
      if (prime_check(mass[i][j]) && mass[i][j] > mx) {
        mx = mass[i][j];
        mx_i = i;
        mx_j = j;
      }
    }
  }
  *x = mx_i;
  *y = mx_j;
}


int main() {
  long long int n, mass[50][50], mx_i, mx_j;
  scanf("%lli", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%lli", &mass[i][j]);
    }
  }
  
  array(mass, n, &mx_i, &mx_j);
  printf("%lli %lli", mx_i, mx_j);
  return 0;
}
