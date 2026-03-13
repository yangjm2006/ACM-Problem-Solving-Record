#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int a[N],num[N],fa[N];
int find(int x){
    return (x==fa[x])?x:(fa[x]=find(fa[x]));
}
bool vis[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k;
    cin>>n>>k;
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]=i;
        num[i]=1;
        fa[i]=i;
    }
    for(int i=1;i<=n;i++){
        if(1ll*a[i]*k>1e9) continue;
        if(mp[a[i]*k]!=0){
            num[find(mp[a[i]*k])]+=num[fa[find(i)]];
            fa[find(i)]=find(mp[a[i]*k]);
        }
    }
    // for(int i=1;i<=n;i++) cout<<find(i)<<" ";cout<<'\n';
    // for(int i=1;i<=n;i++) cout<<num[find(i)]<<" ";cout<<'\n';
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[find(i)]){
            vis[find(i)]=1;
            ans+=num[find(i)]/2+(num[find(i)]&1);
        }
    }
    cout<<ans;
    return 0;
}