#include<bits/stdc++.h>
using namespace std;
struct Int{
    int a[200],len;
    void init(){
        for(int i=0;i<=150;i++) a[i]=0;
    }
    Int operator * (const Int &x) const{
        Int res;res.init();
        for(int i=1;i<=len;i++) for(int j=1;j<=x.len;j++) res.a[i+j-1]+=a[i]*x.a[j];
        for(int i=1;i<=len+x.len-1;i++){
            res.a[i+1]+=res.a[i]/10;
            res.a[i]%=10;
        }
        res.len=len+x.len-1;
        if(res.a[res.len+1]) res.len++;
        return res;
    }
    Int operator * (const int &x) const{
        Int res;res.init();
        for(int i=1;i<=150;i++) res.a[i]=a[i]*x;
        for(int i=1;i<=150;i++){
            res.a[i+1]+=res.a[i]/10;
            res.a[i]%=10;
        }
        // for(int i=1;i<=30;i++) cout<<res.a[i];cout<<'\n';
        return res;
    }
};
void Out(Int x){
    bool f=0;
    for(int i=150;i>=1;i--){
        if(x.a[i]) f=1;
        if(f) cout<<x.a[i];
    }
    cout<<'\n';
}
int n,prime[501],cnt;
bool ntp[501];
int main(){
    cin>>n;
    if(n==2){
        cout<<"-1";
        return 0;
    }
    for(int i=2;i<=500;i++){
        if(!ntp[i]) prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]<=500/i;j++){
            ntp[prime[j]*i]=1;
            if(i%prime[j]==0) continue;
        }
    }
    // for(int i=1;i<=50;i++) cout<<prime[i]<<'\n';
    for(int i=1;i<=n;i++){
        Int ans;ans.init();
        ans.a[1]=1;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            ans=ans*prime[j];
        }
        Out(ans);
    }
    return 0;
}