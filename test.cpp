#include <iostream>
#include <vector>
using namespace std;

// 定义最大节点数
const int MAX_N = 10005;

// 邻接表存储树形结构
vector<int> adj[MAX_N];

// 存储每个节点的初始值
int val[MAX_N];

// 标记每个节点是否被访问过
bool visited[MAX_N];

// DFS函数,计算以u为根节点的子树中,需要执行的最小操作次数,使得子树中所有节点的值都等于targetVal
// parent参数用于避免重复访问父节点
int dfs(int u, int parent, int targetVal) {
    int count = 0;
    // 如果当前节点值不等于目标值,需要执行一次操作
    if (val[u] != targetVal) {
        count++;
    }
    // 标记当前节点已访问
    visited[u] = true;
    // 遍历当前节点的所有邻接节点
    for (int v : adj[u]) {
        // 如果邻接节点不是父节点,且未被访问过
        if (v != parent && !visited[v]) {
            // 递归处理邻接节点,目标值为当前节点值异或目标值
            count += dfs(v, u, targetVal ^ val[u]);
        }
    }
    return count;
}

// 求解整棵树的最小操作次数
int solve(int n) {
    int minOps = n;
    // 枚举每个节点作为根节点
    for (int i = 1; i <= n; i++) {
        // 如果当前节点未被访问过
        if (!visited[i]) {
            // 计算以当前节点为根节点时,使所有节点值变为0或1的最小操作次数
            minOps = min(minOps, min(dfs(i, -1, 0), dfs(i, -1, 1)));
        }
    }
    return minOps;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        // 清空邻接表和访问标记
        for (int i = 0; i < MAX_N; i++) {
            adj[i].clear();
            visited[i] = false;
        }
        // 输入树形结构
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // 输入每个节点的初始值
        for (int i = 1; i <= n; i++) {
            cin >> val[i];
        }
        // 输出最小操作次数
        cout << solve(n) << endl;
    }
    return 0;
}