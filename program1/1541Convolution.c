#include "stdio.h"

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int a[260][260] = {0}, b[5][5] = {0}, a_out[260][260] = {0};
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= 3; ++j) {
                scanf("%d", &b[i][j]);
            }
        }
        //卷积
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                a_out[i][j] = a[i - 1][j - 1] * b[1][1] + a[i - 1][j] * b[1][2] + a[i - 1][j + 1] * b[1][3] +
                              a[i][j - 1] * b[2][1] + a[i][j] * b[2][2] + a[i][j + 1] * b[2][3] +
                              a[i + 1][j - 1] * b[3][1] + a[i + 1][j] * b[3][2] + a[i + 1][j + 1] * b[3][3];
                if (a_out[i][j] < 0) {
                    a_out[i][j] = 0;
                } else if (a_out[i][j] > 255) {
                    a_out[i][j] = 255;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < m; ++j) {
                printf("%d ", a_out[i][j]);
            }
            printf("%d\n", a_out[i][m]);
        }
        printf("\n");
    }
    return 0;
}