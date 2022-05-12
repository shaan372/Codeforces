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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        map<int, vector<int>> m;
        for (int i = 0; i < n; i++)
        {
            m[a[i]].push_back(i + 1);
        }
        int c;
        for (auto i : m)
        {
            if (i.second.size() == 1)
                c = i.second.front();
        }
        cout << c << "\n";
    }
    return 0;
}
