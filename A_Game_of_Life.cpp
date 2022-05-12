#include <bits/stdc++.h>

#define ll long long
#define vi vector<ll>
#define gi greater<ll>
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vector<ll>, greater<ll>>
#define pb push_back
#define eb emplace_back
#define pii pair<ll, ll>
#define spi set<pii>
#define si set<int>
#define mpci map<char, ll>
#define mpii map<ll, ll>
#define f(i, a, n) for (ll i = a; i < n; i++)
#define fi(i, n, a) for (ll i = n - 1; i >= 0; i--)
#define M 1000000007
#define nl endl

using namespace std;

/*-----------------------------------ACTUAL CODE STARTS HERE-----------------------------------------------------*/

int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int p;
        ll x = min(n, m);
        while (x--)
        {
            vi v;
            f(i, 0, n)
            {
                if (i == 0)
                {
                    if (s[i] == '0' && s[i + 1] == '1')
                        v.pb(i);
                }
                else if (i == n - 1)
                {
                    if (s[i] == '0' && s[i - 1] == '1')
                        v.pb(i);
                }
                else
                {
                    if ((s[i] == '0') && (((s[i - 1] - '0') + (s[i + 1] - '0')) == 1))
                        v.pb(i);
                }
            }
            for (auto j : v)
                s[j] = '1';
        }
        cout << s << nl;
    }
    return 0;
}
