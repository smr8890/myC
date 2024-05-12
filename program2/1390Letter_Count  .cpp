#include "iostream"

void dfs(int s, int e, long long int *c, char *str) {
    long long int c1[27] = {0}, c2[27] = {0};
    int j;
    if (str[s] == '(') {
        int flag = 1, i;
        for (i = s + 1; flag != 0; ++i) {
            if (str[i] == '(') {
                flag++;
            } else if (str[i] == ')') {
                flag--;
            }
        }
        i--;

        dfs(s + 1, i - 1, c1, str);

        long long int num = 0;//提取")"后的系数
        for (j = i + 1; j <= e; ++j) {
            if (str[j] >= '0' && str[j] <= '9') {
                num += str[j] - '0';
                num *= 10;
            } else
                break;
        }
        j--;
        num /= 10;

        for (int k = 0; k < 26; ++k) {
            c1[k] *= num;
        }

    } else {
        for (j = s + 1; j <= e; ++j) {
            if (!(str[j] >= '0' && str[j] <= '9')) {
                break;
            }
        }
        j--;

        long long int num = 0;
        if (j == s) {
            num = 1;
        } else {
            for (int i = s + 1; i <= j; ++i) {
                num += str[i] - '0';
                num *= 10;
            }
            num /= 10;
        }
        c1[str[s] - 'a'] += num;
    }

    if (j + 1 <= e) {
        dfs(j + 1, e, c2, str);
    }

    for (int i = 0; i < 26; ++i) {
        c[i] = c1[i] + c2[i];
    }
}

void count(char *str) {
    long long int c[27] = {0};
    int e = 0;
    while (str[e] != '\0') {
        e++;
    }
    dfs(0, e - 1, c, str);
    for (int i = 0; i < 26; ++i) {
        if (c[i] != 0) {
            printf("%c : %I64d\n", i + 'a', c[i]);
        }
    }
    printf("\n");
}

int main() {
    char str[55];
    while (scanf("%s", str) != EOF) {
        count(str);
    }
    return 0;
}