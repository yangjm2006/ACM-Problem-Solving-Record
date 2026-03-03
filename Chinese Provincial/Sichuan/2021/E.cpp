#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
struct edge{
	int v,nxt;
}e[N];
int _,head[N];
void adde(int u,int v){
	e[++_].v=v;
	e[_].nxt=head[u];
	head[u]=_;
}
int T,n,m,ans,dex;
void dfs(int u){
//	cout<<u<<'\n';
	if(dex>n) return;
	if(u==dex) dex++;
	vector<int> vec;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v<dex) continue;
		vec.push_back(v);
	}
	sort(vec.begin(),vec.end());
	int maxx=-1;
	for(int i=0;i<vec.size();i++){
		int v=vec[i];
//		cout<<u<<" "<<v<<"+++++++++++++++\n";
//		maxx=max(maxx,v); 
		while(dex<v){
			ans++;
			dfs(dex);
		}
		dfs(v);
	}
	while(u==1&&dex<=n){
		ans++;
		dfs(dex);
	}
//	cout<<u<<" "<<ans<<"-----------\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m;
		_=ans=0;
		for(int i=1;i<=n;i++) head[i]=0;
		for(int i=1,u,v;i<=m;i++){
			cin>>u>>v;
			adde(u,v);adde(v,u);
		}
		dex=1;dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}