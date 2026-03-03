#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int T,n,a[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int l=1,r=n+1,ans=0,s1=0,s2=0;
        s1+=a[1];
        while(l<r-1){
            while(r>l+1&&s2<s1){
                r--;
                s2+=a[r];
            }
            if(s1==s2){
                ans=l+(n-r+1);
                r--;
                s2+=a[r];
            }
            while(l<r-1&&s1<s2){
                l++;
                s1+=a[l];
            }
            if(s1==s2){
                ans=l+(n-r+1);
                l++;
                s1+=a[l];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}