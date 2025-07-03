#include <iostream>
#include <stack>
using namespace std;

// 括号匹配检查，仅返回1和0
// 后续实现同步运算功能

bool bracketCheck(char *a, int length)
{
    stack<char> s;
    for(int i = 0; i < length; i++)
    {
        if(a[i] == '(' || a[i] == '[' || a[i] == '{')
        {
            s.push(a[i]);
        }
        else
        {
            if(s.empty())
            {
                return false;
            }

            if(a[i] == ')' && s.top() != '(') return false;
            if(a[i] == ']' && s.top() != '[') return false;
            if(a[i] == '}' && s.top() != '{') return false;

            s.pop();
        }
    }

    return s.empty();
}

int main()
{
    int length = 0;
    char a[100];
    cin >> a >> length;

    cout<< bracketCheck(a, length) << endl;
}