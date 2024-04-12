#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 自定义搜索函数，用于在数组a中查找是否存在一个元素，使得a[middle] + a[x] = y
int sousuo(long long *a, int qwe, long long y, int n) {
    int zuo = qwe;
    int you = n - 1;
    while (zuo <= you) {
        int zhongjian = zuo + ((you - zuo) / 2);
        if (a[zhongjian] + a[qwe] > y) {
            you = zhongjian - 1;
        } else if (a[zhongjian] + a[qwe] < y) {
            zuo = zhongjian + 1;
        } else { return 1; }
    }
    return -1;
}

int main() {
    int T, i;
    long long ans[32] = {0};// 定义数组ans，用于存储2的幂次
    scanf("%d", &T);
    ans[0] = 1;
    for (i = 1; i <= 30; i++) ans[i] = 2 * ans[i - 1];
    while (T--) {
        int n;
        scanf("%d", &n);
        long long *a = (long long *) malloc(sizeof(long long) * n);// 动态分配内存以存储集合S的元素
        int j;
        long long flag = 0;
        for (i = 0; i < n; i++) scanf("%I64d", &a[i]);
        for (i = 0; i < n; i++) {
            for (j = 1; j <= 30; j++) {
                if (ans[j] <= 2 * a[i]) continue;
                else {
                    if (sousuo(a, i, ans[j], n) == 1)
                        flag++;
                }
            }
        }
        printf("%I64d\n", flag);
        free(a);// 释放动态分配的内存
        a = NULL;// 将指针设置为NULL，避免悬挂指针
    }
    return 0;
}