#include<bits/stdc++.h>
struct node{
    int num,id;
    bool operator < (const node &x) const{
        return num>x.num;
    }
};
void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<node> a(m);
    std::vector<int> ans(n+1,0);
    for(int i=0;i<m;i++) std::cin>>a[i].num,a[i].id=i+1;
    sort(a.begin(),a.end());
    for(int i=1;i<=a[0].num&&2*i<=n;i++) ans[i*2-1]=a[0].id;
    if(n&1){
        if(n>=3&&m>=3&&a[0].num*2+1>=n){
            ans[n]=a[1].id;
            a[1].num--;
            ans[n-1]=a[2].id;
            a[2].num--;
        }
    }
    for(int i=1;2*i-1<=n;i++){
        if(ans[2*i-1]) continue;
        for(int j=1;j<m;j++){
            if(a[j].num>0){
                a[j].num--;
                ans[2*i-1]=a[j].id;
                break;
            }
        }
    }
    for(int i=1;2*i<=n;i++){
        if(ans[2*i]) continue;
        for(int j=1;j<m;j++){
            if(a[j].num>0){
                a[j].num--;
                ans[2*i]=a[j].id;
                break;
            }
        }
    }
    bool f=1;
    for(int i=1;i<=n;i++) if(ans[i]==0) f=0;
    for(int i=1;i<=n-1;i++) if(ans[i]==ans[i+1]) f=0;
    if(!f) std::cout<<"-1\n";
    else{
        for(int i=1;i<=n;i++) std::cout<<ans[i]<<' ';
        std::cout<<'\n';
    }
}
int main(){
    solve();
}