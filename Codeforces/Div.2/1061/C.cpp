#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int T,n,k,a[N],s[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=4*n;i++) s[i]=0;
        for(int i=1;i<=n;i++) s[a[i]]++;
        for(int i=1;i<=4*n;i++) s[i]+=s[i-1];
        for(int i=n;i>=1;i--){
            if(s[i]-s[i-1]+s[i*2]-s[i*2-1]+s[i*3]-s[i*3-1]+s[n]-s[4*i-1]+k>=n){
                cout<<i<<"\n";
                break;
            }
        }
    }
}