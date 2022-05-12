#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        map<int, int> m;
        long long int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;           
            ans = ans + m[x - i];
            m[x - i]++;
        }

        cout << ans << "\n";
    }
    return 0;
}
