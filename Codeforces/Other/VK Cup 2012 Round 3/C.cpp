#include<bits/stdc++.h>
using namespace std;
const int INF=2e9;
const int N=1e6+100;
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
        vis[i]=0;
        cur[i]=head[i];
        dis[i]=INF;
    }
    queue<int> q;dis[s]=0;q.push(s);vis[s]=1;
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
    for(int i=cur[u];i;i=e[i].nxt){
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
    int tmp;
    while(spfa()&&(tmp=dfs(s,INF)));
}
int k,m;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m>>k;
    vector<int> v1(m),v2(m),v3(m);
    set<int> st;map<int,int> mp;
    for(int i=0;i<m;i++){
        cin>>v1[i]>>v2[i]>>v3[i];
        st.insert(v1[i]);
        st.insert(v1[i]+v2[i]);
    }
    int cnt=0;
    for(auto x:st){
        mp[x]=++cnt;
    }
    for(int i=0;i<m;i++){
        adde(mp[v1[i]],mp[v1[i]+v2[i]],1,-v3[i]);
    }
    s=cnt+1;t=s+1;
    for(int i=1;i<=cnt-1;i++){
        adde(i,i+1,k,0);
    }
    adde(s,1,k,0);adde(cnt,t,k,0);
    dinic();
    for(int i=1;i<=m;i++) cout<<(e[i*2].c==0)<<" ";
    return 0;
}