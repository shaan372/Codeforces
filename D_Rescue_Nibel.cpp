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
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;}//O(sqrt(N))
bool isPrime(ll n){if (n <= 1) return false; for (ll i = 2; i < n; i++)if (n % i == 0) return false; return true;}
ll fast_mul(ll x, ll y){if (x == 0) return 0; else if (x % 2 == 1) return (fast_mul(x >> 1, y << 1) + y); else return fast_mul(x >> 1, y << 1);}
vector<ll> sieve(ll n){vector<bool> is_prime(n + 1, true);is_prime[0] = is_prime[1] = false;for (ll i = 2; i <= n; i++){if (is_prime[i] && i * i <= n){for (int j = i * i; j <= n; j += i)is_prime[j] = false;}}vector<ll> ans;for (ll i = 0; i <= n; i++){if (is_prime[i])ans.pb(i);}return ans;}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------*/

const ll max_n = 3e5 + 10;
ll fact[max_n];
ll ifact[max_n];
void solve()
{
    fact[0] = 1;
    for (ll i = 1; i < max_n; i++)
        fact[i] = (i % MOD * fact[i - 1] % MOD) % MOD;
    ifact[max_n - 1] = inv(fact[max_n - 1], MOD);
    for (ll i = max_n - 2; i >= 0; i--)
        ifact[i] = ((i + 1) % MOD * ifact[i + 1] % MOD) % MOD;
}
ll comb(ll n, ll r)
{
    ll ans = ((fact[n] % MOD * ifact[r] % MOD) % MOD * ifact[n - r] % MOD) % MOD;
    return ans;
}
void run_case()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> l(n), r(n);
    for (ll i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    sort(all(l));
    sort(all(r));
    ll i = 0, j = 0;
    ll ans = 0;
    ll lamp = 0;
    while (i < n && j < n)
    {
        if (l[i] <= r[j])
        {
            if (lamp >= k - 1)
                ans = (ans % MOD + comb(lamp, k - 1) % MOD) % MOD;
            lamp++;
            i++;
        }
        else
        {
            lamp--;
            j++;
        }
    }
    cout << ans << nl;
}

int main(int argc, char const *argv[])
{
    fast_io;
    fast_io2;
    ll t = 1;
    // cin >> t;
    solve();
    for (ll i = 1; i <= t; i++)
    {
        // google_case(i);
        run_case();
    }
    return 0;
}