#include<bits/stdc++.h>
using namespace std;
void __(){
    int x,y;
    cin>>x>>y;
    if(y>0) x-=2*y;
    else x+=4*y;
    if(x%3==0&&x>=0) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}