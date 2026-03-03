#include<bits/stdc++.h>
#define db double
using namespace std;
const int N=1e5+100;
const db eps=1e-6;
const int INF=1e9;
struct edge{
    int v,c,nxt;db w;
}e[N];
int _=1,head[N];
void adde(int u,int v,int c,db w){
    e[++_].v=v;e[_].c=c;e[_].w=w;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=0;e[_].w=-w;e[_].nxt=head[v];head[v]=_;
}
db dis[N];
int s,t,cur[N],flow[N],lst[N],eid[N];
bool vis[N];
bool spfa(){
    for(int i=1;i<=t;i++){
        dis[i]=flow[i]=INF;
        cur[i]=head[i];
        vis[i]=0;
    }
    queue<int> q;q.push(s);dis[s]=0;vis[s]=1;flow[s]=INF;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v,c=e[i].c;db w=e[i].w;
            if(c>0&&dis[v]>dis[u]+w+eps){
                dis[v]=dis[u]+w;
                flow[v]=min(c,flow[u]);
                lst[v]=u;eid[v]=i;
                if(!vis[v]){
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    return abs(dis[t]-INF)>eps;
}
int T,n,x[N],y[N];
void EK(){
    db res=0;int tmp,cnt=0;
    while(spfa()){
        res+=flow[t]*dis[t];
        cnt+=tmp;
        int nw=t;
        while(nw!=s){
            e[eid[nw]].c-=flow[t];e[eid[nw]].c+=flow[t];
            nw=lst[nw];
        }
    }
    if(cnt!=n-1) cout<<"-1";
    else cout<<fixed<<setprecision(10)<<res;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(y[i]>y[j]) adde(i,n+j,1,sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
        }
    }
    s=2*n+1;t=s+1;
    for(int i=1;i<=n;i++) adde(s,i,2,0);
    for(int i=1;i<=n;i++) adde(n+i,t,1,0);
    EK();
    return 0;
}