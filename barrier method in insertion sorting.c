#include <stdio.h>

int main(void) {
  int mass[11] = {0, 12, -1, 0, 33, 24, 10, 47, 3, -243, 55};
  // mass[0] is empty
  for(int i = 2; i < 11; i++){
    int j = i;
    int k = mass[i];
    mass[0] = k;
    while(mass[j - 1] > k){
      mass[j] = mass[j - 1];
      j--;
    }
    mass[j] = k;
  }
  for(int i = 1; i <11; i++) printf("%d ", mass[i]); // mass[0] skipped
  return 0;
}