#include<stdio.h>

int main() {
    long long int tom, rrr, m, k;
    scanf("%I64d", &k);
    while (k--) {
        int STR[100001] = {0};
        scanf("%I64d%I64d%I64d", &tom, &rrr, &m);
        long long int s = 0;
        STR[0] = 1;
        while (1) {// 无限循环，直到找到一个重复的值，即序列进入循环
            s = (tom * s + rrr) % m;
            if (STR[s] == 1) {// 如果计算出的下一个值已经在序列中，则跳出循环
                break;
            }
            STR[s] = 1;// 否则，将这个值标记为已存在
        }
        for (long long int i = 0; i <= m; i++) {// 遍历数组STR，找到第一个值为0的索引，这个索引就是不在序列中的最小正整数
            if (STR[i] == 0) {// 如果当前索引i对应的值为0，说明i不在序列中
                printf("%I64d\n", i);
                break;
            }
        }
    }
    return 0;
}