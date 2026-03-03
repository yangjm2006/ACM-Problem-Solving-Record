#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100;
int T,n,a[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        int cnt=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            int l=1,r=0,s=0;
            bool f=0;
            while(l<=n){
                while(r<n&&a[r+1]+s<=a[i]){
                    r++;
                    s+=a[r];
                }
                if(a[i]==s&&r-l>=1){
                    f=1;
                    break;
                }
                s-=a[l];
                l++;
            }
            cnt+=f;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}