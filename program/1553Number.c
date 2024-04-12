#include "stdio.h"

int isReasonable(long long int n) {
    long long int sum = 0, temp = n;
    while (temp) {
        sum += temp % 10;
        temp /= 10;
    }
    if (n % sum == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long int n;
        scanf("%I64d", &n);
        for (long long int i = n; i > 0; i--) {
            if (isReasonable(i)) {
                printf("%I64d\n", i);
                break;
            }

        }
    }
}