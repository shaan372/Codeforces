#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    long long int t;
    cin>>t;
    while(t--){
        long long int n;
        int c =0;
        cin>>n;
        for(int i =1; i<=9;i++){
            long long int x = i;
            while(x<=n){
                c++;
                x=x*10+i;
            }
        }
        cout<<c<<"\n";      
    }
    return 0;
}
