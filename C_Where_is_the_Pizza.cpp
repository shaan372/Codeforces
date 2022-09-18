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

void init(vector<ll> &par, vector<ll> &sz, ll n)
{
    for (ll i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
}
ll find(vector<ll> &par, ll u)
{
    if (par[u] == u)
        return u;
    return par[u] = find(par, par[u]);
}
void Union(vector<ll> &par, vector<ll> &sz, ll u, ll v)
{
    u = find(par, u);
    v = find(par, v);
    if (u == v)
        return;
    if (sz[u] < sz[v])
        swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}
ll bin_expo(ll a, ll b)
{
    if (a == 1 || b == 0)
        return 1;
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res % M * a % M) % M;
        a = (a % M * a % M) % M;
        b >>= 1;
    }
    return res;
}
void run_case()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    for (auto &i : c)
        cin >> i;
    vector<ll> par(n + 1, 0), sz(n + 1, 0);
    init(par, sz, n);
    for (ll i = 0; i < n; i++)
    {
        Union(par, sz, a[i], b[i]);
        if (a[i] == b[i])
            c[i] = a[i];
    }
    set<ll> st;
    for (ll i = 1; i <= n; i++)
        st.insert(find(par, i));
    for (auto i : c)
    {
        if (i == 0)
            continue;
        st.erase(find(par, i));
    }
    ll ans = bin_expo(2, st.size());
    cout << ans << nl;
}

int main(int argc, char const *argv[])
{
    fast_io;
    fast_io2;
    ll t = 1;
    cin >> t;
    while (t--)
        run_case();
    return 0;
}