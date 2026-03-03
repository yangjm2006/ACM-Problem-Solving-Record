#include<bits/stdc++.h>
using namespace std;
string s[200];
int maxx;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        maxx=max(maxx,(int)s[i].size());
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=(maxx-s[i].size())/2;j++) cout<<".";
        cout<<s[i];
        for(int j=1;j<=(maxx-s[i].size())/2;j++) cout<<".";
        cout<<'\n';
    }
    return 0;
}