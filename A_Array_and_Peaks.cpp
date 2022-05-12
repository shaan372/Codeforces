#include <bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<int> v(n, -1);
        if (2 * k >= n)
        {
            cout << "-1\n";
            continue;
        }
        ll z = n;
        for (ll i = 1; i < 2 * k; i += 2)
        {
            v[i] = z;
            z--;
        }
        for (ll i = 0; i < n; i++)
        {
            if (v[i] == -1)
            {
                v[i] = z;
                z--;
            }
        }
        for (ll i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
