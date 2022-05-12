#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    long long int t;
    cin >> t;
    while (t--)
    {

       long long int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long int s = 0;
        for (int i = 0; i < n; i++)
        {
            s = s + a[i];
        }
        if (s == x)
        {
            cout << "NO\n";
            continue;
        }
         s = 0;
        for (long long int i = 0; i < n - 1; i++)
        {
            if (s + a[i] == x){
                swap(a[i], a[i + 1]);
                break;
                }
            else
                s = s + a[i];
        }
        cout<<"YES\n";
        for(long long int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
