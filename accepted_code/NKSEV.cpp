#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int base = 1337377;
const int N = 3e5 + 7;
int nt = 1,root = 1;
string st,s;
int n,f[N];
struct mang
{
    int kt;
    int link[30];
    mang()
    {
        kt = 0;
    }
};
mang a[N];
void insert_trie(string s1)
{
    int cur_node = root;
    for (int i = 0; i < s1.size(); i++)
    {
        int v = s1[i] - 'a';
        int &son = (a[cur_node].link[v]);
        if (son == 0) son = ++nt;
        cur_node = son;
    }
    a[cur_node].kt = 1;
}

int finding(char s1,int rr)
{
    int cur_node = rr;
    int v = s1 - 'a';
    int son = a[cur_node].link[v];
    if (son == 0) return 0;
    cur_node = son;
    if (a[cur_node].kt == 0) return -cur_node;
    return cur_node;
}
int main()
{
    cin >> st;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        reverse(s.begin(),s.end());
        insert_trie(s);
    }
    int n1 = st.size();
    root = 1;
    f[0] = 1;
    for (int i = 1; i <= n1; i++)
    {
        int tt = 1;
        for (int j = i ; j >= 1; j--)
        {
            int kq = finding(st[j-1],tt);
            if (kq != 0)
            {
                if (kq > 0) f[i] = (f[i] + f[j-1]) % base;
            }
            else break;
            tt = abs(kq);
        }
    }
    cout << f[n1];
    return 0;
}
