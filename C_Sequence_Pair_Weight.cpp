#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll f;
        map<ll, vector<ll>> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> f;
            mp[f].push_back(i);
        }
        ll ans = 0;

        for (auto i : mp)
        {
            ll psum = 0;
            for (auto x : i.second)
            {
                ans += psum * (n - x);
                psum += (x + 1);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
