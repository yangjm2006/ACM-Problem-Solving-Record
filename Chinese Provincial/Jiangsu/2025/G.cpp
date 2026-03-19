#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
int dp[N+100],a[N+100];
int n,q;
int work(int x){
    int l=1,r=n-1;
    while(l<r){
        int mid=(l+r>>1)+1;
        if(a[mid]<=x) l=mid;
        else r=mid-1;
    }
    // cout<<x<<" "<<a[l]<<"!!!\n";
    return x/a[l]+dp[x%a[l]];
}
ll sum[N+100];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<=N;i++) dp[i]=-1;
    dp[0]=0;sum[0]=1;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1){
        for(int i=1;i<=q;i++) cout<<"1 ";
        return 0;
    }
    for(int i=1;i<=a[n]-1;i++){
        dp[i]=work(i);
        sum[dp[i]]++;
    }
    // for(int i=0;i<a[n];i++) cout<<dp[i]<<" ";cout<<'\n';
    for(int i=1;i<=N;i++){
        sum[i]+=sum[i-1];
    }
    // for(int i=0;i<7;i++) cout<<sum[i]<<" ";cout<<"\n";
    while(q--){
        int x;
        cin>>x;
        cout<<sum[min(N,x)]<<' ';
    }
    return 0;
}