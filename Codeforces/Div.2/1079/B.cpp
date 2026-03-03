#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int mp[N];
void __(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        mp[x]=i;
    }
    int lst=-1;
    bool f=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        // cout<<x<<" ";
        x=mp[x];
        // cout<<x<<"++\n";
        if(x<lst){
            f=1;
        }
        lst=x;
    }
    if(f) cout<<"NO\n";
    else cout<<"YES\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}