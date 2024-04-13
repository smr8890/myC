#include "stdio.h"
#include "string.h"

int make_New_Number(long long int n) {
    int nstr[11];
    int len = 0, len1 = 0, len2 = 0;
    for (int i = 0; i < 10 && n; ++i) {
        nstr[i] = n % 10;
        n /= 10;
        len++;
    }
    int mstr1[5], mstr2[5];
    for (int i = len - 1, j = 0; i >= 0; i -= 2, j++) {
        mstr1[j] = nstr[i];
        len1++;
    }
    for (int i = len - 2, j = 0; i >= 0; i -= 2, j++) {
        mstr2[j] = nstr[i];
        len2++;
    }
    int m1 = 0, m2 = 0;
    for (int i = 0; i < len1; ++i) {
        m1 = m1 * 10 + mstr1[i];
    }
    for (int i = 0; i < len2; ++i) {
        m2 = m2 * 10 + mstr2[i];
    }
    return m1 * m2;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long int n;
        scanf("%I64d", &n);
        int count = 0;
        while (n / 10) {
            count++;
            n = make_New_Number(n);
        }
        printf("%d\n", count);
    }
    return 0;
}