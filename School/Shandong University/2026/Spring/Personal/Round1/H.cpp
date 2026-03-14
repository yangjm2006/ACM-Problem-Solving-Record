#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
struct Mat{
    ll a[110][110];
    Mat(){
        for(int i=0;i<=100;i++) for(int j=0;j<=100;j++) a[i][j]=0;
    }
    void build(){
        for(int i=0;i<=100;i++) a[i][i]=1;
    }
    Mat operator * (const Mat &_) const{
        Mat ans;
        for(int i=0;i<=100;i++){
            for(int j=0;j<=100;j++){
                for(int k=0;k<=100;k++){
                    ans.a[i][j]+=a[i][k]*_.a[k][j]%mod;
                    ans.a[i][j]%=mod;
                }
            }
        }
        return ans;
    }
};
ll num[20];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n,b,k,x;
    cin>>n>>b>>k>>x;
    for(int i=1;i<=n;i++){
        int d;
        cin>>d;
        num[d]++;
    }
    Mat IE,ans;
    ans.build();
    for(int i=0;i<=x-1;i++){
        for(int j=0;j<=9;j++){
            IE.a[i][(i*10+j)%x]+=num[j];
        }
    }
    // for(int i=0;i<x;i++){
    //     for(int j=0;j<x;j++) cout<<IE.a[i][j]<<" ";
    //     cout<<'\n';
    // }
    // cout<<"----------\n";
    for(;b;b>>=1,IE=IE*IE){
        if(b&1) ans=ans*IE;
    }
    // for(int i=0;i<x;i++){
    //     for(int j=0;j<x;j++) cout<<ans.a[i][j]<<" ";
    //     cout<<'\n';
    // }
    cout<<ans.a[0][k];
    return 0;
}