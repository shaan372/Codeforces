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
ll inv(ll i) {if (i == 1) return 1; return (M - ((M / i) * inv(M % i)) % M) % M;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;}//O(sqrt(N))
bool isPrime(ll n){if (n <= 1) return false; for (ll i = 2; i < n; i++)if (n % i == 0) return false; return true;}
ll fast_mul(ll x, ll y){if (x == 0) return 0; else if (x % 2 == 1) return (fast_mul(x >> 1, y << 1) + y); else return fast_mul(x >> 1, y << 1);}
vector<ll> sieve(ll n){vector<bool> is_prime(n + 1, true);is_prime[0] = is_prime[1] = false;for (ll i = 2; i <= n; i++){if (is_prime[i] && i * i <= n){for (int j = i * i; j <= n; j += i)is_prime[j] = false;}}vector<ll> ans;for (ll i = 0; i <= n; i++){if (is_prime[i])ans.pb(i);}return ans;}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------*/

const ll max_n = 20;
map<ll, ll> dp[max_n][max_n];
ll ans, half;
void calclf(ll x, ll y, ll val, ll cnt, ll n, ll m, vector<vector<ll>> &a)
{
    val ^= a[x][y];
    if (cnt == half)
    {
        dp[x][y][val]++;
        return;
    }
    if (x + 1 < n)
        calclf(x + 1, y, val, cnt + 1, n, m, a);
    if (y + 1 < m)
        calclf(x, y + 1, val, cnt + 1, n, m, a);
}

void calcrg(ll x, ll y, ll val, ll cnt, ll n, ll m, ll k, vector<vector<ll>> &a)
{
    if (cnt == n + m - 2 - half)
    {
        if (dp[x][y].count(k ^ val))
            ans += dp[x][y][k ^ val];
        return;
    }
    if (x > 0)
        calcrg(x - 1, y, val ^ a[x][y], cnt + 1, n, m, k, a);
    if (y > 0)
        calcrg(x, y - 1, val ^ a[x][y], cnt + 1, n, m, k, a);
}
void run_case()
{
    ll n, m, k;
    cin >> n >> m >> k;
    half = (n + m - 2) / 2;
    vector<vector<ll>> v(n, vector<ll>(m));
    for (auto &i : v)
        for (auto &j : i)
            cin >> j;
    calclf(0, 0, 0, 0, n, m, v);
    calcrg(n - 1, m - 1, 0, 0, n, m, k, v);
    cout << ans << nl;
}

int main(int argc, char const *argv[])
{
    fast_io;
    fast_io2;
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        // google_case(i);
        run_case();
    }
    return 0;
}