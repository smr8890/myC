#include "stdio.h"
#include "string.h"
#include "math.h"

long long int dfs(char *str, int s, int e) {
    long long int result = 0;
    int flag = 1, p = 0;
    for (int i = s + 1; i < e; ++i) {
        if (str[i] == '(') {
            flag++;
        } else if (str[i] == ')') {
            flag--;
        }
        if (flag == 0) {
            p = i + 1;
            break;
        }
    }
    if (p < e) {
        result = dfs(str, p, e);
    }
    if (p - 1 - s == 2) {
        result += str[s + 1] - '0';
    } else {
        long long int a = dfs(str, s + 1, p - 1);
        result += a * a;
    }
    return result;
}

int main() {
    char str[105];
    while (scanf("%s", str) != EOF) {
        int len = strlen(str);
        long long int result = dfs(str, 0, len);
        printf("%I64d\n", result * result);
    }
    return 0;
}