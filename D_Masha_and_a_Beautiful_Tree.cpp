#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ull unsigned long long
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second

#define all(x) (x).begin(), (x).end()
#define prDouble(x,y) cout << fixed << setprecision(y) << x
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fast_io2 cin.exceptions(cin.failbit);
#define M 1000000007
#define inf 1000000000000000005
#define MOD 998244353
#define nl endl

using namespace std;
using namespace __gnu_pbds;

template <class T> using maxheap = priority_queue<T>;
template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template <class T, class V = less<T>> using pbds = tree<T, null_type, V, rb_tree_tag, tree_order_statistics_node_update>; //find_by_order, order_of_key

/*-------------------------------------------------------------------------------------------------------------------------------------*/

void google_case(ll i){cout<<"Case #"<<i<<": ";}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll inv(ll n, ll m) {ll res = expo(n, m-2, m); return res;}
ll mod_add(ll a, ll b, ll m){ll res = (a % m + b % m + m) % m;return res;}
ll mod_mul(ll a, ll b, ll m){ll res = (a % m * b % m) % m;return res;}
ll mod_sub(ll a, ll b, ll m){ll res = (a % m - b % m + m) % m;return res;}
bool isPrime(ll n){if (n <= 1) return false; for (ll i = 2; i < n; i++)if (n % i == 0) return false; return true;}
ll fast_mul(ll x, ll y){if (x == 0) return 0; else if (x % 2 == 1) return (fast_mul(x >> 1, y << 1) + y); else return fast_mul(x >> 1, y << 1);}
vector<ll> sieve(ll n){vector<bool> is_prime(n + 1, true);is_prime[0] = is_prime[1] = false;for (ll i = 2; i <= n; i++){if (is_prime[i] && i * i <= n){for (int j = i * i; j <= n; j += i)is_prime[j] = false;}}vector<ll> ans;for (ll i = 0; i <= n; i++){if (is_prime[i])ans.pb(i);}return ans;}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------*/

bool check(vector<ll> &a)
{
    ll n = a.size();
    for (ll i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
            return false;
    }
    return true;
}
bool double_check(vector<ll> &v)
{
    ll n = v.size();
    for (ll i = 0; i < n; i++)
    {
        if (v[i] != i + 1)
            return false;
    }
    return true;
}
bool sorted(ll l1, ll r1, ll l2, ll r2, vector<ll> &v)
{
    vector<ll> a;
    for (ll i = l1; i <= r1; i++)
        a.pb(v[i]);
    for (ll i = l2; i <= r2; i++)
        a.pb(v[i]);
    if (check(a) == true)
    {
        ll l = min(l1, l2);
        ll r = max(r2, r1);
        ll ind = 0;
        for (ll i = l; i <= r; i++)
        {
            v[i] = a[ind];
            ind++;
        }
        return true;
    }
    return false;
}
ll solve(vector<ll> &v, ll l, ll r)
{
    if (l == r)
        return 0;
    ll mid = (l + r) >> 1;
    ll left = solve(v, l, mid);
    ll right = solve(v, mid + 1, r);
    ll temp = 0;
    if (sorted(l, mid, mid + 1, r, v) == true)
        temp = 0;
    if (sorted(mid + 1, r, l, mid, v) == true)
        temp = 1;
    return temp + left + right;
}
void run_case()
{
    ll m;
    cin >> m;
    vector<ll> v(m);
    for (ll i = 0; i < m; i++)
        cin >> v[i];
    ll ans = solve(v, 0, m - 1);
    if (double_check(v) == false)
        cout << "-1" << nl;
    else
        cout << ans << nl;
}

int main(int argc, char const *argv[])
{
    fast_io;
    fast_io2;
    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        // google_case(i);
        run_case();
    }
    return 0;
}