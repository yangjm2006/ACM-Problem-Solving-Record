#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
string s[200];
int T,n,m,ans;
void work(int x,int y){
    int res=0;
    for(int i=0;i<m;i++) res+=abs(s[x][i]-s[y][i]);
    ans=min(ans,res);
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>s[i];
        ans=INF;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) work(i,j);
        cout<<ans<<'\n';
    }
    return 0;
}