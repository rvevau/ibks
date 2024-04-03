#include <stdio.h>

size_t strlen(char* s){
  size_t len=0;
  while (*s++) len++;
  return len;
}

char* strcpy(char* s1, char* s2){
  char* t = s1;
  while((*s1++ = *s2++));
  return t;
}

char* strncpy(char* s1, char* s2, int n){
char* t = s1;
  int k = 0;
  while(k != n && (*s1++ = *s2++)) k ++;
  return t;
}

char* strcat(char* s1, char* s2){
  char*t = s1;
  while(*s1) s1++;
  while((*s1++ = *s2++));
  return t;
}

char* strncat(char* s1, char* s2, int n){
  char* t = s1;
  int k = 0;
  while(*s1) s1++;
  while(k != n && (*s1++ = *s2++)) k++;
  return t;
}

char* strchr(char* s, char* c){
  char* t = s;
  while (*s != c && *s){
    t++;
    s++;
  }
  if (*s == 0) return 0;
  return t;
}

char* strrchr(char* s, char* c){
  char* t = s;
  while (*s++){
    if (*s == c) t = s;
  }
  if (*s == 0) return 0;
  return t;
}

int* strcmp(char* s1, char* s2){
  while (*s1 == *s2 && *s1 && *s2){
    s1++;
    s2++;
  }
  if(*s1 == 0 && *s2 == 0) return 0;
  else if (*s1 > *s2) return 1;
  else if (*s1 < *s2) return -1;
}

int* strncmp(char* s1, char* s2, int n){
  int k = 0;
  while(k != n && *s1 == *s2 && *s1 && *s2){
    s1++;
    s2++;
    k++;
  }
  if (*s1 > *s2) return 1;
  else if (*s1 < *s2) return -1;
  return 0;
}


int main(void) {
  printf("this program contains implementation of string functions");
  return 0;
}