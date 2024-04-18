#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
int pre[1003][26];

int main() {//



    int T;///



    cin >> T;



    string s;
    while (T--) {
        int K, ssssss = 1000, max, qweqwe, num, b;////
        memset(pre, 0, sizeof(pre));
        cin >> K;
        cin >> s;
        int len = s.length();
        for (int i = 1; i <= len; i++) {
            pre[i][s[i - 1] - 'a']++;
            for (int j = 0; j < 26; j++) {
                pre[i + 1][j] = pre[i][j];
            }
        }
        qweqwe = 0;
        for (int fgh = 0; fgh < 26; fgh++) if (pre[len][fgh] > qweqwe) qweqwe = pre[len][fgh];
        if (qweqwe <= K) {
            cout << 0 << endl;
            continue;
        }

        for (int i = 1; i <= len; i++) {
            for (int j = i; j <= len; j++) {
                max = 0;
                for (int k = 0; k < 26; k++) {
                    num = pre[len][k] - pre[j][k] + pre[i - 1][k];
                    if (num > max) max = num;
                }
                if (max <= K) {
                    if (ssssss > j - i + 1) {
                        ssssss = j - i + 1;
                    }
                    break;
                }
            }
        }
        cout << ssssss << endl;
    }
}