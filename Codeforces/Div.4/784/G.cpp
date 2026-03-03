#include<bits/stdc++.h>
using namespace std;
int T,n,m;
char a[100][100],ans[100][100];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]=='o') ans[i][j]='o';
            else ans[i][j]='.';
        }
        for(int i=1;i<=m;i++) a[n+1][i]='o';
        for(int j=1;j<=m;j++){
            int tmp=0;
            for(int i=1;i<=n+1;i++){
                if(a[i][j]=='*') tmp++;
                else if(a[i][j]=='o'){
                    for(int k=0;k<tmp;k++) ans[i-k-1][j]='*';
                    tmp=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) cout<<ans[i][j];
            cout<<'\n';
        }
    }
    return 0;
}