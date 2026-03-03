#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll ksm(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
    return ans;
}
ll p[10],dig[20];
int s[20];
ll cal(int x){
    ll ans=1;
    for(int i=1;i<=4;i++){
        ans=ans*dig[x%10]%mod;
        x/=10;
    }
    return ans;
}
void solve(){
    int C;
    cin>>C;
    for(int i=1;i<=7;i++){
        cin>>p[i];
        p[i]=p[i]*ksm(100,mod-2)%mod;
    }
    for(int i=0;i<=9;i++){
        ll res=1;
        for(int j=1;j<=7;j++)
            if(s[i]&(1<<(7-j))) res=res*p[j]%mod;
            else res=res*(1-p[j]+mod)%mod;
        dig[i]=res;
    }
    // for(int i=0;i<=9;i++) cout<<dig[i]<<" ";cout<<"!!!!!!!!\n";
    ll ans=0;
    for(int i=0;i<=C;i++){
        ans+=cal(i)*cal(C-i)%mod;
        ans%=mod;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    s[0]=0b1110111;
    s[1]=0b0010010;
    s[2]=0b1011101;
    s[3]=0b1011011;
    s[4]=0b0111010;
    s[5]=0b1101011;
    s[6]=0b1101111;
    s[7]=0b1010010;
    s[8]=0b1111111;
    s[9]=0b1111011;
    // for(int i=0;i<=9;i++) cout<<s[i]<<"++\n";
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}