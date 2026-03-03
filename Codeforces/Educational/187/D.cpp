#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+100;
const ll INF=1e9;
ll gcd(ll a,ll b){
    return (b==0)?(a):gcd(b,a%b);
}
int n;
bool vis[N+100];
void __(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n+m;i++) vis[i]=0;
    set<ll> st;
    ll g=1;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        st.insert(x);
        if(g<INF) g=g*x/gcd(g,x);
    }
    for(ll x:st){
        for(int i=1;x*i<=n+m;i++){
            vis[x*i]=1;
        }
    }
    int cnt1=0,cnt2=0,cnt3=0;
    for(int i=1;i<=m;i++){
        ll x;
        cin>>x;
        bool f1=0,f2=0;
        if(vis[x]){
            cnt1++;
            f1=1;
        }
        if(g>=INF){
            cnt2++;
            f2=1;
        }else{
            if(x%g!=0){
                cnt2++;
                f2=1;
            }
        }
        if(f1&&f2) cnt3++;
    }
    // cout<<cnt1<<" "<<cnt2<<" "<<g<<"!!!\n";
    if(cnt3%2==0){
        if(cnt1>cnt2) cout<<"Alice\n";
        else cout<<"Bob\n";
    }else{
        if(cnt1>=cnt2) cout<<"Alice\n";
        else cout<<"Bob\n";
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}