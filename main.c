#include "stdio.h"

int main() {
    int n;
    scanf("%d", &n);
    int sequence[100005];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &sequence[i]);
    }
    int min = 0;
    for (int i = 0; i < n; ++i) {
        min += sequence[i];
        int flag = 1, sum = 0;
        for (int j = i + 1; j < n; ++j) {
            sum += sequence[j];
            if (sum == min) {
                flag = 1;
                sum = 0;
            } else {
                flag = 0;
            }
        }
        if (flag) {
            printf("%d\n", min);
            break;
        }
    }
    return 0;
}