#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
const int INF=1e9;
struct edge{
    int v,c,w,nxt;
}e[N];
int _=1,head[N];
void adde(int u,int v,int c,int w){
    e[++_].v=v;e[_].c=c;e[_].w=w;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=0;e[_].w=-w;e[_].nxt=head[v];head[v]=_;
}
int s,t,dis[N],cur[N];
bool vis[N];
bool spfa(){
    for(int i=1;i<=t;i++){
        dis[i]=INF;
        cur[i]=head[i];
        vis[i]=0;
    }
    queue<int> q;q.push(s);dis[s]=0;vis[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v,c=e[i].c,w=e[i].w;
            if(c>0&&dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    return dis[t]!=INF;
}
int dfs(int u,int flow){
    if(u==t) return flow;
    int res=0;vis[u]=1;
    for(int i=cur[u];i&&flow;i=e[i].nxt){
        cur[u]=i;
        int v=e[i].v,c=e[i].c,w=e[i].w;
        if(c>0&&vis[v]==0&&dis[v]==dis[u]+w){
            int fw=dfs(v,min(c,flow));
            flow-=fw;res+=fw;
            e[i].c-=fw;e[i^1].c+=fw;
        }
    }
    return res;
}
void dinic(){
    int res=0,tmp;
    while(spfa()&&(tmp=dfs(s,INF))) res+=dis[t]*tmp;
    cout<<-res;
}
int n,k;
set<int> st;
map<int,int> mp;
int main(){
    cin>>n>>k;
    vector<int> l(n+1),r(n+1);
    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
        st.insert(l[i]);st.insert(r[i]);
    }
    int cnt=0;
    for(auto x:st) mp[x]=++cnt;
    for(int i=1;i<=n;i++) adde(mp[l[i]],mp[r[i]],1,-(r[i]-l[i]));
    for(int i=1;i<=cnt-1;i++) adde(i,i+1,k,0);
    s=cnt+1;t=s+1;
    adde(s,1,k,0);adde(cnt,t,k,0);
    dinic();
    return 0;
}