#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int T,n,a[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            if(a[i]%2){
                for(int j=i+1;j<=n;j++) if(a[j]<a[i]) a[j]--;
                a[i]=;
            }else{

            }
        }
        cout<<'\n';
    }
    return 0;
}