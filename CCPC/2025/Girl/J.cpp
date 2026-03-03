#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        cout<<s;
        if(s[s.size()-1]=='n') cout<<'g';
        cout<<" ";
    }
    return 0;
}