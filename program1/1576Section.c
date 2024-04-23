#include "stdio.h"

int cacu_sum(int *sequence, int len) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += sequence[i];
    }
    return sum;
}

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

int find_factor(int n, int *factor) {
    int j = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            factor[j] = i;
            j++;
            if (i != n / i) {
                factor[j] = n / i;
                j++;
            }
        }
    }
    sort(factor, j);
    return j;
}

int main() {
    int n;
    scanf("%d", &n);
    int sequence[100005];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &sequence[i]);
    }
    int sum = cacu_sum(sequence, n);
//    printf("%d\n",sum);
    int factor[10000];
    int len = find_factor(sum, factor);
//    for (int i = 0; i < len; ++i) {
//        printf("%d ", factor[i]);
//    }
    for (int i = 0; i < len; ++i) {
        int flag = 1, section_sum = 0;
        for (int j = 0; j < n; ++j) {
            section_sum += sequence[j];
            if (section_sum == factor[i]) {
                flag = 1;
                section_sum = 0;
            } else if (section_sum > factor[i]) {
                flag = 0;
                break;
            } else {
                flag = 0;
            }
        }
        if (flag) {
            printf("%d\n", factor[i]);
            break;
        }
    }
    return 0;
}