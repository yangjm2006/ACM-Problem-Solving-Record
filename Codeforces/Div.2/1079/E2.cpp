#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> ans;
int w[50],nw[50],lst[50],lennw,lenlst;
vector<int> g[50];
void __(){
    int n;
    cin>>n;
    ans.clear();
    for(int i=1;i<=n;i++){
        w[i]=1;
        g[i].clear();
    }
    int cur=2;
    for(;;){
        cout<<"? "<<cur<<'\n';
        cin>>lennw;
        if(lennw==0) break;
        for(int i=1;i<=lennw;i++) cin>>nw[i];
        for(int i=lennw+1;i<=40;i++) nw[i]=0;
        for(int i=lenlst-1;i>=lennw;i--){
            int u=lst[i];
            for(auto v:g[u]){
                w[u]+=w[v];
            }
        }
        if(lennw>=2){
            g[nw[lennw-1]].push_back(nw[lennw]);
            ans.push_back(make_pair(nw[lennw-1],nw[lennw]));
        }
        lenlst=lennw;
        for(int i=1;i<=40;i++) lst[i]=nw[i];
        cur+=w[nw[lennw]];
    }
    cout<<"! "<<ans.size()<<'\n';
    for(auto &x:ans) cout<<x.first<<" "<<x.second<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}