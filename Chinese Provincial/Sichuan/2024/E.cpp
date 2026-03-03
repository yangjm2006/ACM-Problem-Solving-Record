#include"bits/stdc++.h"
using namespace std;
int T,n,m,s[550][550];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=0;i<=n+1;i++) for(int j=0;j<=m+1;j++) s[i][j]=0;
        bool f=1;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='.'){
                if(i!=1||j!=m) f=0;
            }
            if(i==1&&j==m){
                if(c!='.') f=0;
            }
            if(c=='C') s[i][j]+=4;
            if(c=='L') s[i][j-1]+=1;
            if(c=='R') s[i][j+1]+=1;
            if(c=='U') s[i-1][j]+=2;
            if(c=='D') s[i+1][j]+=2;
        }
        for(int i=0;i<=n+1;i++) for(int j=0;j<=m+1;j++){
            if(s[i][j]!=0&&s[i][j]!=7) f=0;
        }
        if(f) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
/*
 3
 4 4
 CLD.
 UDCL
 DCLD
 CLRC
 2 3
 DRC
 CLU
 4 4
 CLD.
 UDCL
 DCLD
 CLRC
*/