#include <iostream>
#include <string>
using namespace std;

int solve(string s) {
    int n = s.length();
    int res = 0;
    int prev = -1; // 前一天训练的项目
    int cnt = 0;   // 当前连续训练同一项目的天数

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cnt = 0; // 重置连续天数
        } else {
            int curr = s[i] - '1'; // 当前训练的项目
            if (curr != prev) {
                res++;
                prev = curr;
                cnt = 1;
            } else {
                cnt++;
                if (cnt > 2) {
                    cnt = 2; // 连续三天以上训练同一项目，只计算前两天
                }
                res++;
            }
        }
    }

    return res;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}