#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n,a[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        a[i]=a[a[i]];
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}