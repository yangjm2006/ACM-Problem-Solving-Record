#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
struct edge{
    int v,nxt;
}e[N];
int _,head[N];
void adde(int u,int v){
    e[++_].v=v;e[_].nxt=head[u];head[u]=_;
}
vector<int> g[N];
int T,n,in[N],len[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        _=0;
        int ans=2;
        for(int i=1;i<=n;i++){
            head[i]=in[i]=len[i]=0;
            g[i].clear();
        }
        for(int i=1,v;i<=n;i++){
            cin>>v;
            adde(i,v);in[v]++;
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            len[i]++;
            if(!in[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int i=head[u];i;i=e[i].nxt){
                int v=e[i].v;
                len[v]+=len[u];
                in[v]--;
                if(!in[v]) q.push(v);
            }
        }
        for(int i=1;i<=n;i++) if(!in[i]) ans=max(len[i]+2,ans);
        cout<<ans<<'\n';
    }
    return 0;
}