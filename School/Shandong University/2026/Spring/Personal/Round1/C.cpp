#include<bits/stdc++.h>
using namespace std;
const int N=2e6+100;
int a[N];
void __(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++){
        if(abs(a[i]-a[i-1])>1){
            cout<<"YES\n";
            cout<<i-1<<" "<<i<<'\n';
            return;
        }
    }
    cout<<"NO\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}