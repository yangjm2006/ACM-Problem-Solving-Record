#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
bool vis[N];
vector<int> e[N];
int fat[N];
vector<int> vec[N];
void dfs(int u,int fa){
    for(auto v:e[u]){
        if(v==fa) continue;
        fat[v]=u;
        vec[u].push_back(v);
        dfs(v,u);
    }
}
int tim[N];
bool cmp(int x,int y){
    return tim[x]<tim[y];
}
void __(){
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,0);
    vector<int> v;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v.push_back(x);
        tim[x]=i;
    }
    if(v[0]!=1){
        cout<<"No";
        return;
    }
    for(int i=1;i<=n;i++){
        sort(vec[i].begin(),vec[i].end(),cmp);
        // cout<<i<<":";
        // for(auto x:vec[i]) cout<<x<<" ";
        // cout<<"\n";
    }
    queue<int> q;
    q.push(1);
    int cnt=0;
    while(!q.empty()){
        if(q.front()!=v[cnt]){
            cout<<"No";
            return;
        }
        int u=q.front();
        q.pop();
        cnt++;
        for(auto v:vec[u]){
            q.push(v);
        }
    }
    cout<<"Yes";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    __();
    return 0;
}