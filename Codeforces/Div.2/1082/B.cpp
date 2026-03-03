#include<bits/stdc++.h>
using namespace std;
void __(){
    int n;
    string s;
    cin>>n>>s;
    if(n&1){
        if(s[0]=='b'){
            cout<<"NO\n";
            return;
        }
        for(int i=1;i<n;i+=2){
            if((s[i]=='a'&&s[i+1]=='a')||(s[i]=='b'&&s[i+1]=='b')){
                cout<<"NO\n";
                return;
            }
        }
    }else{
        for(int i=0;i<n;i+=2){
            if((s[i]=='a'&&s[i+1]=='a')||(s[i]=='b'&&s[i+1]=='b')){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
}
int main(){
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}