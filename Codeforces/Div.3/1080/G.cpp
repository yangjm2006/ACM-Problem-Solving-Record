#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
struct edge{
    int v,nxt;
}e[N];
int _,head[N];
void adde(int u,int v){
    e[++_].v=v;e[_].nxt=head[u];head[u]=_;
}
ll f[N],ans[N];
void dfs1(int u){
    bool flg=0;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        dfs1(v);
        f[u]+=f[v];
        flg=1;
    }
    if(flg) f[u]+=4;
}
void dfs2(int u){
    ans[u]+=f[u]+1;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        ans[v]+=ans[u];
        dfs2(v);
    }
}
vector<int> euler;
int pos[N],fat[22][N];
void dfs3(int u){
    pos[u]=euler.size();
    euler.push_back(u);
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        fat[0][v]=u;
        dfs3(v);
        euler.push_back(u);
    }
}
void __(){
    int n,q;
    cin>>n>>q;
    _=0;
    euler.clear();
    for(int i=1;i<=n;i++){
        head[i]=f[i]=ans[i]=0;
        pos[i]=-1;
    }
    for(int k=0;k<=20;k++) for(int i=1;i<=n;i++) fat[k][i]=0;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        if(u){
            adde(i,v);
            adde(i,u);
        }
    }
    dfs1(1);
    dfs2(1);
    dfs3(1);
    for(int k=1;k<=20;k++){
        for(int i=1;i<=n;i++){
            fat[k][i]=fat[k-1][fat[k-1][i]];
        }
    }
    ans[0]=-1e18;
    // for(auto u:euler) cout<<u<<" ";cout<<"----\n";
    // for(int i=1;i<=n;i++) cout<<pos[i]<<" ";cout<<"+++\n";
    // for(int k=0;k<=2;k++){
    //     cout<<k<<"-------------------\n";
    //     for(int i=1;i<=n;i++) cout<<fat[k][i]<<" ";cout<<"\n";
    // }
    while(q--){
        int u;ll k;
        cin>>u>>k;
        for(int o=20;o>=0;o--){
            if((ans[u]-ans[fat[o][u]])<=k){
                k-=ans[u]-ans[fat[o][u]];
                u=fat[o][u];
            }
        }
        // cout<<u<<" "<<k<<"!!!!\n";
        // cout<<euler[pos[u]+k]<<'\n';
        cout<<euler[pos[u]+k]<<" ";
    }
    cout<<'\n';
    // for(int i=1;i<=n;i++) cout<<f[i]<<" ";cout<<'\n';
    // for(int i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}