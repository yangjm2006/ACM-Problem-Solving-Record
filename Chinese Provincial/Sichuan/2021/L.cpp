#include<bits/stdc++.h>
using namespace std;
const int M=4e5;
const int N=2e5;
const int INF=1e9;
struct edge{
	int v,w,nxt;
}e[M];
int _,head[N];
void adde(int u,int v,int w){
	e[++_].v=v;
	e[_].w=w;
	e[_].nxt=head[u];
	head[u]=_;
}
struct node{
	int u,d;
};
deque<node> q;
int d[109][N],dis[N],n,m,p;
bool vis[N];
void bfs(int s){
	for(int i=1;i<=s;i++){
		dis[i]=INF;
		vis[i]=0;
	}
	q.push_front((node){s,0});dis[s]=0;
	while(!q.empty()){
		int u=q.front().u,d=q.front().d;q.pop_front();
		if(vis[u]) continue;vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>d+w){
				dis[v]=d+w;
				if(w==1) q.push_back((node){v,dis[v]});
				else q.push_front((node){v,dis[v]});
			}
		}
	}
	for(int i=1;i<=n;i++) d[s-n][i]=dis[i];
}
vector<int> vc[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>p;
	for(int i=1,w;i<=n;i++){
		cin>>w;
		vc[w].push_back(i);
	}
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		adde(u,v,1);adde(v,u,1);
	}
	for(int i=1;i<=100;i++){
		for(int j=0;j<vc[i].size();j++) adde(i+n,vc[i][j],0);
	}
	for(int i=2;i<=100;i++) adde(i+n,i+n-1,0);
	for(int i=1;i<=100;i++) bfs(i+n);
	for(int i=1,u,t;i<=p;i++){
		cin>>u>>t;
		if(d[t][u]==INF) cout<<"-1\n";
		else cout<<d[t][u]<<'\n'; 
	}
	return 0;
}