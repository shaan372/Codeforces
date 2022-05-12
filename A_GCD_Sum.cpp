#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll sumofdigit(ll n)
{
    ll s = 0;
    while (n > 0)
    {
        ll r = n % 10;
        s += r;
        n = n / 10;
    }
    return s;
}
ll gcdsum(ll a, ll b)
{
    if (b % a == 0)
        return a;
    else
        return gcdsum(b % a, a);
}
int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        while (true)
        {
            ll x = gcdsum(n, sumofdigit(n));
            if (x > 1)
                break;
            else
                n++;
        }
        cout << n << '\n';
    }

    return 0;
}
