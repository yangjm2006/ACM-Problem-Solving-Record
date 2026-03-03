#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
struct edge{
    int v,nxt;
}e[N];
int _,head[N];
void adde(int u,int v){
    e[++_].v=v;e[_].nxt=head[u];head[u]=_;
}
int ans[N],n;
void dfs(int u,int fa){
    int maxx1=0,maxx2=0;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa) continue;
        dfs(v,u);
        if(ans[v]>maxx1){
            maxx2=maxx1;
            maxx1=ans[v];
        }else if(ans[v]>maxx2) maxx2=ans[v];
    }
    ans[u]=max(maxx1,maxx2+1);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1,u,v;i<=n-1;i++){
        cin>>u>>v;
        adde(u,v);adde(v,u);
    }
    dfs(1,0);
    cout<<ans[1];
    return 0;
}