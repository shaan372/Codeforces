#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c = 0;
        int a[55];
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] != i + 1)
            {
                c++;
            }
        }
        if (c == 0)
            cout << 0 << "\n";
        else if (a[0] == 1 || a[n - 1] == n)
            cout << 1 << "\n";
        else if (a[0] == n && a[n - 1] == 1)
            cout << 3 << "\n";
        else
            cout << 2 << "\n";
    }
    return 0;
}