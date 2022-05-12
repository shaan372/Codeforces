#include <bits/stdc++.h>

#define ll long long
#define vi vector<ll>
#define gi greater<ll>
#define maxheap priority_queue<ll>
#define minheap priority_queue<ll, vector<ll>, greater<ll>>
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define mp make_pair
#define pii pair<ll, ll>
#define spi set<pii>
#define si set<int>
#define mpci map<char, ll>
#define mpii map<ll, ll>
#define f(i,a,n) for(ll i=a;i<n;i++)
#define fi(i,n,a) for(ll i=n-1;i>=0;i--)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define M 1000000007
#define inf 1e18
#define MOD 998244353
#define nl endl

using namespace std;


/*------------------------------------SOME BASIC FUNCTION--------------------------------------------------*/

ll sumofdigit(ll n){ll s = 0;while (n > 0){ll r = n % 10;s += r;n = n / 10;}return s;}
ll gcd(ll a, ll b){if (b % a == 0){return a;}else{return gcd(b % a, a);}}
ll POW(ll x, ll y){ll ans=1;for(ll i=0;i<y;i++){ans=ans*x;}return ans;}
ll ndigit(ll n){ll s=0;while(n>0){s++;n=n/10;}return s;}
ll arraysum(ll a[], ll n){ll s = 0;f(i, 0, n){s = s + a[i];}return s;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;}//O(sqrt(N))
bool isPrime(int n){if (n <= 1) return false; for (int i = 2; i < n; i++)if (n % i == 0) return false; return true;}


/*---------------------------------------------------------------------------------------------------------------*/


/*-----------------------------------ACTUAL CODE STARTS HERE-----------------------------------------------------*/
bool solve2(ll y1, ll y2, ll r)
{
    if (y2 + r < y1)
        return true;
    return false;
}
bool solve3(ll y1, ll y2, ll r)
{
    if (y1 + r < y2)
        return true;
    return false;
}
ll solve(vi &a)
{
    ll cnt1 = 0;
    ll cnt2 = 0;
    ll x = 9;
    for (ll i = 1; i < 10; i += 2)
    {
        cnt1 += a[i - 1];
        ll r = (10 - i - 1) / 2;
        r++;
        if (solve2(cnt1, cnt2, r) || solve3(cnt1, cnt2, r - 1))
        {
            x = i - 1;
            break;
        }
        cnt2 += a[i];
        r--;
        if (solve2(cnt1, cnt2, r) || solve3(cnt1, cnt2, r))
        {
            x = i;
            break;
        }
    }
    return x + 1;
}

int main(int argc, char const *argv[])
{
    fast_io;
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vi v(10);
        f(i, 0, 10)
        {
            if (s[i] == '?')
            {
                if (i % 2 != 0)
                    v[i] = 0;
                else
                    v[i] = 1;
            }
            else if (s[i] == '1')
                v[i] = 1;
            else
                v[i] = 0;
        }
        vi v2(10);
        for (ll i = 0; i < 10; i++)
        {
            if (s[i] == '?')
            {
                if (i % 2 != 0)
                    v2[i] = 1;
                else
                    v2[i] = 0;
            }
            else if (s[i] == '1')
                v2[i] = 1;
            else
                v2[i] = 0;
        }
        ll ans = min(solve(v), solve(v2));
        cout << ans << nl;
    }
    return 0;
}