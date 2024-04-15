#include<stdio.h>
#include<string.h>
int main() {
    char chuan[30];
    int n, amy, tom, john, count;
    n = amy = tom = john = 0;
    count = 1;
    while (scanf("%[^\n]", chuan) != EOF) {
        getchar();
        int sum, num;
        sum = num = 0;
        char* p = strtok(chuan, " ");
        if (strlen(p) == 2) {
            num = (p[0] - '0') * 10 + p[1] - '0';
        } else {
            num = p[0] - '0';
        }
        while (p = strtok(NULL, " ")) {
            if (p[0] == 'P') {
                sum += 5;
            }
        }
        if (n == 0) {
            if (john == 0) {
                printf("Alice start game %d\n", count);
                n++;
            } else {
                printf("Bob start game %d\n", count);
                n++;
            }
        }
        if (sum != num) {
            if (john == 0) {
                printf("Change to Bob\n");
                n++;
                john = 1;
            } else {
                printf("Change to Alice\n");
                n++;
                john = 0;
            }
        } else if (sum == num) {
            if (john == 0) {
                printf("Alice win game %d\n", count);
                n = 0;
                count++;
                amy++;
            } else {
                printf("Bob win game %d\n", count);
                count++;
                n = 0;
                tom++;
            }
        }
    }
    printf("Game over %d:%d\n", amy, tom);
    return 0;
}