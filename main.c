#include "stdio.h"
#include "stdlib.h"

int cmp_int(const void *a, const void *b) {
    return *(int *) b -*(int *) a;
}

int result(int *a, int n) {
//    while (n-- > 1) {
//        qsort(a, n + 1, sizeof(a[0]), cmp_int);
//        a[n - 1] = a[n] - a[n - 1];
//    }
    int t = n;
    qsort(a,n, sizeof(a[0]),cmp_int);
    for (int i = n-2; i >=0; --i) {
        a[i]-=a[i+1];
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