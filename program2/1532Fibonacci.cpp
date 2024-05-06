#include "stdio.h"

int init(long long int x, long long int *fibonacci, long long int *S) {
    fibonacci[0] = 1;
    fibonacci[1] = 2;
    S[0] = 1;
    S[1] = 3;
    int len = 2;
    for (int i = 2; S[i - 1] < x; ++i) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        S[i] = S[i - 1] + fibonacci[i];
        len++;
    }
    return len;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long int x;
        scanf("%I64d", &x);
        long long int fibonacci[1000], S[1000], flag[1000] = {0};
        int len = init(x, fibonacci, S);
        for (int i = 0; i < len && x > 0;) {
            if (x <= S[i]) {
                flag[i] = 1;
                x -= fibonacci[i];
                i = 0;
                continue;
            } else
                i++;
        }
        long long int sum = 0, t = 1;
        for (int i = 0; i < len; ++i) {
            sum += flag[i] * t;
            t *= 2;
        }
        printf("%I64d\n", sum);
    }
    return 0;
}