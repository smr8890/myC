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

void preOrderTraversal(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%d", root->data);
    if (root->lchild != NULL || root->rchild != NULL) {
        printf(" ");
    }
    preOrderTraversal(root->lchild);
    if (root->lchild != NULL && root->rchild != NULL) {
        printf(" ");
    }
    preOrderTraversal(root->rchild);
}

void inOrderTraversal(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->lchild);
    if (root->lchild != NULL) {
        printf(" ");
    }
    printf("%d", root->data);
    if (root->rchild != NULL) {
        printf(" ");
    }
    inOrderTraversal(root->rchild);
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
        preOrderTraversal(T1);
        printf("\n");
        inOrderTraversal(T1);
        printf("\n");
    }
    return 0;
}