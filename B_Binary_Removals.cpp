#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int first1 = 1e9;
        for (int i = 0; i + 1 < s.size(); ++i)
        {
            if (s[i] == '1' && s[i + 1] == '1')
            {
                first1 = i;
                break;
            }
        }
        int last0 = -1;
        for (int i = 0; i + 1 < s.size(); ++i)
        {
            if (s[i] == '0' && s[i + 1] == '0')
            {
                last0 = i;
            }
        }
        if (last0 > first1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}
