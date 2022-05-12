#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool issquare(ll p)
{
    ll x = sqrt(p);
    if (x * x == p)
        return true;
    else
        return false;
}
int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int flag = 0;
        for (ll i = 0; i < n; i++)
        {
            if (issquare(a[i]) == false)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
