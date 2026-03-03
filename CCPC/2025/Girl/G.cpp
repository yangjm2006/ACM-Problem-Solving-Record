#include<bits/stdc++.h>
using namespace std;
const int N=3e5+100;
int n,k,prime[N+1],cnt;
bool ntp[N];
int main(){
    for(int i=2;i<=N;i++){
        if(!ntp[i]) prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]<=N/i;j++){
            ntp[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
    cin>>n>>k;
    if(k-1>cnt||prime[k-1]>n) cout<<"NO";
    else{
        cout<<"YES\n1 ";
        for(int i=1;i<=k-1;i++) cout<<prime[i]<<" ";
    }
    return 0;
}