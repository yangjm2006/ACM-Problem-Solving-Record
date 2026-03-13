#include<bits/stdc++.h>
using namespace std;
int n,d,h;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>d>>h;
    if(d>h*2||(n>=3&&d<=1)){
        cout<<"-1";
        return 0;
    }
    for(int i=1;i<=h;i++){
        cout<<i<<" "<<i+1<<'\n';
    }
    if(d>h){
        cout<<1<<" "<<h+2<<'\n';
        for(int i=h+2;i<=d;i++) cout<<i<<" "<<i+1<<'\n';
    }
    int p=(d==h)?2:1;
    for(int i=d+2;i<=n;i++) cout<<p<<" "<<i<<'\n';
    return 0;
}