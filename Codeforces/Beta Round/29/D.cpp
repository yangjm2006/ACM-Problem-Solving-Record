#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100;
struct edge{
    int v,nxt;
}e[N];
int _,head[N];
void adde(int u,int v){
    e[++_].v=v;e[_].nxt=head[u];head[u]=_;
}
int dfn[N],dn,st[20][N],s[N],tot,fat[N],zs[N];
int get(int x,int y){
    return dfn[x]<dfn[y]?x:y;
}
int lca(int u,int v){
    if(u==v) return u;
    u=dfn[u];v=dfn[v];
    if(u>v) swap(u,v);
    u++;
    int k=__lg(v-u+1);
    return get(st[k][u],st[k][v-(1<<k)+1]);
}
void dfs(int u,int fa){
    st[0][dfn[u]=++dn]=fat[u]=fa;
    bool f=0;
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa) continue;
        f=1;zs[u]++;
        dfs(v,u);
    }
    if(!f){
        tot++;
        zs[u]++;
    }
}
void dfs2(int u,int fa){
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa) continue;
        dfs2(v,u);
        s[u]+=s[v];
    }
}
int n,m,a[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1,u,v;i<=n-1;i++){
        cin>>u>>v;
        adde(u,v);adde(v,u);
    }
    dfs(1,-1);
    for(int k=1;k<=__lg(n);k++){
        for(int i=1;i<=n;i++){
            st[k][i]=get(st[k-1][i],st[k-1][i+(1<<k-1)]);
        }
    }
    for(int i=1;i<=tot;i++) cin>>a[i];
    s[a[1]]++;s[a[tot]]++;
    for(int i=1;i<=tot-1;i++){
        int far=lca(a[i],a[i+1]);
        s[fat[far]]-=2;
        s[a[i]]++;s[a[i+1]]++;
    }
    dfs2(1,-1);
    bool f=1;
    for(int i=1;i<=n;i++) if(zs[i]*2!=s[i]) f=0;
    if(!f){
        cout<<"-1";
        return 0;
    }
    vector<int> ans;
    int nw=a[1];
    vector<int> v;
    do{
        v.push_back(nw);
        nw=fat[nw];
    }while(nw!=-1);
    for(int i=v.size()-1;i>=0;i--) ans.push_back(v[i]);
    for(int i=1;i<=tot-1;i++){
        int far=lca(a[i],a[i+1]);
        nw=fat[a[i]];
        do{
            ans.push_back(nw);
            nw=fat[nw];
        }while(nw!=fat[far]);
        nw=a[i+1];
        v.clear();
        do{
            v.push_back(nw);
            nw=fat[nw];
        }while(nw!=fat[far]);
        for(int j=v.size()-1;j>=0;j--) ans.push_back(v[j]);
    }
    nw=fat[a[tot]];
    do{
        ans.push_back(nw);
        nw=fat[nw];
    }while(nw!=-1);
    int lst=-1;
    for(auto x:ans){
        if(lst!=x){
            cout<<x<<" ";
            lst=x;
        }
    }
    return 0;
}