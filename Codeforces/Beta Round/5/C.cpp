#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
string s;
int maxx,ans=1,len[N];
stack<int> stc;
int main(){
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            stc.push(i);
        }else{
            if(!stc.empty()){
                len[i]=i-stc.top()+len[stc.top()-1]+1;stc.pop();
                if(len[i]>maxx){
                    maxx=len[i];
                    ans=1;
                }else if(len[i]==maxx) ans++;
            }
        }
    }
    cout<<maxx<<" "<<ans;
    return 0;
}