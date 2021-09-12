#include <iostream>

using namespace std;
string f[105];
int n;
string operator+(string a, string b)
{
    string res; int carry=0;
    int i = max(a.size(), b.size());
    while (a.size() < i) a="0"+a;
    while (b.size() < i) b="0"+b;
    while (i--)
    {
        carry = a[i]-'0' + b[i]-'0' + carry/10;
        res = char(carry%10 + '0') + res;
    }
    if (carry / 10) res = '1' + res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    f[1] = "1";
    f[2] = "2";
    for (int i = 3; i<= 100; i++)
        f[i] = f[i-1] + f[i-2];
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        cout << f[t] << "\n";
    }
}
