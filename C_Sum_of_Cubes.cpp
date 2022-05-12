#include <bits/stdc++.h>
using namespace std;
bool cube(long long f)
{
    long long y = cbrt(f);
    if (y * y * y == f)
    {
        return true;
    }
    return false;
}
void solve()
{
    long long x;
    cin >> x;
    if (x == 1)
    {
        cout << "NO\n";
        return;
    }
    long long b = 10000;
    for (long long a = 1; a < 10000; a++)
    {
        while (a * a * a + b * b * b > x)
        {

            b--;
        }
        if (b > 0 && a * a * a + b * b * b == x)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
