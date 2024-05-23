#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int u;
    int v;
    int w;
};

bool cmp(node a, node b) {
    return a.w > b.w;
}

int find_parent(int x, int *parent) {
    if (parent[x] == x) {
        return parent[x];
    }
    return parent[x] = find_parent(parent[x], parent);
}

int result(int n, int m, node *a) {
    int parent[2005];
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    sort(a, a + m, cmp);
    int sum = 0, count = 0;
    for (int i = 0; i < m; i++) {
        int t1 = find_parent(a[i].u, parent);
        int t2 = find_parent(a[i].v, parent);
        if (t1 != t2) {
            sum += a[i].w;
            count++;
            parent[t2] = t1;
            if (count == n - 1) {
                break;
            }
        }
    }
    int sum0 = 0;
    for (int i = 0; i < m; i++) {
        sum0 += a[i].w;
    }
    return sum0 - sum;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        node a[20005];
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a[i].u, &a[i].v, &a[i].w);
        }
        printf("%d\n", result(n, m, a));
    }
    return 0;
}
