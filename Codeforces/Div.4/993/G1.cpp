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
int T,n,in[N],len[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        _=0;
        int ans=2;
        for(int i=1;i<=n;i++) head[i]=in[i]=len[i]=0;
        for(int i=1,v;i<=n;i++){
            cin>>v;
            adde(i,v);in[v]++;
        }
        queue<int> q;
        for(int i=1;i<=n;i++) if(!in[i]){
            q.push(i);
            len[i]=1;
        }
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int i=head[u];i;i=e[i].nxt){
                int v=e[i].v;
                in[v]--;
                len[v]=max(len[u]+1,len[v]);
                if(!in[v]) q.push(v);
            }
        }
        for(int i=1;i<=n;i++) ans=max(ans,len[i]+1);
        cout<<ans<<'\n';
    }
    return 0;
}
/*
6
2
2 1
5
2 3 4 5 1
5
2 1 4 2 3
5
4 1 1 5 4
10
4 3 9 1 6 7 9 10 10 3
2
2 1

*/ 