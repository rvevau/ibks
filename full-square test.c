#include <stdio.h>
#include <math.h>
#include <string.h>

unsigned long long isqrt_ull(unsigned long long x) {

    if (x < 2) {
        return x;
    }
    
    unsigned long long s = isqrt_ull(x >> 2) << 1;
    unsigned long long t = s + 1;
    return (t > x / t) ? s : t;
}

int main() {

    unsigned short int n, count = 0;
    unsigned long long int mass[20], tmp;
    char input[500];

    fgets(input, sizeof(input), stdin);
    sscanf(input, "%hu", &n);
    fgets(input, sizeof(input), stdin);

    char* token = strtok(input, " ");

    for (unsigned int i = 0; i < n; i++) {
        sscanf(token, "%llu", &mass[i]);
        token = strtok(NULL, " ");
    }

    tmp = 0;

    for (unsigned int i = 0; i < n; i++) {
        if (isqrt_ull(mass[i]) * isqrt_ull(mass[i]) == mass[i] && mass[i] >= tmp) {
            tmp = mass[i];
            count++;
        }
    }
    if (count == 0) {
        printf("-1");
    }
    else {
        for (unsigned int i = 0; i < n; i++) {
            if (mass[i] == tmp) {
                printf("%d", i);
                break;
            }
        }
    }
    return 0;
}
