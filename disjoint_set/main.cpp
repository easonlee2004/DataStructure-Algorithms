// disjoint-set
#include <iostream>
using namespace std;

int n;
const int N = 10000;
int p[N]; // parent
int s[N]; // size of the set

int find(int i)
{
    if (p[i] == i) return i;
    // 普通并查集
    // return find(p[i]);

    // 路径压缩并查集
    p[i] = find(p[i]); // p[i]永远指向根节点，所以find返回值都是根节点
    return p[i];
}

void merge(int a, int b) // 这里ab不一定是根，可以是普通节点
{
    // 普通合并
    // p[find(a)] = find(b);

    // 防止退化，小树并到大树
    if (s[find(a)] >= s[find(b)])
    {
        s[find(a)] += s[find(b)];
        p[find(b)] = find(a);
    }
}

int main()
{
    cin >> n;
    // 初始化
    for (int i = 1; i <= n; i++)
    {
        p[i] = i; // 初始每个节点的parent都是自己
        s[i] = 1;
    }

    return 0;
}