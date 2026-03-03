#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+100;
const int M=1e6+100;
int fa[N];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
struct edge{
    int u,v;ll w;
    bool operator < (edge & x) const{
        return w<x.w;
    }
}e[M];
int _,head[N];
void adde(int u,int v,ll w){
    e[++_].u=u;e[_].v=v;e[_].w=w;
}
ll T,n,a[N],b[N][N],cnt,ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        _=cnt=ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) fa[i]=i;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>b[i][j];
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) adde(i,j,b[i][j]);
        sort(e+1,e+1+_);
        for(int i=1;i<=_;i++){
            int fu=find(e[i].u),fv=find(e[i].v);ll w=e[i].w;
            if(fu==fv) continue;
            fa[fv]=fu;
            ans+=w;
            cnt++;
            if(cnt==n-1) break;
        }
        for(int i=1;i<=n;i++){
            ll minn=b[i][1];
            for(int j=2;j<=n;j++) minn=min(minn,b[i][j]);
            ans+=minn*(a[i]-1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}