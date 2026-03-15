#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+100;
const int INF=1e9;
struct edge{
    int v,w,nxt;
}e[N*5];
int _,head[N];
void adde(int u,int v,int w){
    // cout<<u<<" "<<v<<" "<<w<<"++\n";
    e[++_].v=v;e[_].w=w;e[_].nxt=head[u];head[u]=_;
}
ll x[N],y[N];
map<ll,int> mp;
vector<ll> v;
int dis[N],cnt,in[N];
void topo(){
    for(int i=1;i<=cnt;i++) dis[i]=INF;
    dis[0]=0;queue<int> q;q.push(0);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v,w=e[i].w;
            in[v]--;
            dis[v]=min(dis[v],dis[u]+w);
            if(in[v]==0){
                q.push(v);
            }
        }
    }
    for(int i=1;i<=cnt;i++) cout<<dis[i]<<" ";cout<<'\n';
}
int main(){
    // ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        v.push_back(x[i]);
        v.push_back(y[i]);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if(i==0||v[i]!=v[i-1]) mp[v[i]]=++cnt;
    }
    for(int i=1;i<=n;i++){
        if(x[i]<y[i]){
            adde(mp[x[i]],mp[y[i]],-1);
            in[mp[y[i]]]++;
        }else{
            //TODO
        }
    }
    for(int i=0;i<=cnt-1;i++){
        adde(i,i+1,0);
        in[i+1]++;
    }
    topo();
    cout<<-dis[cnt];
    return 0;
}