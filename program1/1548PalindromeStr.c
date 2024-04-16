#include "stdio.h"
#include "string.h"

int isPalind(char *str) {
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < len / 2; i++, j--) {
        if (str[i] != str[j])
            return 0;
    }
    return 1;
}

int countPalind(char *str) {
    int len = strlen(str);
    int count = 0;
    char temp[1005];

    for (int i = 0; i <= len; ++i) {
        strcpy(temp, str);
        memmove(temp + 1 + i, temp + i, len - i + 1);
        temp[i] = temp[len - i];
        if (isPalind(temp))
            count++;
    }
    return count;
}

int main() {
    char str[1005];
    while (scanf("%s", str) != EOF) {
        printf("%d\n", countPalind(str));
    }
}