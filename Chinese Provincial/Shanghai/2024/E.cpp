#include<bits/stdc++.h>
using namespace std;
int str[26];

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(auto x:s){
        if(x<='Z'&&x>='A')x=x-'A';
        else x=x-'a';
        str[x]++;
    }
    int ans = n;
    ans=min(ans,str['s'-'a']);
    ans=min(ans,str['h'-'a']/2);
    ans=min(ans,str['a'-'a']/2);
    ans=min(ans,str['n'-'a']);
    ans=min(ans,str['g'-'a']);
    ans=min(ans,str['i'-'a']);
    cout<<ans<<endl;
}


int main(){

    solve();
    return 0;
}