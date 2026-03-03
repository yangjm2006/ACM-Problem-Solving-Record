#include<bits/stdc++.h>
using namespace std;
const int N=3e5+100;
int T,n,k,a[N];
bool vis[N],f[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>k;
        a[n+1]=-1;
        for(int i=1;i<=n;i++) vis[i]=f[i]=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        int cnt=0;
        for(int i=n;i>=1;i--){
            if(!vis[a[i]]){
                cnt++;
                vis[a[i]]=1;
            }
        }
        int x;
        int res=0;
        if(cnt==n){
            for(int i=1;i<=k;i++) cout<<a[i]<<" ";
            cout<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++) if((vis[i]==0)&&res<k){
            cout<<i<<" ";
            x=i;
            res++;
        }
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(!f[a[i]]){
                f[a[i]]=1;
                ans.push_back(a[i]);
            }
        }
        if(ans[0]==a[n]) {
            for(int i=1;i<=k-res;i++) cout<<ans[ans.size()-i]<<" ";
        }
        else for(int i=1;i<=k-res;i++){
            cout<<ans[i-1]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}