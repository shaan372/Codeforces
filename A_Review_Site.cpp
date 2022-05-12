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

ll sumofdigit(ll n)
{
    ll s = 0;
    while (n > 0)
    {
        ll r = n % 10;
        s += r;
        n = n / 10;
    }
    return s;
}
ll gcd(ll a, ll b)
{
    if (b % a == 0)
    {
        return a;
    }
    else
    {
        return gcd(b % a, a);
    }
}

/*-----------------------------------ACTUAL CODE STARTS HERE-----------------------------------------------------*/

int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll r;
        ll u = 0;
        f(i, 0, n)
        {
            cin >> r;
            if (r != 2)
                u++;
        }
        cout << u << nl;
    }
    return 0;
}
