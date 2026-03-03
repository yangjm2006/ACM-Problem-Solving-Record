#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int v[N+1],a[N];
bool cmp(int x,int y){
    if(v[x]==v[y]) return x<y;
    return v[x]<v[y];
}
int pos[N];
bool cmp2(int x,int y){
    return pos[x]<pos[y];
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=i;
    sort(a+1,a+1+n,cmp);
    map<int,int> mp;
    for(int i=1;i<=n;i++) mp[v[a[i]]]++;
    int r=n;
    for(int i=1;i<=n;i++) pos[a[i]]=i*2;
    for(int i=2;i<=n;i++){
        if(mp[v[a[i]]]==1) break;
        if(mp[v[a[r]]]!=1) break;
        if(v[a[i-1]]!=v[a[i]]||v[a[i-1]]!=v[a[i-2]]||v[a[i]]!=v[a[i+1]]) continue;
        pos[a[r]]=(pos[a[i]]+pos[a[i-1]])/2;r--;
        i++;
    }
    sort(a+1,a+1+n,cmp2);
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<'\n';
    // for(int i=1;i<=n;i++) cout<<v[a[i]]<<" ";cout<<"!!!!!\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=1;i<=N;i++){
        for(int j=2;j*j<=i;j++) if(i%j==0) v[i]=j;
        if(v[i]==0) v[i]=i;
    }
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}