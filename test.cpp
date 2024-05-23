#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int N = 5000;

struct node //�洢ÿһ����
{
    int from;
    int to;
    int w;
} a[N * 10];

bool cmp(node aa, node bb) //����
{
    return aa.w > bb.w; //ע�⣬����С������������ͬ
}

int n, m, k, t;
int f[N]; //�洢ÿһ����ĸ��׽ڵ�

int getf(int v) //Ѱ�Ҹ��׽ڵ㣻
{
    if (f[v] == v)
        return f[v];

    return f[v] = getf(f[v]);
}

int Kruskal() {
    sort(a, a + k, cmp); //���ձߵ�Ȩֵ�ɴ�С��������
    int ans = 0, countt = 1;
    for (int i = 0; i < k; i++) {
        int t1 = getf(a[i].from);
        int t2 = getf(a[i].to);
        if (t1 != t2) //���׽ڵ㲻ͬ�����ṹ�ɻ�·��
        {
            ans += a[i].w;
            f[t2] = t1; //�Ѹ��׽ڵ�ĳ���ͬ��
            countt++;
            if (countt == n) //�������n���߾Ϳ��Խ����ˣ�
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
        for (int i = 0; i <= N; i++) //��ʼ�����Լ��ĸ��׽ڵ����Լ���
            f[i] = i;
        int kk = Kruskal();
        printf("%d\n", kk);
    }
    return 0;
}
