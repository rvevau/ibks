#include <stdio.h>

FILE* input;
FILE* output;

int r = 0;
int chess[24][24];
unsigned short int l, n;

int check_valid_move(int a, int b) {
    for (int i = 0; i < n; ++i) {
        if (chess[a][i] || chess[i][b]){
            return 0;
        }
    }

    for (int i = 1; i < n; ++i) {
        if ((a + i < n && b + i < n && chess[a + i][b + i]) ||
            (a + i < n && b - i >= 0 && chess[a + i][b - i]) ||
            (a - i >= 0 && b + i < n && chess[a - i][b + i]) ||
            (a - i >= 0 && b - i >= 0 && chess[a - i][b - i])){
            return 0;
        }
    }
    return 1;
}

void print_chessboard() {
    unsigned short int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (chess[i][j]) fprintf(output, "(%d,%d) ", i, j);
        }
    }
    fprintf(output, "\n");
    r = 1;
}


void recursive_queen(unsigned short int a, unsigned int counter) {
    unsigned short int b = 0, i;

    for (b = 0; b < n; ++b) {
        if (check_valid_move(a, b)) {
              chess[a][b] = 1;
            for (i = a + 1; i < n; ++i) {
                recursive_queen(i, counter + 1);
            }
            if (counter + 1 == l)
                print_chessboard();
              chess[a][b] = 0;
        }
    }
}


int main() {
    short int x, y, k;
    unsigned short int i = 0, j = 0;

    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    fscanf(input, "%hu %hu %hi", &n, &l, &k);
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++) {
              chess[i][j] = 0;
        }
    }

    while (k > 0) {
        fscanf(input, "%hi %hi", &x, &y);
          chess[x][y] = 1;
        k--;
    }

    for (i = 0; i < n; ++i){
        recursive_queen(i, 0);
    }

    if (r == 0){
        fprintf(output, "no solutions");
    }

  return 0;
}
