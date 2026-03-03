#include<bits/stdc++.h>
using namespace std;
int T,n,k;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        if((n%2==1&&k%2==0)||k>n){
            cout<<"NO\n";
            continue;
        }
        if(n%2==1&&k%2==1){
            cout<<"YES\n";
            cout<<n-(k-1);
            for(int i=1;i<=k-1;i++) cout<<" 1";
            cout<<'\n';
        }else if(k%2==1){
            if(n<2*k) cout<<"NO\n";
            else{
                cout<<"YES\n";
                cout<<n-2*(k-1);
                for(int i=1;i<=k-1;i++) cout<<" 2";
                cout<<'\n';
            }
        }else{
            cout<<"YES\n";
            cout<<n-(k-1);
            for(int i=1;i<=k-1;i++) cout<<" 1";
            cout<<'\n';
        }
    }
    return 0;
}