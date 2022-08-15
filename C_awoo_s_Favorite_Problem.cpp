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

ll digitsum(ll n){ll s = 0;while (n > 0){ll r = n % 10;s += r;n = n / 10;}return s;}
ll inv(ll i) {if (i == 1) return 1; return (M - ((M / i) * inv(M % i)) % M) % M;}
ll gcd(ll a, ll b){if (b % a == 0){return a;}else{return gcd(b % a, a);}}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;}//O(sqrt(N))
bool isPrime(ll n){if (n <= 1) return false; for (ll i = 2; i < n; i++)if (n % i == 0) return false; return true;}
ll binExpo(ll a, ll b){ if(b==0) return 1;if(b==1) return a; int r = binExpo(a, b/2); if(b%2==0) return (r%M * r%M)%M; else return (r%M*r%M*a%M)%M;}
ll fast_mul(ll x, ll y){if (x == 0) return 0; else if (x % 2 == 1) return (fast_mul(x >> 1, y << 1) + y); else return fast_mul(x >> 1, y << 1);}
vector<ll> sieve(ll n){vector<bool> is_prime(n + 1, true);is_prime[0] = is_prime[1] = false;for (ll i = 2; i <= n; i++){if (is_prime[i] && i * i <= n){for (int j = i * i; j <= n; j += i)is_prime[j] = false;}}vector<ll> ans;for (ll i = 0; i <= n; i++){if (is_prime[i])ans.pb(i);}return ans;}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------*/

void solve()
{
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<ll> a1, a2, c1, c2;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            a1.pb(i);
        if (s[i] == 'c')
            c1.pb(i);
    }
    for (ll i = 0; i < n; i++)
    {
        if (t[i] == 'a')
            a2.pb(i);
        if (t[i] == 'c')
            c2.pb(i);
    }
    if ((c1.size() != c2.size()) || (a1.size() != a2.size()))
    {
        cout << "NO" << nl;
        return;
    }
    ll x = a1.size();
    for (ll i = 0; i < x; i++)
    {
        if (a1[i] > a2[i])
        {
            cout << "NO" << nl;
            return;
        }
    }
    x = c1.size();
    for (ll i = 0; i < x; i++)
    {
        if (c1[i] < c2[i])
        {
            cout << "NO" << nl;
            return;
        }
    }
    vector<pair<ll, ll>> p;
    for (ll i = 0; i < n - 1; i++)
    {
        if (s[i] == 'a' && s[i + 1] == 'c')
            p.pb({i, i + 1});
    }
    for (auto i : p)
    {
        if (t[i.ff] == 'a' && t[i.ss] == 'c')
            continue;
        cout << "NO" << nl;
        return;
    }
    string str1, str2;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'b')
            continue;
        str1.pb(s[i]);
    }
    for (ll i = 0; i < n; i++)
    {
        if (t[i] == 'b')
            continue;
        str2.pb(t[i]);
    }
    if (str1 == str2)
        cout << "YES" << nl;
    else
        cout << "NO" << nl;
}

int main(int argc, char const *argv[])
{
    fast_io;
    fast_io2;
    ll t;
    cin >> t;
    // t = 1;
    while (t--)
        solve();
    return 0;
}