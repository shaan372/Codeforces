#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << "1\n";
        }
        else if (n == 2)
        {
            cout << "-1\n";
        }
        else
        {
            int x = 1;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << x << " ";
                    x += 2;
                    if (x > n * n)
                    {
                        x = 2;
                    }
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
