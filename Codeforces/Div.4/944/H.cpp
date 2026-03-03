#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
struct edge{
    int v,nxt;
}e[N*6];
int _,head[N];
void adde(int u,int v){
    // cout<<u<<" "<<v<<"++\n";
    e[++_].v=v;e[_].nxt=head[u];head[u]=_;
}
int a[N][5],n;
int trs(int u){
    return abs(u)<<1|(u>0);
}
int dn,dfn[N],low[N],cn,col[N],stc[N],tp;
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
        }while(stc[tp--]!=u);
    }
}
void tarjan(){
    for(int i=2;i<=2*n+1;i++) if(!dfn[i]) dfs(i);
}
void solve(){
    cin>>n;
    _=dn=cn=0;
    for(int i=2;i<=2*n+1;i++) head[i]=dfn[i]=low[i]=col[i]=0;
    for(int j=1;j<=3;j++) for(int i=1;i<=n;i++) cin>>a[i][j];
    for(int i=1;i<=n;i++){
        map<int,int> mp;
        for(int j=1;j<=3;j++){
            if(a[i][j]>0) mp[a[i][j]]++;
            else mp[-a[i][j]]--;
        }
        int cnt=0;
        for(auto &x:mp){
            if(x.second) cnt++;
        }
        if(cnt==1){
            for(auto &x:mp){
                if(x.second>0) adde(trs(-x.first),trs(x.first));
                else if(x.second<0) adde(trs(x.first),trs(-x.first));
            }
        }else if(cnt==2){
            for(auto &x:mp){
                if(x.second>1) adde(trs(-x.first),trs(x.first));
                else if(x.second<-1) adde(trs(x.first),trs(-x.first));
            }
        }else{
            int v[3],res=0;
            for(auto &x:mp){
                v[res]=x.first*x.second;
                res++;
            }
            for(int i=0;i<=2;i++){
                adde(trs(-v[i]),trs(v[(i+1)%3]));
                adde(trs(-v[i]),trs(v[(i+2)%3]));
            }
        }
    }
    tarjan();
    // for(int i=1;i<=n;i++) cout<<col[i<<1]<<" ";cout<<'\n';
    // for(int i=1;i<=n;i++) cout<<col[i<<1|1]<<" ";cout<<'\n';
    for(int i=1;i<=n;i++) if(col[i<<1]==col[i<<1|1]){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}