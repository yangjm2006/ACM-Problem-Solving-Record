#include"bits/stdc++.h"
using namespace std;
const int N=2e5+100;
int T,n;
bool vis[3][N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        cin>>n;
        string s;
        cin>>s;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='1') vis[1][i]=1;
            else vis[1][i]=0;
        }
        cin>>s;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='1') vis[2][i]=1;
            else vis[2][i]=0;
        }
        bool f=1;
        for(int i=1;i<=n;i++) f&=(vis[1][i]|vis[2][i]);
        cout<<f<<'\n';
    return 0;
}