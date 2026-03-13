#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
struct edge{
    int v,nxt;
}e[N*25];
int _,head[N+100];
void adde(int u,int v){
    // if(v<=100) cout<<u<<" "<<v<<"++\n";
    e[++_].v=v;e[_].nxt=head[u];head[u]=_;
}
int a[N],num[N+10],ans[N+10],in[N+10];
void topo(){
    queue<int> q;
    q.push(1);ans[1]=num[1];
    while(!q.empty()){
        int u=q.front();q.pop();
        // if(u<=100) cout<<u<<"!!\n";
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;
            in[v]--;
            ans[v]=max(ans[v],ans[u]+num[v]);
            if(!in[v]){
                q.push(v);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        num[a[i]]++;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j*i<=N;j++){
            if(i==i*j) continue;
            in[i*j]++;
            adde(i,i*j);
        }
    }
    topo();
    int maxx=-1;
    for(int i=1;i<=N;i++) maxx=max(maxx,ans[i]);
    // for(int i=1;i<=40;i++) cout<<ans[i]<<" ";cout<<'\n';
    cout<<maxx;
    return 0;
}