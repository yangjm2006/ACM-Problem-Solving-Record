#include<bits/stdc++.h>
using namespace std;
void __(){
    int n;
    cin>>n;
    bool f=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==67) f=1;
    }
    if(f) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}