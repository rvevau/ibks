#include <stdio.h>

unsigned int dec_bin(unsigned int num) {
    
    if(num == 0){
        printf("0");
        return 0;
    }
    
   unsigned int bin[32];
   unsigned int i = 0;
   while (num > 0) {
      bin[i] = num % 2;
      num = num / 2;
      i++;
   }
    
   for (long long int j = i - 1; j >= 0; j--) {
      printf("%d", bin[j]);
   }
    
    return 0;
}

int main() {
    
   unsigned int dec;
   scanf("%d", &dec);
    
   dec_bin(dec);
    
   return 0;
}
