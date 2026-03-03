#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i+3<s.size();i++){
        if(s[i]=='2'&&s[i+1]=='0'&s[i+2]=='2'&&s[i+3]=='6'){
            cout<<"0\n";
            return;
        }
    }   
    for(int i=0;i+3<s.size();i++){
        if(s[i]=='2'&&s[i+1]=='0'&s[i+2]=='2'&&s[i+3]=='5'){
            cout<<"1\n";
            return;
        }
    }
    cout<<"0\n";
}
int main(){
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}