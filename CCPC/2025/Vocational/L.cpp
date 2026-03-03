#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
ll n,k,b,x[N],y[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    bool cn=1;
    for(int i=1;i<=n;i++) cn&=(x[i]==x[1]);
    if(cn){
        cout<<"NO";
        return 0;
    }
    if(x[1]==x[2]){
        cout<<"YES";
        return 0;
    }
    k=(y[1]-y[2])/(x[1]-x[2]);
    b=y[1]-k*x[1];
    bool f=0;
    for(int i=1;i<=n;i++) if(y[i]!=k*x[i]+b) f=1;
    if(f) cout<<"YES";
    else cout<<"NO";
}