#include"bits/stdc++.h"
using namespace std;
const int N=60;
struct node{
    int x,y;
    bool operator < (const node &_) const{
        if(x==_.x) return y<_.y;
        return x<_.x;
    }
};
set<node> p;
int n,l,h,x[N],y[N];
bool in(int l1,int r1,int l2,int r2){
    if(l1>l2&&l1<r2) return 1;
    if(r1>l2&&r1<r2) return 1;
    if(l2>l1&&l2<r1) return 1;
    if(r2>l1&&r2<r1) return 1;
    if(l1==l2&&r1==r2) return 1;
    return 0;
}
bool vis[N];
int ansx[N],ansy[N];
bool check(int px,int py,int nw){
    for(int i=1;i<=n;i++){
        if(!vis[i]) continue;
        if(in(px,px+x[nw],ansx[i],ansx[i]+x[i])&&in(py,py+y[nw],ansy[i],ansy[i]+y[i])) return 0;
        if(px+x[nw]>l||py+y[nw]>h) return 0;
    }
    return 1;
}
int shadowx(int nx,int ny){
    int maxx=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]) continue;
        if(nx>=ansx[i]&&nx<ansx[i]+x[i]) if(ansy[i]+y[i]<=ny) maxx=max(maxx,ansy[i]+y[i]);
    }
    return maxx;
}
int shadowy(int ny,int nx){
    int maxx=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]) continue;
        if(ny>=ansy[i]&&ny<ansy[i]+y[i]) if(ansx[i]+x[i]<=nx) maxx=max(maxx,ansx[i]+x[i]);
    }
    return maxx;
}
void solve(int nw){
    bool f=0;
    for(auto _:p){
        if(check(_.x,_.y,nw)){
            ansx[nw]=_.x;ansy[nw]=_.y;
            f=1;
            p.insert((node){_.x+x[nw],shadowx(_.x+x[nw],_.y+y[nw])});
            p.insert((node){shadowy(_.y+y[nw],_.x+x[nw]),_.y+y[nw]});
            p.erase(_);
            break;
        }
    }
    if(!f) cout<<"-1\n";
    else{
        vis[nw]=1;
        cout<<ansx[nw]<<" "<<ansy[nw]<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>l>>h;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    p.insert((node){0,0});
    for(int i=1;i<=n;i++) solve(i);
    return 0;
}