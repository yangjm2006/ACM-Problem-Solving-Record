#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
ll a[N];
void __(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        for(int j=i-a[i],cnt=1;j>=1&&cnt<=a[i];j-=a[i],cnt++){
            if(a[i]*a[j]==i-j){
                if(a[i]==a[j]) ans2++;
                else ans1++;
            }
        }
        for(int j=i+a[i],cnt=1;j<=n&&cnt<=a[i];j+=a[i],cnt++){
            if(a[i]*a[j]==j-i){
                if(a[i]==a[j]) ans2++;
                else ans1++;
            }
        }
    }
    // cout<<ans1<<" "<<ans2<<"!!\n";
    cout<<ans1+ans2/2<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}