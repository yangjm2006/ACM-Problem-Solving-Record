#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
const ll INF=1e10;
ll h,c,t;
ll cal(ll x){
    return h*(x+1)+c*x-t*(2*x+1);
}
void __(){
    cin>>h>>c>>t;
    if(h==t){
        cout<<"1\n";
        return;
    }
    if(h+c>=2*t){
        cout<<"2\n";
        return;
    }
    ll l=0,r=INF;
    while(l<r){
        ll mid=(l+r>>1)+1;
        if(cal(mid)>=0) l=mid;
        else r=mid-1;
    }
    // cout<<l<<"!!\n";
    // cout<<1.0*cal(l)/(2*l+1)<<" "<<-1.0*cal(l+1)/(2*l+3)<<"------\n";
    if((__int128)cal(l)*(2*l+3)<=(__int128)-cal(l+1)*(2*l+1)){
        cout<<2*l+1<<'\n';
    }else{
        cout<<2*l+3<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}