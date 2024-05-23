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

int find_parent(int *parent, int x) {
    if (parent[x] == x) {
        return parent[x];
    }
    return parent[x] = find_parent(parent, parent[x]); //路径压缩
}

int result(node *a, int n, int m) {
    int parent[1005];
    for (int i = 0; i <= 1004; i++) {
        parent[i] = i;
    }
    sort(a, a + m, cmp);
    int sum = 0, count = 0;
    for (int i = 0; i < m; i++) {
        int t1 = find_parent(parent, a[i].u);
        int t2 = find_parent(parent, a[i].v);
        if (t1 != t2) {
            sum += a[i].w;
            parent[t2] = t1;
            count++;
            if (count == n - 1) {
                break;
            }
        }
    }
    int sum1=0;
    for (int i=0;i<m;i++) {
        sum1+=a[i].w;
    }
    return sum1-sum;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        node a[1005];
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a[i].u, &a[i].v, a[i].w);
        }
        int x=result(a,n,m);
        printf("%d\n",x);
    }
    return 0;
}
