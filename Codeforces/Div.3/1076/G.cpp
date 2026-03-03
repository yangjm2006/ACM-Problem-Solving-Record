#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n;
vector<int> g[N],d;
void dfs(int u,int fa){
    d.push_back(u);
    for(auto v:g[u]){
        if(v==fa) continue;
        dfs(v,u);
    }
}
void solve(){
    cin>>n;
    d.clear();
    for(int i=1;i<=n;i++){
        g[i].clear();
    }
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=0;i<d.size();i++){
        if(i&1){
            cout<<"? "<<d[i]<<" "<<d[i-1]<<'\n';
            cout.flush();
            bool flg;
            cin>>flg;
            if(flg){
                cout<<"? "<<d[i]<<" "<<d[i]<<'\n';
                cout.flush();
                cin>>flg;
                if(flg) cout<<"! "<<d[i]<<'\n';
                else cout<<"! "<<d[i-1]<<'\n';
                cout.flush();
                return;
            }
        }
    }
    cout<<"! "<<d[d.size()-1]<<"\n";
    cout.flush();
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
/*
1
6
4 1
4 2
4 6
6 5
3 4
*/