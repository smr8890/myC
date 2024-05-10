#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010, mod = 1000000009;

int a[N];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);

    sort(a, a + n);

    int l  = 0, r = n - 1;                                     // 双指针初始化
    int ans = 1;                                               // 乘积初始化
    int sign  = 1;                                             // 符号初始化

    if(k % 2)                                                  // k 为奇数
    {
        ans = a[r];                                            // 取出最大的数
        r --;                                                  // r指针 左移
        k --;                                                  // k 变为偶数

        if(ans < 0) sign = -1;                                 // 最大值为负数，则所有数都是负数，结果也为负，所以要让绝对值小
    }

    while(k)
    {
        LL x = (LL)a[l] * a[l + 1], y =(LL)a[r] * a[r - 1];    // 左右两边同时取一对乘积，比较大小
        if(x * sign > y * sign)
        {
            ans = x % mod * ans % mod;
            l += 2;                                            // l指针 右移
        }
        else
        {
            ans = y % mod * ans % mod;
            r -= 2;                                            // r指针 左移
        }
        k -= 2;                                                // 个数减二
    }

    cout << ans << endl;
    return 0;
}
