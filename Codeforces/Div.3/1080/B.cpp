#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int a[N];
bool cmp(int x,int y){
    while(x%2==0) x/=2;
    while(y%2==0) y/=2;
    return x==y;
}
void __(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(!cmp(a[i],i)){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}