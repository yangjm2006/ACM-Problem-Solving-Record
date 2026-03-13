#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
string ans;
char c[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    s="0"+s;
    c[n]=s[n];
    for(int i=n-1;i>=1;i--){
        c[i]=min(s[i],c[i+1]);
    }
    // for(int i=1;i<=n;i++) cout<<c[i];cout<<'\n';
    stack<char> stc;
    for(int i=1;i<=n;i++){
        while((!stc.empty())&&stc.top()<=c[i]){
            ans+=stc.top();
            stc.pop();
        }
        stc.push(s[i]);
    }
    while(!stc.empty()){
        ans+=stc.top();
        stc.pop();
    }
    cout<<ans;
    return 0;
}