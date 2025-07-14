#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int n;
int a[N];

void quick_sort(int l, int r)
{
    if (l >= r) return;
    int i = l, j = r;
    int x = a[l]; // 基准为第一个元素，保存在x中。现在l位置逻辑上为空

    while (i < j)
    {
        while (i < j && a[j] >= x) // 从右向左寻找第一个小于基准的j
            j--;
        if (i < j)
            a[i++] = a[j]; // i位置为空，放入j。此时j逻辑上为空，用于放入下一个i

        while (i < j && a[i] < x) // 从左向右寻找第一个小于基准的i
            i++;
        if (i < j)
            a[j--] = a[i]; // j位置为空，放入i。此时i逻辑上为空，用于放入下一个j
    }

    a[i] = x; // 由于i和j都是单步，此时i==j
    quick_sort(l, i - 1);
    quick_sort(i + 1, r);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quick_sort(0, n-1);
    for (int i = 0; i < n; i++)
        cout<< a[i] << " ";
    cout << endl;

    return 0;
}