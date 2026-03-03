#include<bits/stdc++.h>
using namespace std;
const int N=3e5+100;
int n,a[N];
map<int,int> mp;
void __(){
    cin>>n;
    int ans=-1;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        ans=max(ans,mp[x]=mp[x-1]+1);
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    __();
    return 0;
}