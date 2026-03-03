#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
int T,n,a[N],prime[N],cnt;
bool ntp[N];
map<int,int> mp1,mp2,mp3;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=2;i<=1000000;i++){
        if(!ntp[i]) prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]<=1000000/i;j++){
            ntp[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
    // for(int i=1;i<=100;i++) cout<<prime[i]<<" ";cout<<"====\n";
    cin>>T;
    while(T--){
        mp1.clear();mp2.clear();mp3.clear();ll ans=0,num=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            if(!ntp[a[i]]){
                ans+=num-mp1[a[i]]+mp3[a[i]];
                mp1[a[i]]++;num++;
            }else{
                bool f=0;
                for(int j=1;j<=cnt&&prime[j]<=a[i]/prime[j];j++){
                    if(a[i]%prime[j]==0&&ntp[a[i]/prime[j]]==0){
                        f=1;
                        ans+=mp1[prime[j]];
                        mp3[prime[j]]++;
                        if(prime[j]*prime[j]!=a[i]){
                            ans+=mp1[a[i]/prime[j]];
                            mp3[a[i]/prime[j]]++;
                        }
                        break;
                    }
                }
                if(f){
                    mp2[a[i]]++;
                    ans+=mp2[a[i]];
                }
            }
            // cout<<a[i]<<" "<<ans<<"++\n";
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
4
4
2 2 3 4
6
2 2 3 4 5 6
9
2 2 4 5 7 8 9 3 5
11
2 2 4 5 7 8 9 3 5 6 2
*/