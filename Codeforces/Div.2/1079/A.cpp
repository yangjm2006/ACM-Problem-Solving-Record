#include<bits/stdc++.h>
using namespace std;
bool check(int x,int y){
    int tmp=x;
    while(x){
        tmp-=x%10;
        x/=10;
    }
    return tmp==y;
}
void __(){
    int x;
    cin>>x;
    int ans=0;
    for(int i=1;i<=100;i++){
        if(check(x+i,x)) ans++;
    }
    cout<<ans<<'\n';
}
int main(){
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}