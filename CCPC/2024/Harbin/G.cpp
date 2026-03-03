#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+5;

ll T;
bool b[N],b2[N];
vector<int>G[N];

void solve(){
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;

    int tp;
    for(int i=1;i<=k;i++){
        cin>>tp;
        b2[tp]=1;
    }
    int u,v;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    
    queue<int>q;
    map<int,int>mp;
    vector<vector<int>>as;

    int num = 0;

    for(int i=1;i<=n;i++){
        if(!b2[i]){
            q.push(i);
            b[i]=1;
            num++;
            vector<int>tpx;
            tpx.emplace_back(i);
            as.emplace_back(tpx);
            mp[i]=0;
            break;
        }
    }
    
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int tp:G[x]){
            if(!b[tp]){
                b[tp]=1;
                num++;
                if(mp.find(x)==mp.end()){
                    vector<int>tpx;
                    tpx.emplace_back(x);
                    tpx.emplace_back(tp);
                    as.emplace_back(tpx);
                    mp[x]=as.size()-1;
                }
                else{
                    as[mp[x]].emplace_back(tp);
                }
                if(!b2[tp]){
                    q.push(tp);
                }
            }
        }
    }
    if(num==n){
        cout<<"Yes\n";
        cout<<as.size()<<'\n';
        for(int i=0;i<as.size();i++){
            cout<<as[i][0]<<" "<<as[i].size()-1<<" ";
            for(int j=1;j<as[i].size();j++){
                cout<<as[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    else cout<<"No\n";
}

int main(){
    T=1;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(T--){
        solve();
    }
    return 0;
}