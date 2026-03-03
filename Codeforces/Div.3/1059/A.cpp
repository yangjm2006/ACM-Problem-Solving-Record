#include<bits/stdc++.h>
using namespace std;
int n,T;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        int maxx=0;
        for(int i=1,x;i<=n;i++){
            cin>>x;
            maxx=max(maxx,x);
        }
        cout<<maxx<<'\n';
    }
    return 0;
}