#include<bits/stdc++.h>
using namespace std;
const int N=100;
void __(){
    int n;
    cin>>n;
    int maxx=-1,ans=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x>maxx){
            maxx=x;
            ans=1;
        }else if(x==maxx) ans++;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}