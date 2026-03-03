#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
const int INF=1e9;
struct edge{
    int v,c,nxt;
};
struct graph{
    edge e[N];
    int _=1,head[N],dis[N],cur[N];
    void adde(int u,int v,int c){
        e[++_].v=v;e[_].c=c;e[_].nxt=head[u];head[u]=_;
        e[++_].v=u;e[_].c=0;e[_].nxt=head[v];head[v]=_;
    }
    int S,T;
    bool bfs(){
        for(int i=1;i<=T;i++){
            dis[i]=INF;
            cur[i]=head[i];
        }
        queue<int> q;q.push(S);dis[S]=0;
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
        return dis[T]!=INF;
    }
    int dfs(int u,int flow){
        if(u==T) return flow;
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
    int dinic(int s,int t){
        S=s;T=t;
        int res=0,tmp;
        while(bfs()&&(tmp=dfs(s,INF))) res+=tmp;
        return res;
    }
};
struct network_flow{
    graph g;
    int maxflow(int n,int s,int t,int ss,int tt){
        
    }
}f;
int main(){
    return 0;
}