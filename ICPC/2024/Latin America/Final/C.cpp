#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
const int INF=1e9;
struct edge{
    int v,c,nxt;
}e[N];
int _=1,head[N];
void adde(int u,int v,int c){
    e[++_].v=v;e[_].c=c;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].c=0;e[_].nxt=head[v];head[v]=_;
}
int s,t,dis[N],cur[N];
bool bfs(){
    for(int i=1;i<=t;i++) dis[i]=INF,cur[i]=head[i];
    queue<int> q;q.push(s);dis[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v,c=e[i].c;
            if(c>0&&dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    return dis[t]!=INF;
}
int dfs(int u,int flow){
    if(u==t) return flow;
    int res=0;
    for(int i=cur[u];i&&flow;i=e[i].nxt){
    	cur[u]=i;
        int v=e[i].v,c=e[i].c;
        if(c>0&&dis[v]==dis[u]+1){
            int fw=dfs(v,min(c,flow));
            flow-=fw;res+=fw;
            e[i].c-=fw;e[i^1].c+=fw;
        }
    }
    return res;
}
int n,m,cnt,maxx,ans,max_flow,tot;
void dinic(){
    max_flow=0;int tmp,cnt=0;
    while(bfs()&&(tmp=dfs(s,INF))){
        max_flow+=tmp;
        cnt++;tot++;
    }
}
int id[100][100],idcnt;
bool c[100][100];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1},inv[100][100];
void init(int x,int y){
	for(int i=2;i<=_;i++)
		if(i&1) e[i].c=0;
		else e[i].c=1;
	e[inv[x][y]].c=0;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        char ch;
        cin>>ch;
        if(ch=='.'){
            c[i][j]=1;
            id[i][j]=++idcnt;
        }
    }
    s=idcnt+1;t=idcnt+2;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(c[i][j]){
        inv[i][j]=_+1;
        if(i+j&1) adde(s,id[i][j],1);
        else adde(id[i][j],t,1);
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(c[i][j]){
        if(i+j&1){
            for(int k=0;k<4;k++){
                int tox=i+dx[k],toy=j+dy[k];
                if(tox>=1&&tox<=n&&toy>=1&&toy<=m&&c[tox][toy]){
                    adde(id[i][j],id[tox][toy],1);
                }
            }
        }
    }
    dinic();
    maxx=max_flow;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(c[i][j]){
        init(i,j);
        dinic();
        if(max_flow==maxx) ans++;
    }
    cout<<ans;
    return 0;
}