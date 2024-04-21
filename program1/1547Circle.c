#include "stdio.h"

int divisor(int a, int b) {
    int temp;
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    while (b > 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void find_min(int r, int h) {
    int a = 2 * (r + h);
    int b = r;
    printf("%d/%d\n", b / divisor(a, b), a / divisor(a, b));
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int r, h;
        scanf("%d %d", &r, &h);
        find_min(r, h);
    }
    return 0;
}