#include <iostream>
#include <string>
using namespace std;

int solve(string s) {
    int n = s.length();
    int res = 0;
    int prev = -1; // ǰһ��ѵ������Ŀ
    int cnt = 0;   // ��ǰ����ѵ��ͬһ��Ŀ������

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cnt = 0; // ������������
        } else {
            int curr = s[i] - '1'; // ��ǰѵ������Ŀ
            if (curr != prev) {
                res++;
                prev = curr;
                cnt = 1;
            } else {
                cnt++;
                if (cnt > 2) {
                    cnt = 2; // ������������ѵ��ͬһ��Ŀ��ֻ����ǰ����
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