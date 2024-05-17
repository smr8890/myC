#include "iostream"
#include "queue"
#include "vector"

using namespace std;

struct TreeNode {
    int data;
    int left, right;
    TreeNode *lchild;
    TreeNode *rchild;

    TreeNode(int x, int y, int z) : data(x), left(y), right(z), lchild(NULL), rchild(NULL) {}
};

TreeNode *createTree(TreeNode *T) {
    int val, left, right;
    queue<TreeNode *> q;

    scanf("%d %d %d", &val, &left, &right);
    T = new TreeNode(val, left, right);
    q.push(T);

    TreeNode *p = NULL;
    while (!q.empty()) {
        p = q.front();
        q.pop();
        if (p->left != 0) {
            scanf("%d %d %d", &val, &left, &right);
            p->lchild = new TreeNode(val, left, right);
            q.push(p->lchild);
        }
        if (p->right != 0) {
            scanf("%d %d %d", &val, &left, &right);
            p->rchild = new TreeNode(val, left, right);
            q.push(p->rchild);
        }
    }
    return T;
}

TreeNode *merge(TreeNode *T1, TreeNode *T2) {
    if (T1 == NULL)return T2;
    if (T2 == NULL)return T1;

    queue<TreeNode *> q;
    q.push(T1);
    q.push(T2);

    while (!q.empty()) {
        TreeNode *p1 = q.front();
        q.pop();
        TreeNode *p2 = q.front();
        q.pop();
        p1->data += p2->data;
        if (p1->lchild != NULL && p2->lchild != NULL) {
            q.push(p1->lchild);
            q.push(p2->lchild);
        } else if (p1->lchild == NULL) {
            p1->lchild = p2->lchild;
        }
        if (p1->rchild != NULL && p2->rchild != NULL) {
            q.push(p1->rchild);
            q.push(p2->rchild);
        } else if (p1->rchild == NULL) {
            p1->rchild = p2->rchild;
        }
    }
    return T1;
}

void preOrderTraversal(TreeNode *root, queue<int> &q) {
    if (root == NULL) {
        return;
    }
    q.push(root->data);
//    printf("%d ", root->data);
    preOrderTraversal(root->lchild, q);
    preOrderTraversal(root->rchild, q);
}

void inOrderTraversal(TreeNode *root, queue<int> &q) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->lchild, q);
    q.push(root->data);
//    printf("%d ", root->data);
    inOrderTraversal(root->rchild, q);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n1, n2;
        scanf("%d", &n1);
        TreeNode *T1 = NULL;
        T1 = createTree(T1);
        scanf("%d", &n2);
        TreeNode *T2 = NULL;
        T2 = createTree(T2);

        T1 = merge(T1, T2);
        queue<int> queue1, queue2;
        preOrderTraversal(T1, queue1);
        while (!queue1.empty()) {
            int x = queue1.front();
            queue1.pop();
            if (!queue1.empty()) {
                printf("%d ", x);
            } else {
                printf("%d", x);
            }
        }
        printf("\n");

        inOrderTraversal(T1, queue2);
        while (!queue2.empty()) {
            int x = queue2.front();
            queue2.pop();
            if (!queue2.empty()) {
                printf("%d ", x);
            } else {
                printf("%d", x);
            }
        }
        printf("\n");
    }
    return 0;
}