#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

const int N = 10000;
int n; // n表示点数
int g[N][N]; // 邻接矩阵，存储所有边
int dist[N]; // 存储其他点到当前最小生成树的距离
bool st[N]; // 存储每个点是否已经在生成树中


// 如果图不连通，则返回INF(值是0x3f3f3f3f), 否则返回最小生成树的树边权重之和
int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i ++) // 生成树每次加入一个节点，共需n次循环
    {
        // 遍历所有节点，找到离生成树最近的节点t
        int t = -1;
        for (int j = 1; j <= n; j ++)
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
            // t==-1表示正在尝试第一个没加入的节点
            // t!=1时才比较dist[j] < dist[t]，找出最近的t
                t = j;

        // i第一轮为0，不涉及return和生成树大小的累加。从i=1开始

        if (i && dist[t] == INF) // 更新dist后还不连通，无生成树
            return INF;

        if (i)
            res += dist[t]; // 生成树大小累加
        st[t] = true; // t加入树中

        // 使用新加入生成树的节点t来更新其他点的dist
        for (int j = 1; j <= n; j ++) dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}

int main()
{
    return 0;
}