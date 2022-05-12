#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        ll m, n, k;
        cin >> m >> n >> k;
        if (k == m * n - 1)
        {
            cout << "YES\n";
            continue;
        }
        else
        {
            cout << "NO\n";
            continue;
        }
    }
    return 0;
}
