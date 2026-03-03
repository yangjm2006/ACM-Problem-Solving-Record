#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll R(){
    return (rand()<<10)|rand();
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n=1e3;
    cout<<n<<'\n';
    for(int i=1;i<=n;i++){
        ll D=R();
        cout<<D<<" "<<D+rand()<<'\n';
    }
    return 0;
}