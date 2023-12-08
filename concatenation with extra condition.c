#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

char alph[27] ="qwertyuiopasdfghjklzxcvbnm";
char cons[21] = "qwrtpsdfghjklmnbvcxz";
char vow[7] = "eauioy";

char* concat(char* word_1, char* word_2, char* res) {

    char concat_res[40];
    int len_1 = strlen(word_1);
    int len_2 = strlen(word_2);
    int min_len = len_1;

    if (len_2 < min_len) {
        min_len = len_2;
    }
    int max_len = abs(len_2 - len_1);
    for (int i = 0; i < min_len; i++) {
        concat_res[2 * i] = word_1[i];
        concat_res[(2 * i) + 1] = word_2[i];
    }

    if (len_1 > len_2) {
        int i = 2 * min_len;
        int k = i;
        int j = 0;
        for (i; i < (max_len + k); i++) {
            concat_res[i] = word_1[min_len + j];
            j++;
        }
        concat_res[max_len + k] = '\0';
    }
    if (len_1 < len_2) {
        int i = 2 * min_len;
        int k = i;
        int len_answer = strlen(concat_res);
        int j = 0;
        for (i; i < (max_len + k); i++) {
            concat_res[i] = word_2[min_len + j];
            j++;
        }
        concat_res[max_len + k] = '\0';
    }
    else {
        concat_res[min_len * 2] = '\0';

    }
    if (strchr(cons, concat_res[min_len * 2 - 1]) != NULL) {

        int len_answer = strlen(concat_res);
        int j = 0;
        for (int i = 0; i < strlen(concat_res); i++) {
            if (i == strlen(concat_res) - 1) {
                res[j] = concat_res[i];
            }
            else {


                if (concat_res[i] == concat_res[i + 1] && strchr(cons, concat_res[i]) != NULL) {
                    res[j] = concat_res[i];
                    res[j + 1] = concat_res[i + 1];

                    i++;
                    j += 2;
                }
                if ((concat_res[i] != concat_res[i + 1] && strchr(vow, concat_res[i]) != NULL && strchr(vow, concat_res[i + 1]) != NULL)) {
                    i += 1;
                }
                else if ((concat_res[i] == concat_res[i + 1] && strchr(vow, concat_res[i]) != NULL && strchr(vow, concat_res[i + 1]) != NULL)) {

                    res[j] = concat_res[i];
                    res[j + 1] = concat_res[i + 1];
                    i += 1;
                    j += 2;
                }
                else {
                    res[j] = concat_res[i];
                    j++;
                }
            }
        }
        res[j + 1] = '\0';


        return res;
    }
    else {

        int len_answer = strlen(concat_res);
        int j = 0;
        for (int i = 0; i < strlen(concat_res); i++) {
            if (i == strlen(concat_res) - 1) {
                res[j] = concat_res[i];
            }
            else {


                if (concat_res[i] == concat_res[i + 1] && strchr(cons, concat_res[i]) != NULL) {
                    res[j] = concat_res[i];
                    res[j + 1] = concat_res[i + 1];

                    i++;
                    j += 2;
                }
                if ((concat_res[i] != concat_res[i + 1] && strchr(vow, concat_res[i]) != NULL && strchr(vow, concat_res[i + 1]) != NULL)) {
                    i += 1;
                }
                else if ((concat_res[i] == concat_res[i + 1] && strchr(vow, concat_res[i]) != NULL && strchr(vow, concat_res[i + 1]) != NULL)) {

                    res[j] = concat_res[i];
                    res[j + 1] = concat_res[i + 1];
                    i += 1;
                    j += 2;
                }
                else {
                    res[j] = concat_res[i];
                    j++;
                }
            }
        }
        res[j] = '\0';
return res;
    }

    int len_answer = strlen(concat_res);
    int j = 0;
    for (int i = 0; i < strlen(concat_res); i++) {
        if (i == strlen(concat_res) - 1) {
            res[j] = concat_res[i];
        }
        else {


            if (concat_res[i] == concat_res[i + 1] && strchr(cons, concat_res[i]) != NULL) {
                res[j] = concat_res[i];
                res[j + 1] = concat_res[i + 1];

                i++;
                j += 2;
            }
            if ((concat_res[i] != concat_res[i + 1] && strchr(vow, concat_res[i]) != NULL && strchr(vow, concat_res[i + 1]) != NULL)) {
                i += 1;
            }
            else if ((concat_res[i] == concat_res[i + 1] && strchr(vow, concat_res[i]) != NULL && strchr(vow, concat_res[i + 1]) != NULL)) {

                res[j] = concat_res[i];
                res[j + 1] = concat_res[i + 1];
                i += 1;
                j += 2;
            }
            else {
                res[j] = concat_res[i];
                j++;
            }
        }
    }
    res[j + 1] = '\0';


    return res;
}

int main() {
  
    char word1[40];
    char word2[40];
    char res[100];
  
    for (;;) {

        scanf("%s %s", word1, word2);
        printf("%s", concat(word1, word2, res));
    }


}
