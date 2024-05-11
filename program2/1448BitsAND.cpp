#include "iostream"
#include "bitset"

using namespace std;

void bitsToChar(bitset<32> bits, char *str) {
    for (int i = 0, j = 31; i < 32; ++i, --j) {
        str[i] = bits[j] ? '1' : '0';
    }
    str[32] = '\0';
}

int maxlen(int n, int k, char str[10005][33]) {
    int max = 0;
    for (int i = 0; i < 32; ++i) {
        int left = 0, right = 0;
        int count_max = 0, count0 = 0;

        while (right < n) {
            if (str[right][i] == '0') {
                count0++;
            }
            while (count0 > k) {
                if (str[left][i] == '0') {
                    count0--;
                }
                left++;
            }
            if (count_max < right - left + 1) {
                count_max = right - left + 1;
            }
            right++;
        }
        if (max < count_max) {
            max = count_max;
        }
    }
    return max;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int a[10005];
        char str[10005][33];//32位二进制

        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            bitset<32> bits(a[i]);
            bitsToChar(bits, str[i]);
        }

        printf("%d\n", maxlen(n, k, str));
    }
    return 0;
}