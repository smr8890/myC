#include "iostream"
#include "queue"

using namespace std;

int minOperation(int x, int y) {
    queue<int> que;
    int dist[100005] = {0};
    que.push(x);
    dist[x] = 0;

    while (!que.empty()) {
        int num = que.front();
        que.pop();

        if (num == y)return dist[num];

        int nextNumbers[4] = {num * 2, num + 1, num / 2, num - 1};
        for (int next: nextNumbers) {
            if (next >= 1 && next <= 100000 && dist[next] == 0) {
                que.push(next);
                dist[next] = dist[num] + 1;
            }
        }
    }
    return -1;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", minOperation(x, y));
    }
    return 0;
}