#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int n;
int a[N];

void bubble_sort()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                a[j] ^= a[j + 1];
                a[j + 1] ^= a[j];
                a[j] ^= a[j + 1];
            }
        }
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