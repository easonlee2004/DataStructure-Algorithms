// floyd
#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int n;
int d[N][N];

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    // 注意先k，再i、j
}

int main()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j) d[i][j] = 0;
            else d[i][j] = 0x3f3f3f3f;
    // 接着还需添加g[i][j]到d[i][j]中，此处省略
    floyd();
}