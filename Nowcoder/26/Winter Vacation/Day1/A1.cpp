#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,mod=998244353;
typedef long long ll;
typedef pair<ll,ll> PII;
typedef array<ll,2> a2;
typedef array<ll,3> a3;
int n,m,k;
int a[N];
string s[10]={"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"};
ll p[N],pp[N];
ll ny100;


ll ksm(ll x,ll p){
    ll sum=1,item=x;
    while(p){
        if(p&1) sum=sum*item%mod;
        p>>=1;
        item=item*item%mod;
    }
    return sum;
}


ll cal(ll x){
    ll sum=1;
    for(int i=1;i<=4;i++){
        int t=x%10;
        sum=sum*p[t]%mod;
        x/=10;
    }
    return sum;
}

void __(){
    
    cin>>n;
    for(int i=0;i<7;i++) cin>>pp[i];
    for(int i=0;i<10;i++){
        ll prob=1;
        for(int j=0;j<7;j++){
            if(s[i][j]=='1'){
                prob=prob*pp[j]%mod*ny100%mod;
            }else prob=prob*(100-pp[j])%mod*ny100%mod;
        }
        p[i]=prob;
    }
    for(int i=0;i<=9;i++) cout<<p[i]<<" ";cout<<"!!!!!!\n";
    ll sum=0;
    for(int i=0;i<=n;i++){
        ll x=i,y=n-i;
        ll res=cal(x)*cal(y)%mod;
        sum=(sum+res)%mod;
    }
    cout<<sum<<"\n";

}


int main(){
    ny100=ksm(100,mod-2);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _=1;
    cin>>_;
    while(_--){
        __();
    }
}
