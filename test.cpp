#include <iostream>
#include <vector>

using namespace std;

bool isCompleteAndBST(vector<int>& tree) {
    int n = tree.size();
    if (n == 0) return true;  // 空树视为完全二叉排序树

    int i = 1;
    for (int val : tree) {
        if ((i > 1) && (val < tree[(i-1)/2])) return false;  // 当前节点小于父节点
        if (i > n) return false;  // 节点索引超过数组大小,不是完全二叉树

        if (2*i <= n && val > tree[2*i-1]) return false;  // 当前节点大于左子节点
        if (2*i+1 <= n && val < tree[2*i]) return false;  // 当前节点小于右子节点

        i++;
    }

    return true;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> tree(n);
        for (int i = 0; i < n; i++) {
            cin >> tree[i];
        }

        if (isCompleteAndBST(tree)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}