#include<bits/stdc++.h>
using namespace std;
const int N=100;
int a[N];
void __(){
    int n;
    bool f=0;
    a[0]=-1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) f=1;
    }
    if(f) cout<<1<<'\n';
    else cout<<n<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}