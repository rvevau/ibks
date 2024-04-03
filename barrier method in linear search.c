#include <stdio.h>

int main(void) {
  int mass_1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  int mass_2[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

  int x, i = 0, j = 0;
  scanf("%d", &x);
  
  //normal search
  while(i < 10 && mass_1[i] != x) i++;
  if (i == 10) return 0;
  else printf("%d\n", i);

  //linear search with barrier
  mass_2[10] = x;
  while(mass_2[j] != x) j++;
  if(j == 10) return 0;
  else printf("%d", j);
}