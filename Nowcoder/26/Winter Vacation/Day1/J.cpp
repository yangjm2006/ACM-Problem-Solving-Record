#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+100;
struct node{
    ll val;
    int id;
    bool operator < (const node &_) const{
        return val<_.val;
    }
}a[N];
set<int> st[N];
int fa[N];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].val;
        a[i].id=i;
        st[i].clear();
        fa[i]=i;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        if(u>v) swap(u,v);
        st[u].insert(v);
    }
    ll sum=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            int u=min(a[i].id,a[j].id),v=max(a[i].id,a[j].id);
            if(st[u].find(v)==st[u].end()&&find(a[i].id)!=find(a[j].id)){
                sum+=a[i].val+a[j].val;
                // cout<<a[i].id<<" "<<a[j].id<<"++\n";
                fa[fa[a[i].id]]=fa[a[j].id];
            }
        }
        // for(int j=1;j<=n;j++) cout<<find(j)<<" ";cout<<"------\n";
    }
    for(int i=1;i<=n;i++) if(find(i)!=find(1)){
        cout<<"-1\n";
        return;
    }
    cout<<sum<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}