#include "stdio.h"

void sort(int *arr, int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//迭代返回下一个n
int iterate(int n) {
    int arr[4];
    for (int i = 0; i < 4; ++i) {
        arr[i] = n % 10;
        n /= 10;
    }
    sort(arr, 4);
    int a = 0, b = 0;
    for (int i = 0; i < 4; ++i) {
        a = a * 10 + arr[i];
    }
    for (int i = 3; i >= 0; i--) {
        b = b * 10 + arr[i];
    }
    a += b;
    for (int i = 0; i < 4; ++i) {
        arr[i] = a % 10;
        a /= 10;
    }
    n = 0;
    for (int i = 3; i >= 0; --i) {
        n = n * 10 + arr[i];
    }
    return n;
}
//判断数码是否相等
int isSame(int n) {
    int arr[4];
    for (int i = 0; i < 4; ++i) {
        arr[i] = n % 10;
        n /= 10;
    }
    if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3])
        return 1;
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int count = 0;
        while (!isSame(n)) {
            n = iterate(n);
            count++;
        }
        printf("%d\n", count);
    }
    return 0;
}