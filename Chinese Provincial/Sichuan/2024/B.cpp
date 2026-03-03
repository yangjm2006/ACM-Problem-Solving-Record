#include"bits/stdc++.h"
using namespace std;
using ll = long long;
ll a[6];

void solve(){
    ll ans = 0;
    for(int i=1;i<=5;i++)cin>>a[i];

    ans += a[3]/2;
    a[3]%=2;
    ll numx = min(a[2],a[4]);
    ans+=numx;
    a[2]-=numx;
    a[4]-=numx;
    numx=min(a[1],a[5]);
    ans+=numx;
    a[1]-=numx;
    a[5]-=numx;

    // cout<<ans<<endl;
    if(a[1]>0){
        if(a[2]>0){
            if(a[3]>0){
                a[2]--;
                a[1]--;
                a[3]--;
                ans++;
            }
            a[2]+=a[1]/2;
            ans+=a[2]/3;
        }
        else if(a[4]>0){
            ll num = min(a[1]/2,a[4]);
            ans+=num;
            a[1]-=2*num;
            a[4]-=num;
            if(a[1]>=2){
                if(a[3]>0&&a[1]>=3){
                    a[3]--;
                    a[1]-=3;
                    ans++;
                }
                ans+=a[1]/6;
            }
            else{
                a[1]+=a[3];
                ll num = min(a[1]/2,a[4]);
                ans+=num;
                a[1]-=2*num;
                a[4]-=num;
                if(a[1]==1&&a[4]>=2){
                    ans++;
                    a[1]--;
                    a[4]-=2;
                }
                ans+=a[4]/3;
            }
        }
        else{
            if(a[3]>0&&a[1]>=3){
                ans++;
                a[3]--;
                a[1]-=3;
            }
            ans+=a[1]/6;
        }
    }
    else if(a[5]>0){
        if(a[2]>0){
            int num = min(a[2],a[5]);
            a[2]-=num;
            a[5]-=num;
            ans+=num;
            if(a[2]>0){
                if(a[3]>0&&a[2]>=2){
                    a[3]--;
                    a[2]-=2;
                    ans++;
                }
                ans+=a[2]/3;
            }
            else{
                if(a[3]>0&&a[5]>0){
                    a[3]--;
                    a[5]--;
                    ans++;
                }
                ans+=a[5]/2;
            }
        }
        else if(a[4]>0){
            if(a[3]>0){
                ans++;
                a[3]--;
                a[5]--;
            }
            int num = min(a[4],a[5]);
            ans+=num;
            a[4]-=num;
            a[5]-=num;
            ans+=a[4]/3;
            ans+=a[5]/2;
        }
        else{
            if(a[3]>0){
                ans++;
                a[3]--;
                a[5]--;
            }
            ans+=a[5]/2;
        }
    }
    else{
        if(a[2]>0){
            if(a[3]>0&&a[2]>=2){
                a[3]--;
                a[2]-=2;
                ans++;
            }
            ans+=a[2]/3;
        }
        else if(a[4]>0){
            if(a[3]>0&&a[4]>=2){
                a[3]--;
                a[4]-=2;
                ans++;
            }
            ans+=a[4]/3;
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
 5
 3 3 3 3 3
 2 3 4 5 1
 1 2 3 4 5
 2 2 0 0 0
 0 3 0 0 3
*/