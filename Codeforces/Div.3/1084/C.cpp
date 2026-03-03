#include<bits/stdc++.h>
using namespace std;
void __(){
    int n;
    cin>>n;
    stack<char> s;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(s.size()!=0&&s.top()==c){
            s.pop();
        }else s.push(c);
    }
    if(s.empty()) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}