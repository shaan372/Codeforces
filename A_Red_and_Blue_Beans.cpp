#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, d;
        cin >> a >> b >> d;
        if (a > b)
            swap(a, b);
        if (a * (d + 1) >= b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
