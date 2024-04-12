#include<stdio.h>
#include<string.h>

char zfc[1000];
int main() {
    while (scanf("%s", zfc) != EOF) {
        int shumu = strlen(zfc),flag = 0;
        for (int j = 0; j < shumu + 1; j++) {
            int biaozhi = 0;// 标记是否能够形成回文串
            for (int k1 = shumu; k1 >= j + 1; k1--) { // 将字符串中j位置后的字符后移一位
                zfc[k1] = zfc[k1 - 1];
            }
            zfc[j] = zfc[shumu - j];// 在位置j插入字符，字符取自字符串的对称位置
            int t = 0;
            for (t = 0; t < (shumu + 1) / 2; t++) { // 比较插入字符后的字符串的前半部分和后半部分是否相等
                if (zfc[t] != zfc[shumu - t]) biaozhi = 1; // 如果字符不相等，则不能形成回文串
            }
            if (biaozhi == 0)flag++;
            for (int k2 = j; k2 < shumu; k2++) {
                zfc[k2] = zfc[k2 + 1];
            }
            zfc[shumu] = '0';
        }
        printf("%d\n", flag);
        memset(zfc, '0', sizeof(zfc)); // 将整个字符串重置为'0'，清除之前的尝试结果
    }
    return 0;
}