#include<bits/stdc++.h>
using namespace std;
const int N=4e6+9;
struct edge{
	int v,nxt;
}e[N];
int _,head[N];
void adde(int u,int v){
    // cout<<u<<" "<<v<<"++\n";
	e[++_].v=v;
	e[_].nxt=head[u];
	head[u]=_;
}
int n,dn,dfn[N],low[N],cn,col[N],stc[N],tp,sz[N];
bool vis[N];
void dfs(int u){
	dfn[u]=low[u]=++dn;
	stc[++tp]=u;vis[u]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(!dfn[v]) dfs(v);
		if(vis[v]) low[u]=min(low[u],low[v]);
	}
	if(dfn[u]==low[u]){
		cn++;
		do{
			col[stc[tp]]=cn;
			vis[stc[tp]]=0;
			sz[cn]++;
		}while(stc[tp--]!=u);
	}
	return;
}
void tj(){
	for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i);
}
void __(){
    double b;
    cin>>n>>b;
    _=dn=cn=tp=0;
    for(int i=1;i<=n;i++){
        head[i]=dfn[i]=low[i]=stc[i]=col[i]=sz[i]=0;
    }
    for(int i=1;i<=n;i++){
        double maxx=-1000;int id=-1;
        for(int j=1;j<=n;j++){
            double x;
            cin>>x;
            if(i==j||x<b) continue;
            if(x>maxx){
                maxx=x;
                id=j;
            }
        }
        if(id!=-1) adde(i,id);
    }
    if(n==1){
        cout<<"kono jinsei, imi ga nai!\n";
        return;
    }
	tj();
    // for(int i=1;i<=n;i++) cout<<col[i]<<" ";cout<<'\n';
    for(int i=1;i<=cn;i++){
        if(sz[i]<=1){
            cout<<"hbxql\n";
            return;
        }
    }
    cout<<"wish you the best in your search\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
	return 0;
} 