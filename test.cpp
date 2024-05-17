#include "iostream"
#include "queue"

using namespace std;

struct TreeNode {
    int data;
    int left, right;
    TreeNode *lchild;
    TreeNode *rchild;
};

TreeNode *createTree(TreeNode *T) {
    int val, left, right;
    queue<TreeNode *> q;

    scanf("%d %d %d", &val, &left, &right);
    T = new TreeNode;
    T->data=val;
    T->left=left;
    T->right=right;
    q.push(T);

    TreeNode *p = nullptr;
    while (!q.empty()) {
        p = q.front();
        q.pop();
        if (p->left != 0) {
            scanf("%d %d %d", &val, &left, &right);
            p->lchild = new TreeNode;
            p->lchild->data=val;
            p->lchild->left=left;
            p->lchild->right=right;
            q.push(p->lchild);
        }
        if (p->right != 0) {
            scanf("%d %d %d", &val, &left, &right);
            p->rchild = new TreeNode;
            p->rchild->data=val;
            p->rchild->left=left;
            p->rchild->right=right;
            q.push(p->rchild);
        }
    }
    return T;
}

void merge(TreeNode *T1, TreeNode *T2) {
    if (T2 == nullptr) {
        return;
    }
    if (T1 == nullptr) {
        T1 = new TreeNode;
        T1->data=T2->data;
        T1->left=0;
        T1->right=0;
    } else {
        T1->data += T2->data;
    }
    merge(T1->lchild, T2->lchild);
    merge(T1->rchild, T2->rchild);
}

void preOrderTraversal(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    printf("%d ", root->data);
    preOrderTraversal(root->lchild);
    preOrderTraversal(root->rchild);
}

void inOrderTraversal(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->lchild);
    printf("%d ", root->data);
    inOrderTraversal(root->rchild);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n1, n2;
        scanf("%d", &n1);
        TreeNode *T1 = nullptr;
        T1 = createTree(T1);
        scanf("%d", &n2);
        TreeNode *T2 = nullptr;
        T2 = createTree(T2);
        merge(T1, T2);
        preOrderTraversal(T1);
        printf("\n");
        inOrderTraversal(T1);
    }
    return 0;
}