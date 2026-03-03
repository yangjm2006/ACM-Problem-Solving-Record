#include<bits/stdc++.h>
using namespace std;
void __(){
    int a[4];
    for(int i=1;i<=3;i++) cin>>a[i];
    int maxx=-1,minn=1e9+100;
    for(int i=1;i<=3;i++){
        maxx=max(maxx,a[i]);
        minn=min(minn,a[i]);
    }
    if(maxx<=minn+1) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}