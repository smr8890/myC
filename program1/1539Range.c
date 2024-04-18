#include "stdio.h"
#include "string.h"

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int k;
        char str[1005];
        scanf("%d", &k);
        scanf("%s", str);
        int len = strlen(str);
        int pre[1005][27] = {0};
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j <= i; ++j) {
                pre[i][str[j] - 'a']++;
            }
        }
        int max0 = 0;
        for (int i = 0; i < 26; ++i) {
            if (pre[len - 1][i] > max0)
                max0 = pre[len - 1][i];
        }
        if (max0 <= k) {
            printf("0\n");
            continue;
        }
        int flag = 0;
        //区间[l,r],l=i,r=i+len_range-1,len=len_range+1
        for (int len_range = 1; len_range <= len; ++len_range) {
            for (int i = 0; i + len_range - 1 < len; ++i) {
                int max = 0;
                for (int j = 0; j < 26; ++j) {
                    int num;
                    if (i == 0) {
                        num = pre[len - 1][j] - pre[i + len_range - 1][j] + 0;
                    } else {
                        num = pre[len - 1][j] - pre[i + len_range - 1][j] + pre[i - 1][j];
                    }
                    if (num > max) {
                        max = num;
                    }
                }
                if (max <= k) {
                    printf("%d\n", len_range);
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                break;
            }
        }
    }
    return 0;
}