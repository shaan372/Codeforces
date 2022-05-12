#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll x = 1;
        while (true)
        {
            if (x * 2 > n)
                break;
            else
                x *= 2;
        }
        cout << x - 1 << "\n";
    }
    return 0;
}
