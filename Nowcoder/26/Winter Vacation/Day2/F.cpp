#include<bits/stdc++.h>
#define ll long long
using namespace std;
void __(){
    ll n;
    cin>>n;
    int tmp;
    for(int i=40;i>=1;i--){
        if(n&(1ll<<(i-1))){
            tmp=i;
            break;
        }
    }
    cout<<(n<<tmp)<<" "<<((n<<tmp)|n)<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}