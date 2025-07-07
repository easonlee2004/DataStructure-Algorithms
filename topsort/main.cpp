#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;
int n, m; // n 节点数，m 边数
int cnt; // cnt == n才存在拓扑排序，否则有环
int indegree[N]; // 入度
queue<int> q;
int ans[N];

// 邻接表
int h[N], e[N], ne[N], idx;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool topsort()
{
    for (int i = 1; i <= n; i++)
        if(!indegree[i])
            q.push(i);

    while(!q.empty())
    {
        auto t = q.front();
        q.pop();
        ans[cnt++] = t;
        for (int i = h[t]; i != -1; i = ne[i]) // 遍历队列头所连接的点，入度--
            if (--indegree[e[i]] == 0) // --后入度为0则加入队列
                q.push(e[i]);
    }

    return cnt == n;
}

int main()
{
    memset(h, -1, sizeof h);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        indegree[b]++;
    }

    if (topsort())
    {
        for (int i = 0; i < cnt; i++)
        {
            cout << ans[i] << " ";
        }
    }
    else cout << -1;

    return 0;
}