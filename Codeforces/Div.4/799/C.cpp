#include<bits/stdc++.h>
using namespace std;
bool vis[20][20];
int dx[4]={1,1,-1,-1},dy[4]={1,-1,1,-1};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        for(int i=1;i<=8;i++) for(int j=1;j<=8;j++){
            char c;
            cin>>c;
            if(c=='#') vis[i][j]=1;
            else vis[i][j]=0;
        }
        int x,y;
        for(int i=2;i<=7;i++) for(int j=2;j<=7;j++){
            bool vs=1;
            for(int k=0;k<4;k++){
                vs&=vis[i+dx[k]][j+dy[k]];
            }
            if(vs) x=i,y=j;
        }
        cout<<x<<" "<<y<<'\n';
    }
    return 0;
}