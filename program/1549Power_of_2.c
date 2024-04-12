#include "stdio.h"

//int isPower_of_2(long long int a) {
//    if (a & (a - 1))
//        return 0;
//    return 1;
//}

int search(long long int *s, long long int left, long long int right, long long int a) {
    while (left <= right) {
        long long int mid = left + ((right - left) / 2);
        if (s[mid] < a) {
            left = mid + 1;
        } else if (s[mid] > a) {
            right = mid - 1;
        } else {
            return 1;
        }
    }
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long int n;
        long long int s[100005];
        scanf("%I64d", &n);
        for (long long int i = 0; i < n; ++i) {
            scanf("%I64d", &s[i]);
        }
        long long int count = 0;
//        for (long long int i = 0; i < n - 1; ++i) {
//            for (long long int j = i + 1; j < n; ++j) {
//                if (isPower_of_2(s[i] + s[j]))
//                    count++;
//            }
//        }
        long long int power2[31] = {0};
        long long int temp = 2;
        for (int i = 1; i < 31; ++i) {
            power2[i] = temp;
            temp *= 2;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < 31; ++j) {
                if (s[i] * 2 < power2[j]) {
                    if (search(s, i+1, n - 1, power2[j] - s[i]))
                        count++;
                }
            }
        }
        printf("%I64d\n", count);
    }
}