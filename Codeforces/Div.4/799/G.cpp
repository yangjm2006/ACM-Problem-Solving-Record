#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int T,n,a[N],k;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        vector<int> v;
        v.push_back(0);
        for(int i=2;i<=n;i++)
            if(a[i-1]<a[i]*2){
                v[v.size()-1]++;
            }else{
                v.push_back(0);
            }
        int ans=0;
        for(auto x:v) ans+=max(0,x-k+1);
        cout<<ans<<'\n';
    }
    return 0;
}