#include <iostream>
#include <string>
using namespace std;

string value;
string pattern;
int _next[1000];
void makeNext(string pattern)
{
    int q,k;
    int m = pattern.length();
    _next[0] = 0;
    for (q = 1,k = 0; q < m; ++q)
    {
        while(k > 0 && pattern[q] != pattern[k])
            k = _next[k-1];
        if (pattern[q] == pattern[k])
        {
            k++;
        }
        _next[q] = k;
    }
}

int kmp(string value, string pattern)
{
    int n,m;
    int i,q;
    n = value.length();
    m = pattern.length();
    for (i = 0,q = 0; i < n; ++i)
    {
        while(q > 0 && pattern[q] != value[i])
            q = _next[q-1];
        if (pattern[q] == value[i])
        {
            q++;
        }
        if (q == m)
        {
           cout << i-1 << endl;
            q = 0;
        }
    }
}

int main()
{
    string value;
    string pattern;
    cin >> value;
    cin >> pattern;
    makeNext(pattern);
    kmp(value, pattern);


    return 0;
}