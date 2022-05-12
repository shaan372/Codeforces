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
#define prDouble(x,y) cout << fixed << setprecision(y) << x
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fast_io2 cin.exceptions(cin.failbit);
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
int binExpo(int a, int b){ if(b==0) return 1;if(b==1) return a; int r = binExpo(a, b/2); if(b%2==0) return (r%M * r%M)%M; else return (r%M*r%M*a%M)%M;}
int fast_mul(int x, int y){if (x == 0) return 0; else if (x % 2 == 1) return (fast_mul(x >> 1, y << 1) + y); else return fast_mul(x >> 1, y << 1);}


/*---------------------------------------------------------------------------------------------------------------*/


/*-----------------------------------ACTUAL CODE STARTS HERE-----------------------------------------------------*/

ll func(vector<ll> &v, vector<ll> &a)
{
    ll n = v.size();
    vector<ll> odd, even;
    for (ll i = 0; i < n; i++)
    {
        if (v[i] != a[i])
        {
            if (a[i] == 0)
                even.pb(i);
            else
                odd.pb(i);
        }
    }
    sort(all(odd));
    sort(all(even));
    ll m = odd.size();
    ll ans = 0;
    for (ll i = 0; i < m; i++)
        ans += abs(odd[i] - even[i]);
    return ans;
}

int main(int argc, char const *argv[])
{
    fast_io;
    fast_io2;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        ll o = 0, e = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            v[i] = v[i] % 2;
            if (v[i] == 0)
                e++;
            else
                o++;
        }
        if (n == 1)
        {
            cout << "0" << nl;
            continue;
        }
        if (abs(o - e) > 1)
        {
            cout << "-1" << nl;
            continue;
        }
        vector<ll> a(n);
        if (o == e)
        {
            vector<ll> a(n), b(n);
            ll x = 0;
            for (ll i = 0; i < n; i++)
            {
                a[i] = x;
                x ^= 1;
            }
            for (ll i = 0; i < n; i++)
                b[i] = a[i] ^ 1;
            ll ans = min(func(v, a), func(v, b));
            cout << ans << nl;
            continue;
        }
        if (e > o)
        {
            vector<ll> a(n);
            ll x = 0;
            for (ll i = 0; i < n; i++)
            {
                a[i] = x;
                x ^= 1;
            }
            ll ans = func(v, a);
            cout << ans << nl;
            continue;
        }
        if (o > e)
        {
            vector<ll> a(n);
            ll x = 1;
            for (ll i = 0; i < n; i++)
            {
                a[i] = x;
                x ^= 1;
            }
            ll ans = func(v, a);
            cout << ans << nl;
            continue;
        }
    }
    return 0;
}