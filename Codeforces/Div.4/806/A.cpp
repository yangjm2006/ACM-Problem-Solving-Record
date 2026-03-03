#include"bits/stdc++.h"
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        for(auto &x:s) if(x>='A'&&x<='Z') x=x-'A'+'a';
        cout<<(s=="yes"?"YES":"NO")<<"\n";
    }
    return 0;
}