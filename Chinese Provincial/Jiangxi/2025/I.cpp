#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
const ll mod=998244353;
const int N=1e6+100;
ll ksm(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
    return ans;
}
ll mul[N],inv[N];
ll C(int n,int m){
    if(m>n) return 0;
    return mul[n]*inv[n-m]%mod*inv[m]%mod;
}
ll n,k,s[N];
string str;
bool vis[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    mul[0]=1;
    for(int i=1;i<N;i++) mul[i]=mul[i-1]*i%mod;
    inv[N-1]=ksm(mul[N-1],mod-2);
    for(int i=N-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
    // cout<<C(6,3)<<" "<<C(6,2)<<"---\n";
    ll T;
    cin>>T;
    while(T--){
        ll ans=0;
        cin>>n>>k;
        cin>>str;
        vis[1]=1;vis[n+2]=1;
        for(int i=1;i<=n;i++) vis[i+1]=str[i-1]-'0';
        n+=2;
        for(int i=1;i<=n;i++) s[i]=0;
        for(int i=1;i<=n;i++) s[i]+=s[i-1]+vis[i];
        for(int i=1;i<=n;i++){
            if(vis[i]){
                int l=1,r=i-1;
                while(l<r){
                    int mid=(l+r>>1)+1;
                    if(s[i]-s[mid-1]>=k+2) l=mid;
                    else r=mid-1;
                }
                if(s[i]-s[l-1]==k+2){
                    // cout<<l<<" "<<i<<"********\n";
                    ans+=C(i-l-1,k);
                    //  cout<<C(i-l-1,k)<<"++\n";
                    ans%=mod;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(vis[i]){
                int l=1,r=i-1;
                while(l<r){
                    int mid=(l+r>>1)+1;
                    if(s[i]-s[mid-1]>=k+1) l=mid;
                    else r=mid-1;
                }
                if(s[i]-s[l-1]==k+1){
                    if(l==1||i==n) continue;
                    // cout<<l<<" "<<i<<"======\n";
                    ans-=C(i-l-1,k-1);
                    // cout<<C(i-l-1,k-1)<<"--\n";
                    ans%=mod;
                }
            }
        }
        cout<<(ans+mod)%mod<<'\n';
    }
    return 0;
}