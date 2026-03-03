#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    int x,y;
}c[15];
void solve(){
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>c[i].x>>c[i].y;
    }
    for(int S=0;S<(1<<k);S++){
        bool vis[20];
        for(int i=1;i<=k;i++)
            if((S>>(i-1))&1) vis[i]=1;
            else vis[i]=0;
        int l=1,r=n,ans=m-1;
        bool f=0;
        for(int i=1;i<=k;i++){
            if(!vis[i]){
                int R=c[i].x-1;
                if(l<=R) r=min(r,R);
                else{
                    ans+=abs(R-l);
                    l=r=R;
                }
            }else{
                int L=c[i].x+1;
                if(r>=L) l=max(l,L);
                else{
                    ans+=abs(L-r);
                    l=r=L;
                }
            }
            if(i>=2&&c[i].y==c[i-1].y+1){
                if(vis[i]^vis[i-1]){
                    if(vis[i]){
                        if(c[i-1].x<=c[i].x+1) f=1;
                    }else{
                        if(c[i-1].x>=c[i].x-1) f=1;
                    }
                }
            }
            if(l==0||l==n+1||r==0||r==n+1) f=1;
        }
        if(f) cout<<"-1 ";
        else cout<<ans<<" ";
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
}
/*
1
75 38
10
36 4
63 6
42 7
60 11
4 16
57 20
24 21
19 23
56 29
20 32
*/