#include<iostream>
#define ll long long
const ll INF=3e16;
ll x0,y0,ax,ay,bx,by,xs,ys,t,ans,x[100],y[100],n;
void cal(int s){
    ll tim=std::abs(xs-x[s])+std::abs(ys-y[s]);
    if(tim>t) return;
    ans=std::max(ans,1ll);
    for(int o=1;o<=s;o++){
        if(tim+std::abs(x[o]-x[s])+std::abs(y[o]-y[s])<=t){
            ans=std::max(ans,(ll)1+s-o);
            for(int k=s+1;k<=n;k++){
                if(tim+std::abs(x[o]-x[s])+std::abs(y[o]-y[s])+std::abs(x[k]-x[o])+std::abs(y[k]-y[o])<=t){
                    ans=std::max(ans,(ll)1+k-o);
                }
            }
        }
    }
}
int main(){
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    std::cin>>x[1]>>y[1]>>ax>>ay>>bx>>by>>xs>>ys>>t;
    for(int i=2;i<=90;i++){
        x[i]=x[i-1]*ax+bx;
        y[i]=y[i-1]*ay+by;
        n=i;
        if(x[i]>=INF||y[i]>=INF) break;
    }
    // for(int i=1;i<=n;i++) std::cout<<x[i]<<" "<<y[i]<<'\n';
    for(int i=1;i<=n;i++){
        cal(i);
    }
    std::cout<<ans;
    return 0;
}