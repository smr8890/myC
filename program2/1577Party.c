#include "stdio.h"
#include "stdlib.h"

int cmp_int(const void *_a, const void *_b) {
    int *a = (int *) _a, *b = (int *) _b;
    return *a - *b;
}

//void mysort(int *a, int n) {
//    for (int i = 0; i < n - 1; ++i) {
//        for (int j = 0; j < n - i - 1; ++j) {
//            if (a[j] > a[j + 1]) {
//                int t = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = t;
//            }
//        }
//    }
//}

int result(int *a, int n) {
    qsort(a, n, sizeof(a[0]), cmp_int);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (count + 1 >= a[i]) {
            count++;
        } else {
            break;
        }
    }
    return count;
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
        printf("%d\n", result(a, n));
    }
    return 0;
}