#include <stdio.h>  // 用于输入/输出操作
#include <algorithm>  // 用于memset函数
#include <string.h>  // 用于字符串操作函数,如memset
typedef __int64 ll;  // 定义一个新的数据类型'll'用于64位整数
using namespace std;

char str[100];  // 声明一个字符数组,用于存储输入的字符串
ll c3[30];  // 声明一个数组,用于存储每个字符的最终计数

// 递归函数,用于计算字符的计数
void dfs(int s, int e, ll c[]) {
    ll c1[30], c2[30];  // 数组,用于存储子字符串中字符的计数
    memset(c1, 0, sizeof(c1));  // 用0初始化c1数组
    memset(c2, 0, sizeof(c2));  // 用0初始化c2数组
    int i, j, t, o, l = 1, r = 0;
    ll sum = 0;

    // 如果当前子字符串以'('开头
    if (str[s] == '(') {
        l = 1;
        r = 0;
        // 查找相应的闭括号
        for (i = s + 1; i <= e; i++) {
            if (str[i] == '(') l++;
            if (str[i] == ')') {
                r++;
                if (r == l) break;
            }
        }
        dfs(s + 1, i - 1, c1);  // 递归调用,处理括号内的子字符串

        // 提取闭括号后的数字系数
        for (t = i + 1; t <= e; t++) {
            if (str[t] >= '0' && str[t] <= '9') {
                sum += str[t] - 48;
                sum = sum * 10;
            } else
                break;
        }
        j = t - 1;
        sum = sum / 10;
        for (o = 0; o <= 26; o++) {
            c1[o] *= sum;  // 将计数乘以数字系数
        }
    } else {
        // 如果当前子字符串不以'('开头
        for (i = s + 1; i <= e; i++) {
            if (str[i] >= '0' && str[i] <= '9') continue;
            else break;
        }
        j = i - 1;
        if (i == s + 1) sum = 1;  // 如果没有数字系数,将sum设为1
        else {
            sum = 0;
            for (o = s + 1; o <= j; o++) {
                sum += str[o] - 48;
                sum = sum * 10;
            }
            sum = sum / 10;
        }
        c1[str[s] - 'a'] += sum;  // 增加当前字符的计数
    }

    if (j + 1 <= e) dfs(j + 1, e, c2);  // 递归调用,处理剩余的子字符串

    // 将c1和c2中的计数合并到c
    for (o = 0; o <= 26; o++) {
        c[o] = c1[o] + c2[o];
    }

    // 将最终的计数存储到c3中
    for (o = 0; o <= 26; o++) {
        c3[o] = c[o];
    }
}

int main() {
    ll i, j, cnt;
    memset(str, 0, sizeof(str));  // 用0初始化输入字符串数组
    memset(c3, 0, sizeof(c3));  // 用0初始化c3数组

    while (scanf("%s", str) != EOF) {  // 读取输入字符串,直到EOF
        cnt = 0;
        for (i = 0; str[i] != '\0'; i++) {
            cnt++;  // 统计输入字符串的长度
        }
        dfs(0, cnt - 1, c3);  // 调用递归函数计算计数

        // 打印非零字符的计数
        for (i = 0; i <= 26; i++) {
            if (c3[i] != 0) {
                char ch = i + 97;
                printf("%c : %I64d\n", ch, c3[i]);
            }
        }
        printf("\n");  // 在每个输入字符串后打印一个新行

        memset(str, 0, sizeof(str));  // 重置输入字符串数组
        memset(c3, 0, sizeof(c3));  // 重置c3数组
    }

    return 0;
}