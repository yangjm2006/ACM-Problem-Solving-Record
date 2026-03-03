#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    map<int,int> mpx,mpy,mpz;
    for(int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        mpx[x]++;mpy[y]++;mpz[z]++;
    }
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        mpx[x]++;mpy[y]++;mpz[z]++;
    }
    bool f=1;
    for(auto &x:mpx){
        if(x.second%2) f=0;
    }
    for(auto &x:mpy){
        if(x.second%2) f=0;
    }
    for(auto &x:mpz){
        if(x.second%2) f=0;
    }
    if(f) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
}
/*
 3

 9 7
 0 2-2
 -2 2 0
 0 1 -1
 2 0 -2
 -1 0 1
 2 -2 0
 0 -2 2
 0 0 0
 -2 1 1
 -1 1 0
 1 1 -2
 2 0 -2
 2 -1 -1
 0 -1 1
 0 -2 2
 1 -2 1

 5 3
 0 0 0
 -1 1 0
 -1 0 1
 0 -1 1
 1 0 -1
 0 0 0
 0 1 -1
 1 -1 0

 4 3
 -1 1 0
 -1 0 1
 0 -1 1
 1 0 -1
 0 0 0
 0 1 -1
 1 -1 0
*/