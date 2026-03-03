#include<bits/stdc++.h>
using namespace std;
const int N=4e5+100;
int a[N];
bool vis[N];
void __(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[i]=0;
    }
    int ans=0;
    for(int i=2;i<=n;i++){
        if((a[i]+a[i-1]==7||a[i]==a[i-1])&&vis[i-1]==0){
            ans++;
            vis[i]=1;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}