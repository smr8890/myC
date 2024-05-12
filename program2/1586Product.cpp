#include "iostream"
#include "algorithm"

using namespace std;

const int mod = 1000000007;

long long int maxProduct(long long int *nums, int n, int k) {
    sort(nums, nums + n);

    int left = 0, right = n - 1;
    long long int product = 1;
    long long int flag = 1;

    if (k % 2) {
        product = nums[right];
        right--;
        k--;
        if (product < 0) {
            flag = -1;
        }
    }

    while (k) {
        long long int lp = nums[left] * nums[left + 1];
        long long int rp = nums[right] * nums[right - 1];

        if (lp * flag > rp * flag) {
            product = lp % mod * product % mod;
            left += 2;
        } else {
            product = rp % mod * product % mod;
            right -= 2;
        }
        k -= 2;
    }
    return product;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        long long int nums[10005];
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%I64d", &nums[i]);
        }
        printf("%I64d\n", maxProduct(nums, n, k));
    }
    return 0;
}