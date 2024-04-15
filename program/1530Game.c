#include "stdio.h"
#include "string.h"

int main() {
    char str[30];
    int n = 1, begin_flag = 0, people_flag = 0;
    int a_score = 0, b_score = 0;//比分
    while (gets(str) != NULL) {
        char *token;
        int number, sum = 0;
        token = strtok(str, " ");
        if (strlen(token) == 2) {
            number = (token[0] - '0') * 10 + token[1] - '0';
        } else {
            number = token[0] - '0';
        }
        token = strtok(NULL, " ");
        while (token != NULL) {
            if (token[0] == 'P')
                sum += 5;
            token = strtok(NULL, " ");
        }
        //游戏开始判断
        if (begin_flag == 0) {
            if (people_flag == 0) {
                printf("Alice start game %d\n", n);
            } else {
                printf("Bob start game %d\n", n);
            }
            begin_flag = 1;
        }

        if (sum == number) {
            if (people_flag == 0) {
                printf("Alice win game %d\n", n);
                a_score++;
            } else {
                printf("Bob win game %d\n", n);
                b_score++;
            }
            n++;
            begin_flag = 0;
        } else {
            if (people_flag == 0) {
                printf("Change to Bob\n");
                people_flag = 1;
            } else {
                printf("Change to Alice\n");
                people_flag = 0;
            }
        }
    }
    printf("Game over %d:%d\n", a_score, b_score);
    return 0;
}