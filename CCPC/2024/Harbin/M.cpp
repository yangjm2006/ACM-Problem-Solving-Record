#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        ll sum=0,lst=1;
        vector<ll> v;
        v.push_back(n+1);
        for(ll i=1;i<=n/i;i++){
            if(n%i==0){
                sum+=(i-lst)*(n/lst);
                // cout<<(i-lst)*(n/lst)<<" "<<i<<'\n';
                lst=i;
                v.push_back(n/i);
            }
        }
        for(int i=v.size()-1;i>=0;i--){
            sum+=(v[i]-lst)*(n/lst);
            // cout<<(v[i]-lst)*(n/lst)<<" "<<v[i]<<'\n';
            lst=v[i];
        }
        cout<<sum<<'\n';
    }
    return 0;
}