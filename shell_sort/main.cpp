#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int n;
int a[N];

void shell_sort()
{
    for (int d = n / 2; d >= 1; d /= 2)
    {
    // 组内插入排序，1，1+d，1+2d...
    // 由于1一定有序，所以直接从d开始
        for (int i = d; i < n; i += d)
        {
            int temp = a[i];
            int j;
            for (j = i - d; j >= 0 && a[j] > temp; j -= d)
                a[j + d] = a[j];
            a[j + d] = temp; // j指向小于temp的数，所以插入位置为j+d
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    shell_sort();
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}