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
int ttt;
void dinic(){
    int res=0,tmp,tot=0;
    while(spfa()&&(tmp=dfs(s,INF))){
        res+=dis[t]*tmp;
        tot+=tmp;
    }
    if(tot!=ttt) cout<<"-1";
    else cout<<res;
}
string str;
int cnt[30],n,m;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>str;
    s=200;t=230;
    for(int i=0;i<str.size();i++){
        cnt[str[i]-'a'+1]++;
    }
    ttt=str.size();
    for(int i=1;i<=26;i++) if(cnt[i]>0) adde(s+i,t,cnt[i],0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str>>m;
        adde(s,i,m,0);
        for(int j=1;j<=26;j++) cnt[j]=0;
        for(int j=0;j<str.size();j++){
            cnt[str[j]-'a'+1]++;
        }
        for(int j=1;j<=26;j++){
            if(cnt[j]>0) adde(i,s+j,cnt[j],i);
        }
    }
    dinic();
}
/*
abacaba
4
aba 11
bcc 1
caa 2
bbb 5
*/