#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
bool ans[N];
int T,n,m,k,maxx,minn;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        maxx=max(n,m);minn=min(n,m);
        if(k>maxx||k<maxx-minn){
            cout<<"-1\n";
            continue;
        }
        for(int i=1;i<=n+m;i++) ans[i]=0;
        if(n>=m){
            for(int i=1;i<=k;i++) ans[i]=1;
            for(int i=k+1;i<=n;i++) ans[k+(i-k)*2]=1;
            for(int i=1;i<=n+m;i++) cout<<(ans[i]^1);
        }else{
            for(int i=1;i<=k;i++) ans[i]=1;
            for(int i=k+1;i<=m;i++) ans[k+(i-k)*2]=1;
            for(int i=1;i<=n+m;i++) cout<<ans[i];
        }
        cout<<'\n';
    }
    return 0;
}