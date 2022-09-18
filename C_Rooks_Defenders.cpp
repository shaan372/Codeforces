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

void build(ll i, ll l, ll r, vector<ll> &seg, vector<ll> &v)
{
    if (l == r)
    {
        seg[i] = v[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(2 * i + 1, l, mid, seg, v);
    build(2 * i + 2, mid + 1, r, seg, v);
    seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
}
void update(ll i, ll l, ll r, vector<ll> &seg, ll ind, ll val)
{
    if (l == r)
    {
        if (l == ind)
            seg[i] = val;
        return;
    }
    if (ind < l || ind > r)
        return;
    ll mid = (l + r) >> 1;
    update(2 * i + 1, l, mid, seg, ind, val);
    update(2 * i + 2, mid + 1, r, seg, ind, val);
    seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
}
ll query(ll i, ll l, ll r, vector<ll> &seg, ll low, ll high)
{
    if (l >= low && r <= high)
        return seg[i];
    if (r < low || l > high)
        return 0;
    ll mid = (l + r) >> 1;
    ll left = query(2 * i + 1, l, mid, seg, low, high);
    ll right = query(2 * i + 2, mid + 1, r, seg, low, high);
    ll ans = left + right;
    return ans;
}
void run_case()
{
    ll n, q;
    cin >> n >> q;
    map<ll, ll> row, col;
    vector<ll> l(n, 1), h(n, 1);
    vector<ll> r(4 * n + 1, 0), c(4 * n + 1, 0);
    build(0, 0, n - 1, r, l);
    build(0, 0, n - 1, c, h);
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            row[x]++;
            col[y]++;
            update(0, 0, n - 1, r, x, 0);
            update(0, 0, n - 1, c, y, 0);
        }
        else if (t == 2)
        {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            row[x]--;
            col[y]--;
            if (row[x] == 0)
                update(0, 0, n - 1, r, x, 1);
            if (col[y] == 0)
                update(0, 0, n - 1, c, y, 1);
        }
        else
        {
            ll x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            ll temp1 = query(0, 0, n - 1, r, min(x1, x2) - 1, max(x1, x2) - 1);
            ll temp2 = query(0, 0, n - 1, c, min(y1, y2) - 1, max(y1, y2) - 1);
            if (temp1 == 0 || temp2 == 0)
                cout << "Yes" << nl;
            else
                cout << "No" << nl;
        }
    }
}

int main(int argc, char const *argv[])
{
    fast_io;
    fast_io2;
    ll t = 1;
    // cin >> t;
    while (t--)
        run_case();
    return 0;
}