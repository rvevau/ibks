#include <stdio.h>

#define BUFSIZE 2048
#define CODE                        0
#define STAR_IN_MULTI_COMMENT       1
#define SLASH_IN_LINE_COMMENT       2
#define BEGIN_COMMENT               3
#define STRING                      4
#define MULTI_COMMENT               5
#define LINE_COMMENT                6
#define SLASH_IN_STRING             7
#define LITERAL                     8
#define SLASH_IN_LITERAL            9

void processFile(FILE *filei, FILE *fileo);

int main() {
    char filenamei[] = "test.c";
    char filenameo[] = "test.wc";

    FILE *filei, *fileo;

    if ((filei = fopen(filenamei, "r")) == NULL
    || (fileo = fopen(filenameo, "w")) == NULL) {
        return 0;
    }

    processFile(filei, fileo);

    fclose(filei);
    fclose(fileo);

    return 0;
}

void processFile(FILE *filei, FILE *fileo) {
    int i, size, pOutStr, state;
    char buffer[BUFSIZE], result[BUFSIZE];

    state = CODE;
    do {
        pOutStr = 0;
        size = fread(buffer, 1, BUFSIZE, filei);

        for(i = 0; i < size; i++) {
            switch (state) {
                case CODE:
                    if (buffer[i] == '\"') {
                        state = STRING;
                        result[pOutStr++] = buffer[i];
                    } else if (buffer[i] == '/') {
                        state = BEGIN_COMMENT;
                    } else if (buffer[i] == '\'') {
                        state = LITERAL;
                        result[pOutStr++] = buffer[i];
                    } else {
                        result[pOutStr++] = buffer[i];
                    }
                    break;

                case STAR_IN_MULTI_COMMENT:
                    if (buffer[i] == '/') {
                        state = CODE;
                    } else if (buffer[i] != '*') {
                        state = MULTI_COMMENT;
                    }
                    break;

                case SLASH_IN_LINE_COMMENT:
                    state = LINE_COMMENT;
                    break;

                case BEGIN_COMMENT:
                    if (buffer[i] == '*') {
                        state = MULTI_COMMENT;
                    } else if (buffer[i] == '/') {
                        state = LINE_COMMENT;
                    } else {
                        result[pOutStr++] = '/';
                        --i;
                        state = CODE;
                    }
                    break;

                case STRING:
                    if (buffer[i] == '"') {
                        state = CODE;
                    } else if (buffer[i] == '\\') {
                        state = SLASH_IN_STRING;
                    } else if (buffer[i] == '\n') {
                        state = CODE;
                    }
                    result[pOutStr++] = buffer[i];
                    break;

                case LITERAL:
                    if (buffer[i] == '\'') {
                        state = CODE;
                    } else if (buffer[i] == '\\') {
                        state = SLASH_IN_LITERAL;
                    } else if (buffer[i] == '\n') {
                        state = CODE;
                    }
                    result[pOutStr++] = buffer[i];
                    break;

                case MULTI_COMMENT:
                    if (buffer[i] == '*') {
                        state = STAR_IN_MULTI_COMMENT;
                    }
                    break;

                case LINE_COMMENT:
                    if (buffer[i] == '\\') {
                        state = SLASH_IN_LINE_COMMENT;
                    } else if (buffer[i] == '\n') {
                        state = CODE;
                        result[pOutStr++] = buffer[i];
                    }
                    break;

                case SLASH_IN_STRING:
                    state = STRING;
                    result[pOutStr++] = buffer[i];
                    break;

                case SLASH_IN_LITERAL:
                    state = (buffer[i] != '\n') ? LITERAL : CODE;
                    result[pOutStr++] = buffer[i];
                    break;

                default:
                    break;
            }
        }

        if (pOutStr) {
            fwrite(result, 1, pOutStr, fileo);
        }

    } while(!feof(filei));
}
