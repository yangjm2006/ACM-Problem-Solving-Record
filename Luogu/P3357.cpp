#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
const int INF1=1e9;
const ll INF2=1e18;
struct edge{
    int v,c,nxt;ll w;
}e[N];
int _=1,head[N];
void adde(int u,int v,int c,ll w){
    cout<<u<<" "<<v<<" "<<c<<" "<<w<<"+++++++++++++++++\n";
    e[++_].v=v;e[_].c=c;e[_].w=w;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=0;e[_].w=-w;e[_].nxt=head[v];head[v]=_;
}
ll dis[N];
int s,t,cur[N];
bool vis[N];
bool spfa(){
    for(int i=1;i<=t;i++){
        cur[i]=i;
        dis[i]=INF2;
        vis[i]=0;
    }
    queue<int> q;dis[s]=0;q.push(s);vis[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v,c=e[i].c;ll w=e[i].w;
            if(c>0&&dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    for(int i=1;i<=t;i++) cout<<dis[i]<<" ";cout<<'\n';
    return dis[t]!=INF2;
}
int dfs(int u,int flow){
    cout<<u<<" "<<flow<<"++\n";
    if(u==t) return flow;
    int res=0;vis[u]=1;
    for(int i=cur[u];i&&flow;i=e[i].nxt){
        cur[u]=i;
        int v=e[i].v,c=e[i].c;ll w=e[i].w;
        cout<<v<<"!!\n";
        if(c>0&&vis[v]==0&&dis[v]==dis[u]+w){
            int fw=dfs(v,min(flow,c));
            flow-=fw;res+=fw;
            e[i].c-=fw;e[i^1].c+=fw;
        }
    }
    return res;
}
void dinic(){
    ll tmp,res=0;
    while(spfa()&&(tmp=dfs(s,INF1))){
        res+=dis[t]*tmp;
        cout<<tmp<<" "<<dis[t]<<'\n';
    }
    cout<<-res;

}
int n,k;
ll w[N],a[N],b[N];
set<ll> st;
map<ll,int> mp;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        ll c,d;
        cin>>a[i]>>c>>b[i]>>d;
        if(a[i]>b[i]) swap(a[i],b[i]);
        st.insert(a[i]);st.insert(b[i]);
        w[i]=(ll)(sqrt((a[i]-b[i])*(a[i]-b[i])+(c-d)*(c-d)));
    }
    int cn=0;
    for(auto x:st){
        mp[x]=++cn;
    }
    s=cn+1;t=s+1;
    for(int i=1;i<=n;i++){
        adde(mp[a[i]],mp[b[i]],1,-w[i]);
    }
    for(int i=1;i<=cn-1;i++) adde(i,i+1,k,0);
    adde(s,1,k,0);adde(cn,t,k,0);
    dinic();
    return 0;
}