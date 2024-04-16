#include "stdio.h"
#include "string.h"


int main() {
    long long int T;
    scanf("%I64d", &T);
    long long int a, b, m, s, i;
    while (T--) {
        scanf("%I64d %I64d %I64d", &a, &b, &m);
        int flag[100005] = {0};
        s = 0;
        for (i = 1; i < 100000; ++i) {
            s = (a * s + b) % m;
            if (s != 0) {
                flag[s] = 1;
            } else {
                break;
            }
        }

        for (i = 1; i < 100000; ++i) {
            if (flag[i] == 0) {
                printf("%lld\n", i);
                break;
            }
        }
    }
}