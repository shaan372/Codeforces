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
ll binExpo(ll a, ll b){if (a == 1 || b == 0) return 1;ll res = 1; while (b){if (b & 1)res = (res % M * a % M) % M;a = (a % M * a % M) % M;b >>= 1;}return res;}
ll fast_mul(ll x, ll y){if (x == 0) return 0; else if (x % 2 == 1) return (fast_mul(x >> 1, y << 1) + y); else return fast_mul(x >> 1, y << 1);}
vector<ll> sieve(ll n){vector<bool> is_prime(n + 1, true);is_prime[0] = is_prime[1] = false;for (ll i = 2; i <= n; i++){if (is_prime[i] && i * i <= n){for (int j = i * i; j <= n; j += i)is_prime[j] = false;}}vector<ll> ans;for (ll i = 0; i <= n; i++){if (is_prime[i])ans.pb(i);}return ans;}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------------*/

void run_case()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (auto &i : a)
    {
        cin >> i;
        i++;
    }
    for (auto &i : b)
    {
        cin >> i;
        i++;
    }
    a[0]--;
    vector<ll> down(n);
    vector<ll> up(n);
    up[n - 1] = max(a[n - 1], b[n - 1] - 1);
    down[n - 1] = max(b[n - 1], a[n - 1] - 1);
    ll steps = 3;
    for (int i = n - 2; i >= 0; i--)
    {
        up[i] = max(up[i + 1] - 1, max(a[i], b[i] - steps));
        down[i] = max(down[i + 1] - 1, max(b[i], a[i] - steps));
        steps += 2;
    }
    ll ans = inf;
    ll currentTime = -1;
    for (int i = 0; i < n; i++)
    {
        currentTime++;
        ll timeAllowed = inf;
        if (i & 1)
            currentTime = max(currentTime, b[i]);
        else
            currentTime = max(currentTime, a[i]);

        if (i & 1)
            timeAllowed = max(currentTime, down[i]);
        else
            timeAllowed = max(currentTime, up[i]);

        currentTime++;
        if (i & 1)
            currentTime = max(currentTime, a[i]);
        else
            currentTime = max(currentTime, b[i]);
        ans = min(ans, timeAllowed + (n - i) * 2 - 1);
    }
    ans = min(ans, currentTime);
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