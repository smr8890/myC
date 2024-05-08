#include "stdio.h"

int insertTree(long long int *tree, long long int data, int n) {
    int i = 1;
    if (tree[1] == 0) {
        tree[1] = data;
        return 1;
    } else {
        while (tree[i] != 0) {
            if (data < tree[i]) {
                i = i * 2;
            } else {
                i = i * 2 + 1;
            }
            if (i > n) {
                return 0;
            }
        }
        tree[i] = data;
        return 1;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        long long int arr[105], tree[105] = {0};
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%I64d", &arr[i]);
        }
        int flag = 1;
        for (int i = 0; i < n; ++i) {
            if (insertTree(tree, arr[i], n) == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}