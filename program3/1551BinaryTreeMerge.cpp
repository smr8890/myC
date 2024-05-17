#include "iostream"
#include "queue"

using namespace std;

struct TreeNode {
    int data;
    int left, right;
    TreeNode *lchild;
    TreeNode *rchild;

    TreeNode(int x, int y, int z) : data(x), left(y), right(z), lchild(nullptr), rchild(nullptr) {}
};

TreeNode *createTree(TreeNode *T) {
    int val, left, right;
    queue<TreeNode *> q;

    scanf("%d %d %d", &val, &left, &right);
    T = new TreeNode(val, left, right);
    q.push(T);

    TreeNode *p = nullptr;
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
    if (T1 == nullptr)return T2;
    if (T2 == nullptr)return T1;

    queue<TreeNode *> q;
    q.push(T1);
    q.push(T2);

    while (!q.empty()) {
        TreeNode *p1 = q.front();
        q.pop();
        TreeNode *p2 = q.front();
        q.pop();
        p1->data+=p2->data;
        if (p1->lchild!= nullptr&&p2->lchild!= nullptr){
            q.push(p1->lchild);
            q.push(p2->lchild);
        } else if (p1->lchild== nullptr){
            p1->lchild=p2->lchild;
        }
        if (p1->rchild!= nullptr&&p2->rchild!= nullptr){
            q.push(p1->rchild);
            q.push(p2->rchild);
        } else if (p1->rchild== nullptr){
            p1->rchild=p2->rchild;
        }
    }
    return T1;
}

void preMerge(TreeNode *T1, TreeNode *T2) {
    if (T1 == nullptr && T2 == nullptr) {
        return;
    }
    if (T1 == nullptr) {
        T1 = new TreeNode(0, 0, 0);
    } else if (T2 == nullptr) {
        T2 = new TreeNode(0, 0, 0);
    }
    printf("%d ", T1->data + T2->data);
    preMerge(T1->lchild, T2->lchild);
    preMerge(T1->rchild, T2->rchild);
}

void inMerge(TreeNode *T1, TreeNode *T2) {
    if (T1 == nullptr && T2 == nullptr) {
        return;
    }
    if (T1 == nullptr) {
        T1 = new TreeNode(0, 0, 0);
    } else if (T2 == nullptr) {
        T2 = new TreeNode(0, 0, 0);
    }
    inMerge(T1->lchild, T2->lchild);
    printf("%d ", T1->data + T2->data);
    inMerge(T1->rchild, T2->rchild);
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
//        int preout[105];
//        preMerge(T1, T2);
//        printf("\n");
//        inMerge(T1, T2);
        T1=merge(T1, T2);
        preOrderTraversal(T1);
        printf("\n");
        inOrderTraversal(T1);
    }
    return 0;
}