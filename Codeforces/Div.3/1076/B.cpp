#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]!=n+1-i){
            for(int j=i+1;j<=n;j++){
                if(a[j]==n+1-i){
                    for(int k=0;k<=(j-i)/2;k++){
                        swap(a[i+k],a[j-k]);
                    }
                    break;
                }
            }
            break;
        }
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}