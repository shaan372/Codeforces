#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
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
#define prDouble(x,y) cout << fixed << setprecision(y) << x
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fast_io2 cin.exceptions(cin.failbit);
#define M 1000000007
#define inf 9223372036854775807
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
int binExpo(int a, int b){ if(b==0) return 1;if(b==1) return a; int r = binExpo(a, b/2); if(b%2==0) return (r%M * r%M)%M; else return (r%M*r%M*a%M)%M;}
int fast_mul(int x, int y){if (x == 0) return 0; else if (x % 2 == 1) return (fast_mul(x >> 1, y << 1) + y); else return fast_mul(x >> 1, y << 1);}
vector<ll> sieve(ll n){vector<bool> is_prime(n + 1, true);is_prime[0] = is_prime[1] = false;for (ll i = 2; i <= n; i++){if (is_prime[i] && i * i <= n){for (int j = i * i; j <= n; j += i)is_prime[j] = false;}}vector<ll> ans;for (ll i = 0; i <= n; i++){if (is_prime[i])ans.pb(i);}return ans;}


/*---------------------------------------------------------------------------------------------------------------*/


/*-----------------------------------ACTUAL CODE STARTS HERE-----------------------------------------------------*/

int main(int argc, char const *argv[])
{
    fast_io;
    fast_io2;
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    vector<ll> pre(n), suff(n);
    pre[0] = 0;
    for (ll i = 1; i < n; i++)
        pre[i] = pre[i - 1] + max(0 * 1ll, v[i - 1] - v[i]);
    suff[n - 1] = 0;
    for (ll i = n - 2; i >= 0; i--)
        suff[i] = suff[i + 1] + max(0 * 1ll, v[i + 1] - v[i]);
    while (q--)
    {
        ll s, t;
        cin >> s >> t;
        ll ans;
        if (s <= t)
            ans = pre[t - 1] - pre[s - 1];
        else
            ans = suff[t - 1] - suff[s - 1];
        cout << ans << nl;
    }
    return 0;
}
