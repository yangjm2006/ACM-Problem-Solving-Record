#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll s[N],n,k;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        ll x;
        scanf("%lld",&x);
        s[i]=s[i-1]+x;
    }
    for(int i=k;i<=n;i++){
        double ans=1.0*(s[i]-s[i-k])/k;
        if(ans>=1024.0) printf("%.7lf MiBps\n",ans/1024.0);
        else printf("%.7lf KiBps\n",ans);
    }
    return 0;
}