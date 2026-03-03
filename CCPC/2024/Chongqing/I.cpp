#include"bits/stdc++.h"
#define ll long long
using namespace std;
const ll mod=998244353;
ll ksm(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
    return ans;
}
ll a[20],T,ans; 

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        for(int i=1;i<=9;i++) cin>>a[i];
        ans=1;
        bool flag = 0;
        a[10] = 0;
        if(a[1]==1&&a[2]==0){
            a[1]=0;
            flag = 1;
            for(int i=3;i<=9;i++){
                if(a[i]>0){
                    a[i]--;
                    a[i+1]++;
                    break;
                }
            }
        }
        
        for(int i=3;i<=10;i++) {
            ans=ans*ksm(i,a[i])%mod;
        }
        if(flag){
            cout<<ans<<'\n';
            continue;
        }
        if(a[1]<=a[2]){
            ans=ans*ksm(3,a[1])%mod;
            ans=ans*ksm(2,a[2]-a[1])%mod;
        }else{
            if(a[2]==0){
                int tmp = a[1]%6;
                int cnt2=0,cnt3=0;
                cnt3 = (a[1]-tmp)/3;
                if(tmp==1){
                    cnt3--;
                    cnt2+=2;
                }
                else if(tmp==2){
                    cnt2++;
                }
                else if(tmp==4){
                    cnt2+=2;
                }
                else if(tmp==3){
                    cnt3++;
                }
                else if(tmp==5){
                    cnt2++;
                    cnt3++;
                }
                ans = ans*ksm(2,cnt2)%mod;
                ans = ans*ksm(3,cnt3)%mod;
            }else{
                if(a[1]-a[2]==1){
                int cnt2=2,cnt3=a[2]-1;
                a[1]-=a[2]-1;
                ans = ans*ksm(2,cnt2)%mod;
                ans = ans*ksm(3,cnt3)%mod;
                }
                else{
                int cnt2=0,cnt3=a[2];
                a[1]-=a[2];
                int tmp = a[1]%6;
                cnt3 += (a[1]-tmp)/3;
                if(tmp==1){
                    cnt3--;
                    cnt2+=2;
                }
                else if(tmp==2){
                    cnt2++;
                }
                else if(tmp==4){
                    cnt2+=2;
                }
                else if(tmp==3){
                    cnt3++;
                }
                else if(tmp==5){
                    cnt2++;
                    cnt3++;
                }
                ans = ans*ksm(2,cnt2)%mod;
                ans = ans*ksm(3,cnt3)%mod;
                }
            }
        }
        cout<<ans%mod<<'\n';
    }
    return 0;
}

/*
 7
 5 3 0 0 0 0 0 0 0
 4 1 1 1 0 0 0 0 0
 1 0 0 0 0 0 0 0 0
 1 0 0 0 0 0 0 0 1
 1 0 0 0 0 0 0 0 2
 99 88 77 66 55 44 33 22 11
 100 90 80 70 60 50 40 30 20
*/
