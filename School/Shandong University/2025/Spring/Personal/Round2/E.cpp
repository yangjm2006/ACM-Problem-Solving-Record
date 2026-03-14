#include<bits/stdc++.h>
using namespace std;
void __(){
    int n,x,cnt=0;
    cin>>n>>x;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        if(u==x||v==x) cnt++;
    }
    if(cnt<=1||n%2==0) cout<<"Ayush\n";
    else cout<<"Ashish\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}