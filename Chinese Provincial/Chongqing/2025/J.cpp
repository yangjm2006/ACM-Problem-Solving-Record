#include<bits/stdc++.h>
const int N=1e6+10;
using namespace std;
vector<int> e[N];
int n,a[N],in[N],de[N];
bool vis[N],ans[N];
queue<int> q;
void work(int col){
	for(int i=1;i<=n;i++){
		de[i]=in[i];
		vis[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(de[i]==1&&a[i]==col){
			q.push(i);
			vis[i]=1;
		}
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i];
			de[v]--;
			if(de[v]==1&&a[v]==col){
				q.push(v);
				vis[v]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&a[i]==col) ans[i]=1;
	} 
}
string s;
int mp[300],res;
int main(){
	mp['R']=1;mp['G']=2;mp['B']=3;
	cin>>n>>s;
	for(int i=1;i<=n;i++) a[i]=mp[s[i-1]];
	for(int i=1,u,v;i<=n-1;i++){
		cin>>u>>v;
		e[u].push_back(v);in[v]++;
		e[v].push_back(u);in[u]++;
	}
	for(int i=1;i<=3;i++) work(i);
	for(int i=1;i<=n;i++) if(ans[i]) res++;
	cout<<res;
	return 0;
}