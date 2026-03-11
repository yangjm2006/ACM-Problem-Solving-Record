#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int sz[N],ful[N];
struct edge{
    int v,nxt;
}e[N];
int _,head[N];
void adde(int u,int v){
    e[++_].v=v;e[_].nxt=head[u];head[u]=_;
}
int fa[N];
void dfs(int u){
    sz[u]++;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa[u]) continue;
        dfs(v);
        sz[u]+=sz[v];
    }
}
bool vis[N];
int ans;
void work1(int u){
    if(u==0) return;
    if(vis[u]==0){
        ans++;
        vis[u]=1;
        work1(fa[u]);
    }
}
void work2(int u){
    if(u==0) return;
    if(sz[u]==0){
        ans--;
        sz[fa[u]]-=ful[u];
        if(sz[fa[u]]==0) work2(fa[u]);
    }
}
void __(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        cin>>fa[i];
        adde(i,fa[i]);
        adde(fa[i],i);
    }
    dfs(1);
    for(int i=1;i<=n;i++) ful[i]=sz[i];
    // for(int i=1;i<=n;i++) cout<<sz[i]<<" ";cout<<"____\n";
    for(int o=1;o<=n;o++){
        int x;
        cin>>x;
        work1(x);
        sz[x]--;
        work2(x);
        cout<<ans<<" ";
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    __();
	return 0;
} 