#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
const int M=1e7;
const ll mod=998244353;
ll ksm(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
    return ans;
}
int n,a[N];
bool notprime[M+100];
int _,prime[M+100],p[M+100];
map<int,int> max1,max2;
void work(int x){
    while(x!=1){
        int pm=p[x],cnt=0;
        while(x%pm==0){
            x/=pm;
            cnt++;
        }
        if(cnt>max1[pm]){
            max2[pm]=max1[pm];
            max1[pm]=cnt;
        }else if(cnt>max2[pm]){
            max2[pm]=cnt;
        }
    }
}
void dne(int x,ll ans){
    while(x!=1){
        int pm=p[x],cnt=0;
        while(x%pm==0){
            x/=pm;
            cnt++;
        }
        if(cnt==max1[pm]){
            ans=ans*ksm(ksm(pm,cnt-max2[pm]),mod-2)%mod;
        }
    }
    cout<<ans<<" ";
}
void __(){
    max1.clear();max2.clear();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        work(a[i]);
    }
    ll ans=1;
    for(auto &x:max1){
        ans=ans*ksm(x.first,x.second)%mod;
        // cout<<x.first<<" "<<x.second<<"++\n";
    }
    for(int i=1;i<=n;i++){
        dne(a[i],ans);
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=2;i<=M;i++){
        if(!notprime[i]){
            prime[++_]=i;
            p[i]=i;
        }
        for(int j=1;j<=_&&prime[j]<=M/i;j++){
            notprime[prime[j]*i]=1;
            p[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}