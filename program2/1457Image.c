#include "stdio.h"
#include "math.h"

int find_n(long long int k) {
    for (long long int i = 0; i <= 60; ++i) {
        long long int t = pow(2, 2 * i);
        if (t >= k)
            return i;
    }
    return -1;
}

void find_xy(long long int k, long long int n) {
    long long int x = 1, y = 1;
    while (n != 0) {
        long long int i;
        long long int t0 = pow(2, 2 * (n - 1));
        for (i = 1; i <= 4; ++i) {
            if (i * t0 >= k) {
                break;
            }
        }
        k -= (i - 1) * t0;
        long long int t = pow(2, n - 1);
        if (i == 2) {
            y += t;
        } else if (i == 3) {
            x += t;
        } else if (i == 4) {
            x += t;
            y += t;
        }
        n--;
    }
    printf("%I64d %I64d\n", x, y);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long int k;
        scanf("%I64d", &k);
        long long int n = find_n(k);
        find_xy(k, n);
    }
    return 0;
}



