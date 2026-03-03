#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=7e6+100;
const ll INF=1e18;
struct edge{
    int v,nxt;
    ll w;
}e[N];
int _,head[N];
void adde(int u,int v,ll w){
    e[++_].v=v;e[_].w=w;e[_].nxt=head[u];head[u]=_;
}
ll dis[N],a[20];
bool vis[N];
void spfa(){
    queue<int> q;
    for(int i=0;i<a[1];i++) dis[i]=INF;
    q.push(0);dis[0]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        vis[u]=0;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;ll w=e[i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
ll cal(ll x){
    ll res=0;
    for(int i=0;i<a[1];i++){
        if(x>=dis[i]) res+=max(0ll,(x-dis[i])/a[1]+1);
    }
    // cout<<x<<" "<<res<<"+++\n";
    return res;
}
int main(){
    ll n,l,r;
    cin>>n>>l>>r;
    set<ll> st;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        if(x) st.insert(x);
    }
    if(st.empty()){
        cout<<0;
        return 0;
    }
    n=0;
    for(auto x:st){
        a[++n]=x;
    }
    for(int i=0;i<a[1];i++){
        for(int j=2;j<=n;j++){
            adde(i,(i+a[j])%a[1],a[j]);
        }
    }
    spfa();
    // for(int i=0;i<a[1];i++) cout<<dis[i]<<" ";cout<<"!!!!!\n";
    cout<<cal(r)-cal(l-1);
    return 0;
}