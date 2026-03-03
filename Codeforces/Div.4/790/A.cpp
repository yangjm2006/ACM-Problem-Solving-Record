#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
    cin>>T;
    while(T--){
        int x,s1=0,s2=0,cnt=0;
        cin>>x;
        while(x){
            if(++cnt<=3) s1+=x%10;
            else s2+=x%10;
            x/=10;
        }
        if(s1==s2) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}