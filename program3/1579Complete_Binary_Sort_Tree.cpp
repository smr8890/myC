#include "iostream"
#include "queue"

using namespace std;

struct TreeNode {
    int data;
    int flag;
    TreeNode *lchild;
    TreeNode *rchild;

    TreeNode(int x, int y) : data(x), flag(y), lchild(NULL), rchild(NULL) {}
};

TreeNode *insert(TreeNode *T, int x, int y, int &max) {
    if (T == NULL) {
        T = new TreeNode(x, y);
        if (T->flag > max) {
            max = T->flag;
        }
    } else {
        if (x < T->data) {
            T->lchild = insert(T->lchild, x, 2 * y, max);
        } else if (x > T->data) {
            T->rchild = insert(T->rchild, x, 2 * y + 1, max);
        }
    }
    return T;
}

void freeTree(TreeNode *T) {
    if (T == NULL)return;
    freeTree(T->lchild);
    freeTree(T->rchild);
    delete T;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        TreeNode *tree = NULL;
        int max = 1;

        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            tree = insert(tree, x, 1, max);
        }
        printf("%d\n", max - n);
        freeTree(tree);
    }
    return 0;
}