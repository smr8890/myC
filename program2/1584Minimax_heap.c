#include "stdio.h"
#include "stdlib.h"

int cmp_int(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int result(int *a, int n) {
//    while (n-- > 1) {
//        qsort(a, n + 1, sizeof(a[0]), cmp_int);
//        a[n - 1] = a[n] - a[n - 1];
//    }
    int t = n;
    while (t-- > 1) {
        int max1 = 1, max2 = 0;
        if (a[0] > a[1])
            max1 = 0, max2 = 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] > a[max1]) {
                max1 = i;
            } else if (a[i] > a[max2] && a[i] < a[max1]) {
                max2 = i;
            }
        }
        a[max1] -= a[max2];
        for (int i = max2; i < n - 1; ++i) {
            a[i] = a[i + 1];
        }
        n--;
    }
    if (a[0] == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int a[10005];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        if (result(a, n)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}