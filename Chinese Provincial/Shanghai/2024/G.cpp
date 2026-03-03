#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
int n,m,x[20],y[20],dx1[4]={0,0,1,-1},dy1[4]={1,-1,0,0},dx2[8]={1,-1,1,-1,2,2,-2,-2},dy2[8]={2,2,-2,-2,1,-1,1,-1};
ll ans[1050][110][110];
struct node{
    int x,y,S;
};
bool vis[1050][110][110],vs[1050][110][110],done[1050][110][110];
int mp[110][110];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x[i]>>y[i];
        mp[x[i]][y[i]]=i;
    }
    for(int S=0;S<(1<<m);S++){
        for(int i=1;i<=m;i++){
            if((S>>(i-1))&1) vs[S][x[i]][y[i]]=1;
        }
        for(int i=1;i<=m;i++) if((S>>(i-1))&1){
            for(int k=0;k<8;k++) if(x[i]+dx2[k]>=0&&y[i]+dy2[k]>=0&&vs[S][x[i]+dx1[k/2]][y[i]+dy1[k/2]]==0){
                vis[S][x[i]+dx2[k]][y[i]+dy2[k]]=1;
            }
        }
    }
    queue<node> q;
    if(vis[(1<<m)-1][0][0]==0){
        q.push((node){0,0,(1<<m)-1});
        ans[(1<<m)-1][0][0]=1;
    }
    while(!q.empty()){
        int xs=q.front().x,ys=q.front().y,S=q.front().S;q.pop();
        int S2=S;
        if(xs<n){
            if(vis[S][xs+1][ys]==0){   
                if(vs[S][xs+1][ys]==1){
                    S2^=(1<<(mp[xs+1][ys]-1));
                }
                ans[S2][xs+1][ys]+=ans[S][xs][ys];
                ans[S2][xs+1][ys]%=mod;
                if(!done[S2][xs+1][ys]){
                    q.push((node){xs+1,ys,S2});
                    done[S2][xs+1][ys]=1;
                }
            }
        }
        S2=S;
        if(ys<n){
            if(vis[S][xs][ys+1]==0){
                if(vs[S][xs][ys+1]==1){
                    S2^=(1<<(mp[xs][ys+1]-1));
                }
                ans[S2][xs][ys+1]+=ans[S][xs][ys];
                ans[S2][xs][ys+1]%=mod;
                if(!done[S2][xs][ys+1]){
                    q.push((node){xs,ys+1,S2});
                    done[S2][xs][ys+1]=1;
                }
            }
        }
        
    }
    ll tot=0;
    for(int i=0;i<(1<<m);i++){
        tot+=ans[i][n][n];
        tot%=mod;
    }
    cout<<tot<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
/*
2 2
0 1
1 1
*/