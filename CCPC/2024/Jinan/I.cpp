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
int T,n,de[N],to[N];
vector<pair<int,int> > ans;
void dfs(int u,int fa){
	int cnt=0;vector<int> vec;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa) continue;
		cnt++;
		vec.push_back(v);
		dfs(v,u);
	}
	if(cnt%2){
		to[u]=to[vec[cnt-1]];
	}else to[u]=u;
	for(int i=0;i<cnt-1;i+=2){
		ans.push_back(make_pair(to[vec[i]],to[vec[i+1]]));
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		_=0;
		for(int i=1;i<=n;i++) head[i]=de[i]=0;
		ans.clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			adde(u,v);adde(v,u);
			de[u]++;de[v]++;
		}
		bool cn=0;int root;
		for(int i=1;i<=n;i++){
			if(de[i]%2==0){
				cn=1;
				root=i;
			}
		}
		if(!cn){
			cout<<"-1\n";
			continue;
		} 
		dfs(root,0);
		cout<<ans.size()<<"\n";
		for(int i=0;i<ans.size();i++){
			cout<<ans[i].first<<" "<<ans[i].second<<"\n";
		}
	}
	return 0;
}