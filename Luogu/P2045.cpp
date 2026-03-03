#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
const int INF=1e9;
struct edge{
	int v,c,w,nxt;
}e[N];
int _=1,head[N];
void adde(int u,int v,int c,int w){
//	cout<<u<<" "<<v<<" "<<c<<" "<<w<<"+++\n";
	e[++_].v=v;e[_].c=c;e[_].w=w;
	e[_].nxt=head[u];head[u]=_;
	e[++_].v=u;e[_].c=0;e[_].w=-w;
	e[_].nxt=head[v];head[v]=_;
}
int dis[N],s=6001,t=6002,tot=6030,n,k,cur[N];
int cal(int x,int y){
	return (x-1)*n+y;
}
bool vis[N];
bool spfa(){
	for(int i=1;i<=tot;i++) dis[i]=INF,vis[i]=0;
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
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[cal(i,j)]<<" ";
//		}
//		cout<<'\n';
//	}
	for(int i=1;i<=tot;i++) cur[i]=head[i];
	return dis[t]!=INF; 
}
int dfs(int u,int flow){
	if(u==t) return flow;
	vis[u]=1;int res=0;
	for(int i=cur[u];i&&flow;i=e[i].nxt){
		cur[u]=i;
		int v=e[i].v,c=e[i].c,w=e[i].w;
		if(c>0&&vis[v]==0&&dis[v]==dis[u]+w){
			int fw=dfs(v,min(flow,c));
			flow-=fw;res+=fw;
			e[i].c-=fw;e[i^1].c+=fw;
		}
	}
	return res;
}
void dinic(){
	int tmp,res=0;
	while(spfa()&&(tmp=dfs(s,INF))) res+=tmp*dis[t];
	cout<<-res;
}
int main(){
	cin>>n>>k;
	adde(s,1,k,0);adde(2*n*n,t,k,0);
	for(int i=1;i<=n;i++){
		for(int j=1,x,u,v;j<=n;j++){
			cin>>x;
			u=cal(i,j);v=u+n*n;
			adde(u,v,1,-x);
			adde(u,v,INF,0);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1,u;j<=n;j++){
			u=cal(i,j)+n*n;
			if(i+1<=n){
				adde(u,cal(i+1,j),k,0);
			}
			if(j+1<=n){
				adde(u,cal(i,j+1),k,0);
			}
		}
	}
	dinic();
	return 0;
}