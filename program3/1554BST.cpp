#include "iostream"

using namespace std;

struct Treenode {
    int data;
    Treenode *lchild;
    Treenode *rchild;

    Treenode(int x) : data(x), lchild(NULL), rchild(NULL) {}
};


Treenode *insert(Treenode *T, int x, int &high) {
    if (T == NULL) {
        T = new Treenode(x);
        high++;
    } else {
        if (x < T->data) {
            high++;
            T->lchild = insert(T->lchild, x, high);
        } else if (x > T->data) {
            high++;
            T->rchild = insert(T->rchild, x, high);
        }
    }
    return T;
}

void freeTree(Treenode *T) {
    if (T == NULL)return;
    freeTree(T->lchild);
    freeTree(T->rchild);
    free(T);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        int a[1005];
        scanf("%d", &n);
        int high = 0;
        Treenode *T1 = NULL;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            T1 = insert(T1, a[i], high);
        }
        printf("%d\n", high);
        freeTree(T1);
    }
    return 0;
}