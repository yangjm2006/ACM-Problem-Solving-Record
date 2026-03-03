#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int INF=1e9;
const int N=1e6+100;
struct edge{
    int v,w,nxt;
}e[N];
int _,head[N];
void adde(int u,int v,int w){
    e[++_].v=v;
    e[_].w=w;
    e[_].nxt=head[u];
    head[u]=_;
}
struct node{
    int dg,id;
    bool operator < (const node &x){
        return dg>x.dg;
    }
}p[N];
int ans[N],n,m,dis[N],st;
void bfs(){
    deque<int> q;
    q.push_back(st);
    dis[st]=0;
    while(!q.empty()){
        int u=q.front();q.pop_front();
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v,w=e[i].w;
            if(dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                if(w==0) q.push_front(v);
                else q.push_back(v);
            }
        }
    }
}
void __(){
    cin>>n>>m;
    _=0;
    st=n+1;
    for(int i=1;i<=st;i++){
        head[i]=p[i].dg=0;
        dis[i]=ans[i]=INF;
        p[i].id=i;
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adde(u,v,1);
        adde(v,u,1);
        p[u].dg++;
        p[v].dg++;
    }
    sort(p+1,p+1+n);
    int i=1;
    for(;;){
        if(i>n) break;
        int D=p[i].dg;
        while(i<=n&&D==p[i].dg){
            int u=p[i].id;
            ans[u]=min(ans[u],dis[u]);
            adde(st,u,0);
            i++;
        }
        bfs();
    }
    for(int i=1;i<=n;i++){
        cout<<(ans[i]==INF?-1:ans[i])<<" ";
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    T=1;
    // cin>>T;
    while(T--) __();
    return 0;
}