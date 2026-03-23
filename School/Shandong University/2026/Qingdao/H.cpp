#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+100;
int s[N];
int main(){
    int k=1;
    for(;;){
        cout<<"? "<<k<<'\n';
        cin>>s[k];
        if(s[k]<=s[k/2]) break;
        k*=2;
    }
    int l=k/2,r=k;
    while(l<r){
        int mid=(l+r>>1)+1;
        cout<<"? "<<mid<<'\n';
        cin>>s[mid];
        if(s[mid]>s[l]){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<"! "<<l<<'\n';
    return 0;
}