#include "stdio.h"

int find_min(int *a, int len) {
    int min = a[0];
    for (int i = 0; i < len; ++i) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

int result(int *a, int w, int n, int d) {
    if (w - 1 <= d) {
        return -1;
    }
    int remove[100005], remove_flag = 0;
    for (int i = 0; i <= n; ++i) {
        int d0 = a[i] - 1;
        if (d0 > d) {
            remove[remove_flag] = i;
            remove_flag++;
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int d0 = a[j] - a[i];
            if (d0 > d) {
                remove[remove_flag] = j - i - 1;
                remove_flag++;
                break;
            }
        }
    }
    return find_min(remove, remove_flag);
}

int main() {
    int w, n, d;
    int a[100005];
    scanf("%d %d %d", &w, &n, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    a[n] = w;
    printf("%d\n", result(a, w, n, d));
    return 0;
}