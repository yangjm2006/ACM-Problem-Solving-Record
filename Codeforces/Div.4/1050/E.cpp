#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int a[N],cnt[N],num[N],T,n,k;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        long long ans=0;
        for(int i=1;i<=n;i++) cnt[i]=num[i]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            num[a[i]]++;
        }
        bool f=1;
        for(int i=1;i<=n;i++)
            if(num[i]%k){
                f=0;
            }
            else num[i]/=k;
        if(!f){
            cout<<0<<'\n';
            continue;
        }
        for(int l=1,r=0;l<=n;){
            while(r<n&&1+cnt[a[r+1]]<=num[a[r+1]]){
                r++;
                cnt[a[r]]++;
            }
            ans+=r-l+1;
            cnt[a[l]]--;l++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}