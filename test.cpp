#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int N = 5000;

struct node //存储每一条边
{
    int from;
    int to;
    int w;
} a[N * 10];

bool cmp(node aa, node bb) //排序
{
    return aa.w > bb.w; //注意，和最小生成树的排序不同
}

int n, m, k, t;
int f[N]; //存储每一个点的父亲节点

int getf(int v) //寻找父亲节点；
{
    if (f[v] == v)
        return f[v];

    return f[v] = getf(f[v]);
}

int Kruskal() {
    sort(a, a + k, cmp); //按照边的权值由大到小进行排序；
    int ans = 0, countt = 1;
    for (int i = 0; i < k; i++) {
        int t1 = getf(a[i].from);
        int t2 = getf(a[i].to);
        if (t1 != t2) //父亲节点不同，不会构成环路；
        {
            ans += a[i].w;
            f[t2] = t1; //把父亲节点改成相同；
            countt++;
            if (countt == n) //如果加入n条边就可以结束了；
                break;
        }
    }
    int sum1 = 0;
    for (int i = 0; i < k; i++) {
        sum1 += a[i].w;
    }
    return sum1 - ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d %d %d", &a[i].from, &a[i].to, &a[i].w);
        }
        for (int i = 0; i <= N; i++) //初始化，自己的父亲节点是自己；
            f[i] = i;
        int kk = Kruskal();
        printf("%d\n", kk);
    }
    return 0;
}
