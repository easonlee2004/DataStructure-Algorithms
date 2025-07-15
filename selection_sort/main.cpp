#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int n;
int a[N];

void selection_sort()
{
    // 当前排第i个元素，遍历i+1到n-1找到最小j。如果不在i位置则swap
    // 只需要排n-1次。最后一位一定是最大值
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(a[min], a[i]);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    selection_sort();
    for (int i = 0; i < n; i++)
        cout<< a[i] << " ";
    cout << endl;
}