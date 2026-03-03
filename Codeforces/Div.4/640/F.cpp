#include<bits/stdc++.h>
using namespace std;
int T,n0,n1,n2;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n0>>n1>>n2;
        if(n1==0){
            if(n0){
                for(int i=1;i<=n0+1;i++) cout<<"0";
                cout<<'\n';
            }
            else{
                for(int i=1;i<=n2+1;i++) cout<<"1";
                cout<<'\n';
            }
        }else{
            for(int i=1;i<=n2+1;i++) cout<<"1";
            for(int i=1;i<=n0+1;i++) cout<<"0";
            for(int i=1;i<=n1-1;i++) cout<<(i&1);
            cout<<'\n';
        }
    }
    return 0;
}