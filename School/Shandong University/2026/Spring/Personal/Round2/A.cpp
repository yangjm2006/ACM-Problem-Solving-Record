#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
bool vis[N][N];
bool check(int x,int y){
    return vis[x][y]&&vis[x+1][y]&&vis[x][y+1]&&vis[x+1][y+1];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        vis[x][y]=1;
        if(check(x,y)||check(x-1,y)||check(x,y-1)||check(x-1,y-1)){
            cout<<i;
            return 0;
        }
    }
    cout<<"0";
    return 0;
}