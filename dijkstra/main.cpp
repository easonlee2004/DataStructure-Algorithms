#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int g[N][N], dist[N];
bool st[N];
int n; // 节点数

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist); // 所有dist置为无穷大
    dist[1] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        } // 参考kmp的相同实现

        for (int j = 1; j <= n; j++)
            if (!st[j])
                dist[j] = min(dist[j], dist[t] + g[t][j]); // 用t节点更新其他节点

        st[t] = 1;
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}
// 若接受输出a, b，输出a到b距离
// 则设置dist[a]=0
// 返回值为dist[b]

int main()
{
    return 0;
}