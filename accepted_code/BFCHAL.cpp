#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
string str;
int main()
{
    cin >> str;
    for (int i=0; i<str.size(); i++)
        putchar(toupper(str[i]));
    return 0;
}