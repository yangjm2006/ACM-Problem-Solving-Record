#include<bits/stdc++.h>
using namespace std;
int n,m,a[200][200],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(i+j&1){
        a[i][j]=++cnt;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(!(i+j&1)){
        a[i][j]=++cnt;
    }
    bool f=1;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        for(int k=0;k<=3;k++){
            int x=i+dx[k],y=j+dy[k];
            if(x>=1&&x<=n&&y>=1&&y<=m){
                if(abs(a[i][j]-a[x][y])==1) f=0;
            }
        }
    }
    if(f){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) cout<<a[i][j]<<" ";
            cout<<'\n';
        }
    }else cout<<"-1";
    return 0;
}