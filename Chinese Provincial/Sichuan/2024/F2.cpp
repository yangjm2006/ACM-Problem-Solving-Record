#include"bits/stdc++.h"
using namespace std;
const double eps=1e-8;
double x,y,r,vx,vy,lx,ly,rx,ry;
void solve(){
    cin>>x>>y>>r>>vx>>vy;
    cin>>lx>>ly>>rx>>ry;
    bool f=0;
    if(fabs(vx)<eps){
        double t2l=(ly+r-y)/vy,t2r=(ry-r-y)/vy;
        if(t2l>-eps){
        double lxm = x+t2l*vx-r;
        double rxm = x+t2l*vx+r;
        double rym = y+t2l*vy+r;
        if((rxm-rx<eps||fabs(rxm-rx)<eps)&&(lxm-lx>eps||fabs(lxm-lx)<eps)&&(rym-ry<eps||fabs(rym-ry)<eps)){
            cout<<"Yes\n";
            return;
        }
    }
    if(t2r>-eps){
        double lxm = x+t2r*vx-r;
        double rxm = x+t2r*vx+r;
        double lym = y+t2r*vy-r;
        if((rxm-rx<eps||fabs(rxm-rx)<eps)&&(lxm-lx>eps||fabs(lxm-lx)<eps)&&(lym-ly>eps||fabs(lym-ly)<eps)){
            cout<<"Yes\n";
            return;
        }
    }
        cout<<"No\n";
        return;
    }
    if(fabs(vy)<eps){
        double t1l=(lx+r-x)/vx,t1r=(rx-r-x)/vx;
        if(t1l>-eps){
        double rxm = x+t1l*vx+r;
        double lym = y+t1l*vy-r;
        double rym = y+t1l*vy+r;
        // cout<<rxm<<" - "<<lym<<" "<<rym<<endl;
        // cout<<rx<<" - "<<ly<<" - "<<ry<<endl;
        if((rxm-rx<eps||fabs(rxm-rx)<eps)&&(lym-ly>eps||fabs(lym-ly)<eps)&&(rym-ry<eps||fabs(rym-ry)<eps)){
            cout<<"Yes\n";
            return;
        }
        
    }
    if(t1r>-eps){
        double lxm = x+t1r*vx-r;
        double lym = y+t1r*vy-r;
        double rym = y+t1r*vy+r;
        if((lxm-lx>eps||fabs(lxm-lx)<eps)&&(lym-ly>eps||fabs(lym-ly)<eps)&&(rym-ry<eps||fabs(rym-ry)<eps)){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
    return;
    }
    double t1l=(lx+r-x)/vx,t1r=(rx-r-x)/vx,t2l=(ly+r-y)/vy,t2r=(ry-r-y)/vy;
    // cout<<t1l<<" "<<t1r<<" "<<t2l<<" "<<t2r<<endl;
    if(t1l>-eps){
        double rxm = x+t1l*vx+r;
        double lym = y+t1l*vy-r;
        double rym = y+t1l*vy+r;
        // cout<<rxm<<" - "<<lym<<" "<<rym<<endl;
        // cout<<rx<<" - "<<ly<<" - "<<ry<<endl;
        if((rxm-rx<eps||fabs(rxm-rx)<eps)&&(lym-ly>eps||fabs(lym-ly)<eps)&&(rym-ry<eps||fabs(rym-ry)<eps)){
            cout<<"Yes\n";
            return;
        }
        
    }
    if(t1r>-eps){
        double lxm = x+t1r*vx-r;
        double lym = y+t1r*vy-r;
        double rym = y+t1r*vy+r;
        if((lxm-lx>eps||fabs(lxm-lx)<eps)&&(lym-ly>eps||fabs(lym-ly)<eps)&&(rym-ry<eps||fabs(rym-ry)<eps)){
            cout<<"Yes\n";
            return;
        }
    }
    if(t2l>-eps){
        double lxm = x+t2l*vx-r;
        double rxm = x+t2l*vx+r;
        double rym = y+t2l*vy+r;
        if((rxm-rx<eps||fabs(rxm-rx)<eps)&&(lxm-lx>eps||fabs(lxm-lx)<eps)&&(rym-ry<eps||fabs(rym-ry)<eps)){
            cout<<"Yes\n";
            return;
        }
    }
    if(t2r>-eps){
        double lxm = x+t2r*vx-r;
        double rxm = x+t2r*vx+r;
        double lym = y+t2r*vy-r;
        if((rxm-rx<eps||fabs(rxm-rx)<eps)&&(lxm-lx>eps||fabs(lxm-lx)<eps)&&(lym-ly>eps||fabs(lym-ly)<eps)){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
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