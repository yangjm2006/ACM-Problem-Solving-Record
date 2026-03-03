#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
    cin>>T;
    while(T--){
        string s1,s2;
        cin>>s1>>s2;
        cout<<s2[0]<<s1[1]<<s1[2]<<" "<<s1[0]<<s2[1]<<s2[2]<<'\n';
    }
    return 0;
}