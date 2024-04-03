#include <stdio.h>

int main(void) {
  int mass[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  int x, l = 0, r = 9;
  scanf("%d", &x);
  while(l <= r){
    int med = (r + l) / 2; //median is a barrier
    if(x == mass[med]){
      printf("%d", med);
      return 0;
    }
    else if (x > mass[med]) l = med;
    else r = med;
  }
  return 0;
}