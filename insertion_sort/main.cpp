#include <iostream>
using namespace std;

const int N = 10000;
int n;
int a[N];

// 对于第i个需要排序的元素来说，用j指针向前寻找第一个小于他的元素
// 寻找过程中都后移，直到循环退出
// 此时j指向第一个小于他的元素位置，我们只需要在j+1插入这个temp即可
void insertion_sort()
{
    for (int i = 0; i < n; i++)
    {
        int temp = a[i]; // temp记录a[i]，否则会被前项覆盖
        int j;
        for (j = i - 1; j >= 0 && a[j] > temp; j--) // 此处不要写成a[j] > a[i]，应该用temp
            a[j + 1] = a[j];
        a[j + 1] = temp; // j指向小于temp的数，所以插入位置为j+1
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    insertion_sort();
    for (int i = 0; i < n; i++)
        cout<< a[i] << " ";
    cout << endl;

    return 0;
}