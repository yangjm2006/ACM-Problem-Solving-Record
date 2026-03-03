#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int n;
bool inv(int x,int y){
    if(x==n&&y==1) return 0;
    if(x>y) return 1;
    return 0;
}
int a[N],b[N];
int pos(int x){
    return (x-1)%n+1;
}
bool check(int x){
    for(int i=1;i<=n;i++) if(a[pos(x+i-1)]!=i) return 0;
    return 1;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    map<int,int> mp;
    for(int i=1;i<=n;i++) mp[b[i]]=i;
    for(int i=1;i<=n;i++) a[i]=mp[a[i]];
    // for(int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<"==\n";
    int tmp=1;
    while(!(a[pos(tmp)]==1&&check(tmp))){
        if(inv(a[pos(tmp)],a[pos(tmp+1)])){
            cout<<2;
            swap(a[pos(tmp)],a[pos(tmp+1)]);
        }
        else cout<<1;
        tmp++;
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}