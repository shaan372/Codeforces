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

ll z0[5004][5004], z1[5004][5004];
void run_case()
{
    ll n, x, y;
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;
    ll d = 0;
    for (int i = 0; i < n; i++)
    {
        a[i] ^= b[i];
        d += a[i];
    }
    if (d % 2)
    {
        cout << -1 << endl;
        return;
    }
    if (d == 2)
    {
        int l, r;
        for (l = 0; !a[l];)
            l++;
        for (r = n - 1; !a[r];)
            r--;
        if (l + 1 == r)
            cout << min(x, 2 * y) << endl;
        else
            cout << min((r - l) * x, y) << endl;
        return;
    }
    if (!d || x >= y)
    {
        cout << d / 2 * y << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fill(z0[i], z0[i] + n + 1, 1LL << 60);
        fill(z1[i], z1[i] + n + 1, 1LL << 60);
    }
    if (a[0] == 0)
        z0[0][0] = 0;
    if (a[0] == 1)
        z1[0][1] = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i])
        {
            for (int j = i + 1; j >= 0; j--)
            {
                if (j <= i)
                    z0[i][j] = min(z0[i - 1][j + 1] + y, z1[i - 1][j + 1] + x);
                if (j)
                {
                    z0[i][j] = min({z0[i][j], z0[i - 1][j - 1] + x, z1[i - 1][j - 1] + y});
                    z1[i][j] = min(z0[i - 1][j - 1], z1[i - 1][j - 1]);
                }
            }
        }
        else
        {
            for (int j = i + 1; j >= 0; j--)
            {
                z0[i][j] = min(z0[i - 1][j], z1[i - 1][j]);
                z1[i][j] = min(z0[i - 1][j] + y, z1[i - 1][j] + x);
                if (j > 1)
                    z1[i][j] = min({z1[i][j], z0[i - 1][j - 2] + x, z1[i - 1][j - 2] + y});
            }
        }
    }
    cout << z0[n - 1][0] << endl;
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