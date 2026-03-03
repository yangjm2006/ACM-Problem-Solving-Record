#include<bits/stdc++.h>
using namespace std;
int T;
string s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>s;
        bool f=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==s[(i-1+n)%n]){
                cout<<i<<'\n';
                f=1;
                break;
            }
        }
        if(!f) cout<<"-1\n";
    }
    return 0;
}