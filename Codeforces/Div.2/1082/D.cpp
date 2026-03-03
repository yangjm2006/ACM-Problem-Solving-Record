#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int a[N];
void work(int x){
    for(int i=1;i<=2*x-1;i++) cout<<a[i]<<" ";
    cout<<x<<" ";
}
void __(){
    int n,k;
    cin>>n>>k;
    if(k<n||k>2*n-1){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    int m=n-(2*n-1-k);
    work(m);
    for(int i=m+1;i<=n;i++) cout<<i<<" "<<i<<" ";
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    a[1]=a[3]=1;
    for(int i=2;i<=300000;i++) a[2*i+1]=a[2*i-2]=i;
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}