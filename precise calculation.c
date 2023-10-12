/*
  --           i      3i + 1
  \        (-1)  *  x
  /      ------------------- * sin(i * PI/4)
  --       (2i+1) * (2i-1)
*/ 

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>
#include <float.h>

#define EPSILON 0.0001
#define REAL long double

double calculateSum(REAL x, double epsilon) {

    REAL sum = 0, term;

    for (unsigned long long int i = 1; i <= INFINITY; i++) {

        term = ((pow(-1, i) * pow(x, 3 * i + 1)) / ((2 * i + 1) * (2 * i - 1))) * sin(i * M_PI_4);

        if (fabs(term) < epsilon) {

            break;

        }

        sum += term;

        printf("i = %d: %.16f\n", i, term);
    }

    return sum;
}

int main() {

    SetConsoleOutputCP(1253);

    REAL x = 1;
    REAL sum1 = calculateSum(x, EPSILON);
    REAL sum2 = calculateSum(x, DBL_EPSILON);

    printf("\xD3 (\xE5) = %.4f\n", sum1);
    printf("\xD3 (max \xC4) = %.15f\n", sum2);

    return 0;

}