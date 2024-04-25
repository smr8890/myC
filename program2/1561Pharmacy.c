#include "stdio.h"
#include "math.h"

long long int search(long long int *a, long long int *b, long long int n, long long int m) {
    long long int x_left = 0, x_right = 0;
    for (long long int i = 0; i < n; ++i) {
        long long int t = (long long int) ceil((double) m * (double) b[i] / (double) a[i]);
        if (t > x_right) {
            x_right = t;
        }
    }
    while (x_left <= x_right) {
        long long int mid = x_left + ((x_right - x_left) / 2);
        long long int sum = 0;
        for (long long int i = 0; i < n; ++i) {
            sum += (long long int) ceil((double) mid * (double) a[i] / (double) b[i]);
        }
        if (sum < m) {
            x_left = mid + 1;
        } else if (sum > m) {
            x_right = mid - 1;
        } else {
            return mid;
        }
    }
    return x_right;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long int n, m;
        scanf("%I64d %I64d", &n, &m);
        long long int a[1005], b[1005];
        for (long long int i = 0; i < n; ++i) {
            scanf("%I64d", &a[i]);
        }
        for (long long int i = 0; i < n; ++i) {
            scanf("%I64d", &b[i]);
        }
        printf("%I64d\n", search(a, b, n, m));
    }
    return 0;
}