#include<bits/stdc++.h>
using namespace std;
int h,m,x;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        char ch;
        cin>>h>>ch>>m>>x;
        bool vis[30][100]={0};
        int ans=0;
        while(!vis[h][m]){
            if(h==(m%10*10+m/10)) ans++;
            vis[h][m]=1;
            m+=x;
            h+=m/60;
            m%=60;
            h%=24;
        }
        cout<<ans<<'\n';
    }
    return 0;
}