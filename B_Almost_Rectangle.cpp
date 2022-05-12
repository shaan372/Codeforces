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
        char a[500][500];
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == '*')
                    p.emplace_back(i, j);
            }
        }

        if (p[0].first == p[1].first)
        {
            if (p[0].first == 0)
            {
                p[0].first++;
                p[1].first++;
            }
            else
            {
                p[0].first--;
                p[1].first--;
            }
        }
        else if (p[0].second == p[1].second)
        {
            if (p[0].second == 0)
            {
                p[0].second++;
                p[1].second++;
            }
            else
            {
                p[0].second--;
                p[1].second--;
            }
        }
        else
        {
            swap(p[0].second, p[1].second);
        }
        a[p[0].first][p[0].second] = '*';
        a[p[1].first][p[1].second] = '*';
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j];
            }
            cout << "\n";
        }
        }

    return 0;
}
