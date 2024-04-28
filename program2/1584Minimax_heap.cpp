#include <cstdio>
#include "queue"

int result(std::priority_queue<int> a, int n) {
    while (n-- > 1) {
        int max1 = a.top();
        a.pop();
        int max2 = a.top();
        a.pop();
        a.push(max1 - max2);
    }
    if (a.top() == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        std::priority_queue<int> a;
        for (int i = 0; i < n; ++i) {
            int t;
            scanf("%d", &t);
            a.push(t);
        }
        if (result(a, n)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}