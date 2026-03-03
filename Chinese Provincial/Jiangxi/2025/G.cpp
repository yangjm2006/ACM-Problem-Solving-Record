#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+100;
const ll INF=1e9+100;
struct edge{
    int u,v;ll w;
}e[M];
ll dis[M][35],n,m,q;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=n;i++) dis[i][0]=1;
    for(int k=1;k<=32;k++){
        for(int i=1;i<=m;i++){
            int u=e[i].u,v=e[i].v;ll w=e[i].w;
            if(dis[v][k-1]>=INF) dis[u][k]=INF;
            else dis[u][k]=max(dis[u][k],dis[v][k-1]*w);
        }
    }
    // for(int i=0;i<=5;i++){
    //     cout<<i<<"::::";
    //     for(int j=1;j<=n;j++) cout<<dis[j][i]<<" ";
    //     cout<<'\n';
    // }
    for(int i=1;i<=q;i++){
        int p;ll x;
        cin>>p>>x;
        // cout<<i<<":\n"; 
        for(int k=0;k<=32;k++) if(dis[p][k]>x){
            cout<<k<<'\n';
            break;
        }
    }
    return 0;
}