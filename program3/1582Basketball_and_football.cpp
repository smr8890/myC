#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int my_max(int a, int b, int c) {
    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    return max;
}

int result(char *str) {
    int pre[10005][5];
    pre[0][0] = pre[0][1] = pre[0][2] = pre[0][3] = pre[0][4] = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        //(i,0)
        pre[i + 1][0] = *max_element(pre[i], pre[i] + 5);
        //(i,1)
        if (str[i] == '1' || str[i] == '3') {
            pre[i + 1][1] = my_max(pre[i][0], pre[i][3], pre[i][4]) + 1;
        } else {
            pre[i + 1][1] = 0;
        }
        //(i,2)
        if (str[i] == '1' || str[i] == '3') {
            pre[i + 1][2] = pre[i][1] + 1;
        } else {
            pre[i + 1][2] = 0;
        }
        //(i,3)
        if (str[i] == '2' || str[i] == '3') {
            pre[i + 1][3] = my_max(pre[i][0], pre[i][1], pre[i][2]) + 1;
        } else {
            pre[i + 1][3] = 0;
        }
        //(i,4)
        if (str[i] == '2' || str[i] == '3') {
            pre[i + 1][4] = pre[i][3] + 1;
        } else {
            pre[i + 1][4] = 0;
        }
    }
    return *max_element(pre[len], pre[len] + 5);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char str[10005];
        scanf("%s", str);
        printf("%d\n", result(str));
    }
    return 0;
}
