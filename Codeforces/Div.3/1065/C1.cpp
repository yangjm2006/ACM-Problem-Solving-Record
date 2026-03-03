#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    int cnt=0,lst;
    for(int i=1;i<=n;i++){
        if(a[i]^b[i]){
            cnt++;
            lst=i;
        }
    }
    if(cnt%2==0) cout<<"Tie\n";
    else if(lst&1) cout<<"Ajisai\n";
    else cout<<"Mai\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}