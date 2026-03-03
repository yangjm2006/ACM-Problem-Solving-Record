#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int T,n;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        bool fl=1;
        cin>>n>>s1>>s2;
        for(int i=0;i<n;i++){
            if(i<n-3&&s1[i]=='T'&&s1[i+1]=='I'&&s1[i+2]=='O'&&s1[i+3]=='T'&&s2[i]=='I'&&s2[i+1]=='S'&&s2[i+2]=='C'){
                s1[i]='I';s1[i+1]='S';s1[i+2]='C';
            }
            if(s1[i]!=s2[i]){
                fl=0;
                break;
            }
        }
        if(fl) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}