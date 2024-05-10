#include "iostream"
#include "vector"

using namespace std;

void XOR(vector<int> *adj, int node, int parent, int *val) {
    val[node] ^= 1;
    for (int next: adj[node]) {
        if (next != parent) {
            XOR(adj, next, node, val);
        }
    }
}

int dfs(vector<int> *adj, int node, int parent, int *val, int target) {
    int ops = 0;
    if (val[node] != target) {
        XOR(adj, node, parent, val);
        ops++;
    }
    for (int next: adj[node]) {
        if (next != parent) {
            ops += dfs(adj, next, node, val, target);
        }
    }
    return ops;
}

int minOperation(int n, vector<int> *adj, int *val) {
    int val0[10005], val1[10005];
    copy(val, val + n + 1, val0);
    copy(val, val + n + 1, val1);
    int ops0 = dfs(adj, 1, 0, val0, 0);
    int ops1 = dfs(adj, 1, 0, val1, 1);
    return min(ops0, ops1);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);

        vector<int> adj[10005];//邻接表
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int val[10005] = {0};//节点值
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &val[i]);
        }

        printf("%d\n", minOperation(n, adj, val));
    }
    return 0;
}