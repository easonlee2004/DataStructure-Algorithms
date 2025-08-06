#include <iostream>
using namespace std;

int qpow(int a, int b)
{
    int ans = 1, temp = a;
    // ans存结果，temp为位权
    while (b)
    {
        if (b % 2) ans *= temp;
        b /= 2;
        temp *= temp;
    }
    return ans;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << qpow(a, b) << endl;

    return 0;
}