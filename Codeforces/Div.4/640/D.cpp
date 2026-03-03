#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100;
int T,n,a[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        int cnt=0,s1=0,s2=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int l=1,r=n,lst=0;
        while(l<=r){
            int nw=0;
            if((++cnt)&1){
                do{
                    nw+=a[l];
                    l++;
                }while(nw<=lst&&l<=r);
                s1+=nw;
            }else{
                do{
                    nw+=a[r];
                    r--;
                }while(nw<=lst&&l<=r);
                s2+=nw;
            }
            lst=nw;
        }
        cout<<cnt<<" "<<s1<<" "<<s2<<'\n';
    }
    return 0;
}