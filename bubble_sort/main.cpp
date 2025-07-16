#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int n;
int a[N];


// 考研代码比竞赛多一个flag
void bubble_sort()
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = 0; // 用于表示该轮是否有swap，没有说明有序，可以直接break
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
        if (!flag) return; // 节省无用功
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bubble_sort();
    for (int i = 0; i < n; i++)
        cout<< a[i] << " ";
    cout << endl;

    return 0;
}