#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1 || n == 2)
    {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
