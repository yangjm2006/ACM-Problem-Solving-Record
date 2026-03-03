#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e5+100;
ll f[N],a[N];
void __(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>f[i];
    ll sum=0;
    for(int i=2;i<=n-1;i++){
        a[i]=f[i-1]+f[i+1]-2*f[i];
        a[i]/=2;
        sum+=a[i];
    }
    ll A=(f[1]+f[n])/(n-1)-sum,B=f[1]-f[2]-sum;
    a[1]=(A-B)/2;a[n]=(A+B)/2;
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}