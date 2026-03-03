#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int fa[N],num[N],cnt[N];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int n,m,ans;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fa[i]=i;
        cnt[i]=1;
    }
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        u=find(u);v=find(v);
        if(v!=u){
            if(cnt[v]>cnt[u]){
                cnt[v]+=cnt[u];
                num[v]+=num[u];
                fa[u]=v;
                num[v]++;
            }else{
                cnt[u]+=cnt[v];
                num[u]+=num[v];
                fa[v]=u;
                num[u]++;
            }
        }else num[v]++;
    }
    set<int> st;
    for(int i=1;i<=n;i++) st.insert(find(i));
    for(auto x:st) ans+=num[x]-(cnt[x]-1);
    cout<<ans+int(st.size())-1;
    return 0;
}