#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int fa[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
struct edge{
	int u,v,id;ll w;
	bool operator < (const edge &x) const{
		return w<x.w;
	}
}e[N];
int T,n,m,k;
void kruskal(){
	vector<edge> ans;
	for(int i=1;i<=n;i++) fa[i]=i; 
	ll res=0;int cnt=0,ad=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)!=find(v)){
			ans.push_back(e[i]);
			cnt++;
			fa[fa[u]]=fa[v];
		}
	}
	for(int i=cnt-1;i>=max(0,cnt-k);i--){
		if(ans[i].w>1){
			ad++;
			res++;
		}
	}
	cout<<ad<<" "<<'\n';
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=0;i<cnt-ad;i++){
		res+=ans[i].w;
		fa[find(ans[i].u)]=find(ans[i].v);
	}
	for(int i=1;i<=n-1;i++){
		if(find(i)!=find(i+1)){
			cout<<i<<" "<<i+1<<'\n';
			fa[fa[i]]=fa[i+1];
		}
	}
	cout<<res<<'\n';
	for(int i=0;i<cnt-ad;i++) cout<<ans[i].id<<" ";
	for(int i=m+1;i<=m+ad;i++) cout<<i<<" ";
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++){
			cin>>e[i].u>>e[i].v>>e[i].w;
			e[i].id=i;
		}
		sort(e+1,e+1+m);
		kruskal();
	}
	return 0;
}
