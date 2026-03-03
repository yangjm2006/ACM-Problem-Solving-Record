#include<bits/stdc++.h>
void solve(){
    int n,m,k;
    std::cin>>n>>k;
    m=n/k;
    std::vector<int> a(n+1);
    std::vector<bool> vis(n+1,0);
    double minn=1e9,maxx=-1e9;
    for(int i=1;i<=n;i++) std::cin>>a[i];
    int t;
    std::cin>>t;
    for(int i=1;i<=t;i++){
        double res=0;
        for(int j=1,x;j<=m;j++){
            std::cin>>x;
            res+=a[x];
            vis[x]=1;
        }
        res/=m;
        minn=std::min(minn,res);
        maxx=std::max(maxx,res);
    }
    std::vector<int> v;
    for(int i=1;i<=n;i++) if(!vis[i]) v.push_back(a[i]);
    std::sort(v.begin(),v.end());
    if(v.size()-n%k>=m){
        double res=0;
        for(int i=0;i<m;i++) res+=v[i];
        res/=m;
        minn=std::min(minn,res);
        maxx=std::max(maxx,res);
        res=0;
        for(int i=0;i<m;i++) res+=v[v.size()-1-i];
        res/=m;
        minn=std::min(minn,res);
        maxx=std::max(maxx,res);
    }
    std::cout<<std::fixed<<std::setprecision(10)<<minn<<" "<<maxx;
}
int main(){
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    solve();
    return 0;
}