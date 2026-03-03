#include"bits/stdc++.h"
using namespace std;
const double eps=1e-8;
double x,y,r,vx,vy,lx,ly,rx,ry;
void solve(){
    cin>>x>>y>>r>>vx>>vy;
    if(vx<eps) vx=eps;
    if(vy<eps) vy=eps;
    cin>>lx>>ly>>rx>>ry;
    bool f=0;
    double t1l=(lx+r-x)/vx,t1r=(rx-r-x)/vx,t2l=(ly+r-y)/vy,t2r=(ry-r-y)/vy;
    if(t1l>t1r) swap(t1l,t1r);
    if(t2l>t2r) swap(t2l,t2r);
    // cout<<t1l<<" "<<t1r<<" "<<t2l<<" "<<t2r<<"++\n";
    if(t1l>t1r+eps||t2l>t2r+eps||t1r<-eps||t2r<-eps||2*r>(rx-lx)||2*r>(ry-ly)){
        cout<<"No\n";
        return;
    }
    t1l=max(t1l,0.0);t2l=max(t2l,0.0);
    if(t1l>t2l-eps&&t1l<t2r+eps) f=1;
    if(t1r>t2l-eps&&t1r<t2r+eps) f=1;
    if(t2l>t1l-eps&&t2l<t1r+eps) f=1;
    if(t2r>t1l-eps&&t2r<t1r+eps) f=1;
    if(f) cout<<"Yes\n";
    else cout<<"No\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
 5
 0 0 1 1 0
 2-2 6 2
 0 0 1 1 0
 2 0 6 2
 0 0 1 1 1
 1 1 3 3
 0 0 1 -1 -1
 1 1 3 3
 0 0 1 -1 1
 -5 -5 5 5
*/