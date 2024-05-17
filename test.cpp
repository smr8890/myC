#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int center;
    struct Tree* left;
    struct Tree* right;
} Tree;

Tree* creatTree(int a)
{
    Tree* newnode=(Tree* )malloc(sizeof(Tree));
    newnode->center=a;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

Tree* buildTree(int n,int node[][5])
{
    Tree* node_tem[105]={NULL};
    for(int i=1;i<=n;i++)
    {
        node_tem[i]=creatTree(node[i-1][0]);
    }
    int left,right;
    for(int i=1;i<=n;i++)
    {
        left=node[i-1][1];
        right=node[i-1][2];
        if(left!=0)
        {
            node_tem[i]->left=node_tem[left];
        }
        if(right!=0)
        {
            node_tem[i]->right=node_tem[right];
        }
    }
    return node_tem[1];
}

Tree* mergeTree(Tree* a1,Tree* a2)
{
    if(a1==NULL)
    {
        return a2;
    }
    if(a2==NULL)
    {
        return a1;
    }
    a1->center+=a2->center;
    a1->left=mergeTree(a1->left,a2->left);
    a1->right=mergeTree(a1->right,a2->right);
    return a1;
}

void pre(Tree* a)
{
    if(a==NULL)
    {
        return;
    }
    printf("%d",a->center);
    if(a->left!=NULL||a->right!=NULL)
    {
        printf(" ");
    }
    pre(a->left);
    if(a->left!=NULL&&a->right!=NULL)
    {
        printf(" ");
    }
    pre(a->right);
}

void in(Tree* a)
{
    if(a==NULL)
    {
        return;
    }
    in(a->left);
    if(a->left!=NULL)
    {
        printf(" ");
    }
    printf("%d",a->center);
    if(a->right!=NULL)
    {
        printf(" ");
    }
    in(a->right);
}

void freespace(Tree* a)
{
    if(a==NULL)
    {
        return;
    }
    freespace(a->left);
    freespace(a->right);
    free(a);
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n1,n2;
        scanf("%d",&n1);
        int a1[105][5];
        for(int i=0;i<n1;i++)
        {
            scanf("%d %d %d",&a1[i][0],&a1[i][1],&a1[i][2]);
        }
        scanf("%d",&n2);
        int a2[105][5];
        for(int i=0;i<n2;i++)
        {
            scanf("%d %d %d",&a2[i][0],&a2[i][1],&a2[i][2]);
        }
        Tree* tree1=buildTree(n1,a1);
        Tree* tree2=buildTree(n2,a2);
        Tree* new_tree=mergeTree(tree1,tree2);
        pre(new_tree);
        printf("\n");
        in(new_tree);
        printf("\n");
        freespace(new_tree);
    }
    return 0;
}