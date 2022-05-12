#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        long long int a, b;
        cin>>a>>b;
       if(b==1)
       cout<<"NO\n";
       else if(b==2)
       cout<<"YES\n"<<a<<" "<<a*b<<" "<<a*(b+1)<<"\n";
       else
       cout<<"YES\n"<<a<<" "<<a*(b-1)<<" "<<a*b<<"\n";
    }
    return 0;
}
