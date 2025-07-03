// kmp
#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int ne[N];

void nextArr(string s)
{
    int l2 = s.length();
    ne[0] = -1;
    if (l2 == 1) return;
    ne[1] = 0;

    // i表示当前要求next值的位置
    // cn表示当前要和前一个字符比对的下标
    int i = 2, cn = 0;
    while (i < l2)
    {
        if(s[i-1] == s[cn]) // 往后一项也匹配成功
        {
            ne[i++] = ++cn; // next值从1开始，cn从0开始，注意下标差
        }
        else if (cn > 0) // 还能跳转
        {
            cn = ne[cn]; // 向前跳转
        }
        else
        {
            ne[i++] = 0;
        }
    }
}

int kmp(string s1, string s2)
{
    int l1 = s1.length(), l2 = s2.length();
    int x = 0, y = 0; // xy为比较指针
    nextArr(s2);
    while (x < l1 && y < l2)
    {
        if (s1[x] == s2[y]) // 匹配成功，指针后移
        {
            x++;
            y++;
        }
        else if (y == 0) // s2的第一个都不匹配，后移x
        {
            x++;
        }
        else
        {
            y = ne[y];
        }
    }

    return y == l2 ? x - y : -1;
    // y==l2说明匹配到末尾了，范围为0~l2-1
    // 返回匹配成功的头位置
    // 失败返回-1
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout<< kmp(s1, s2) << endl; // 打印的是数组下标，按照情景灵活+1

    return 0;
}