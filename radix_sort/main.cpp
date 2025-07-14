#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int n, bits; // bits表示数组a中最大元素的位数，如元素1234为4位
int a[N];

// 此算法只支持非负数排序，但是负数经过处理也可以实现
// 具体为遍历数组得到min，然后每个数都减去min（min为负数）
// 这样所有数都是非负数，排完序之后再加回min

// offset : 1, 10, 100, ...
// 代表处理个、十、百、千、万
void radix_sort()
{
    int s[N]; // 计数数组
    int help[N]; // 相当于桶
    for (int offset = 1; bits > 0; offset *= 10, bits--) // 每轮处理完bits少一位
    {
        for (int i = 0; i < n; i++)
            s[(a[i] / offset) % 10]++; // (a[i] / offset) % 10表示offset位的数字
        for (int i = 1; i < 10; i++) // 前缀和 从0~9
            s[i] += s[i-1];
        
        for (int i = n - 1; i >= 0; i--) // 数组倒序入桶，保证稳定性
            help[--s[(a[i] / offset) % 10]] = a[i];

        for (int i = 0; i < n; i++)
            a[i] = help[i];
    }
}

int main()
{
    cin >> n;
    int maxn = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    while (maxn > 0)
    {
        bits++;
        maxn /= 10;
    }
    
    radix_sort();
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    
    return 0;
}