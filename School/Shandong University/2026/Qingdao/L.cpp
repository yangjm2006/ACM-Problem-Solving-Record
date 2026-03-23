#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200;
ll vis[N],num[N],res[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n,k,x;
    cin>>n>>k>>x;
    if(k>n){
        cout<<"NO";
        return 0;
    }
    ll cnt=0;
    while(n){
        vis[cnt]=n%x;
        num[cnt]=vis[cnt];
        n/=x;
        cnt++;
    }
    ll sum=0;
    res[0]=1;
    for(int i=1;i<=100;i++) res[i]=res[i-1]*x;
    for(int i=0;i<=100;i++) sum+=vis[i];
    if(sum>k){
        cout<<"NO\n";
        return 0;
    }
    if((k-sum)%(x-1)==0){
        ll tmp=(k-sum)/(x-1);
        for(int i=100;i>=1;i--){
            if(tmp==0) break;
            while(num[i]>0&&tmp>0){
                num[i]--;
                num[i-1]+=x;
                tmp--;
            }
        }
        cout<<"YES\n";
        for(int i=100;i>=0;i--){
            for(int j=1;j<=num[i];j++){
                cout<<res[i]<<" ";
            }
        }
    }else{
        cout<<"NO\n";
    }
    return 0;
}