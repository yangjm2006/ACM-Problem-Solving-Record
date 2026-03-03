#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
struct edge{
    int v,nxt;
}e[N];
int _,head[N];
void adde(int u,int v){
    e[++_].v=v;e[_].nxt=head[u];head[u]=_;
    e[++_].v=u;e[_].nxt=head[v];head[v]=_;
}
int T,n,cnt[N],ans;
void dfs(int u,int fa){
    for(int i=head[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==fa) continue;
        dfs(v,u);
        cnt[u]+=cnt[v];
    }
    if(cnt[u]==0) ans++;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        _=0;
        for(int i=1;i<=n;i++) head[i]=cnt[i]=0;
        for(int i=2,x;i<=n;i++){
            cin>>x;
            adde(i,x);
        }
        string s;
        cin>>s;
        for(int i=1;i<=n;i++)
            if(s[i-1]=='W') cnt[i]++;
            else cnt[i]--;
        ans=0;
        dfs(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}