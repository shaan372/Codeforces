#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 0 || n % 2050 != 0)
        {
            cout << "-1\n";
            continue;
        }
        ll x = n / 2050;
        ll s = 0;
        ll r;
        while (x != 0)
        {
            r = x % 10;
            s += r;
            x = x / 10;
        }
        cout << s << '\n';
    }
    return 0;
}
