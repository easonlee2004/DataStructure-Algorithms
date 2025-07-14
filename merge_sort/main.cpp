#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int n;
int arr[N];

void mergesort(int l, int r)
{
    if (l == r) return; // 边界条件
    int m = (l + r) / 2;
    mergesort(l, m);
    mergesort(m + 1, r);
    
    // merge操作
    int help[N];
    int a = l, b = m + 1, idx = l; // idx容易被误认为从0开始
    while (a <= m && b <= r) // 双指针将小的元素放入help数组
        help[idx++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];

    // 当左右其中一侧已经放完，另一侧的尾巴接在help数组后
    while (a <= m)
        help[idx++] = arr[a++];
    while (b <= r)
        help[idx++] = arr[b++];

    for (int i = l; i <= r; i++)
        arr[i] = help[i];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    mergesort(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}