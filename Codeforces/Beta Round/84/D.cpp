#include<bits/stdc++.h>
const int N=1e5+10;
bool luck(int x){
    bool f=1;
    while(x){
        if(x%10!=4&&x%10!=7) f=0;
        x/=10;
    }
    return f;
}
struct node{
    int val,id;
    bool operator < (const node &x) const{
        return val<x.val;
    }
}v[N];
int a[N],b[N];
std::vector<std::pair<int,int>> ans;
void change(int pos1,int pos2){
    if(pos1==pos2) return;
    std::swap(a[b[pos1]],a[b[pos2]]);
    std::swap(b[pos1],b[pos2]);
    ans.push_back(std::make_pair(pos1,pos2));
}
void solve(){
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++) std::cin>>v[i].val,v[i].id=i;
    int lst=-1;
    bool f1=0;
    for(int i=0;i<n;i++){
        if(luck(v[i].val)){
            lst=i+1;
            f1=1;
            break;
        }
    }
    bool f2=1;
    for(int i=0;i<n-1;i++) if(v[i].val>v[i+1].val) f2=0;
    std::sort(v,v+n);
    for(int i=0;i<n;i++) a[i+1]=v[i].id+1;
    for(int i=1;i<=n;i++) b[a[i]]=i;
    if(lst!=-1){
        for(int i=1;i<=n;i++){
            change(lst,i);
            lst=a[i];
            change(i,a[i]);
        }
    }
    if(f1==0&&f2==0) std::cout<<"-1\n";
    else{
        std::cout<<ans.size()<<'\n';
        for(auto x:ans) std::cout<<x.first<<" "<<x.second<<'\n';
    }
}
int main(){
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    solve();
    return 0;
}