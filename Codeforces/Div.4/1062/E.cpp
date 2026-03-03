#include<bits/stdc++.h>
#define ll long long
const int N=2e5+100;
struct node{
    int pos,x,tp;
    bool operator < (const node &_) const{
        return x<_.x;
    }
};
int n,k,a[N],val;
std::map<int,bool> mp;
void solve(){
    mp.clear();
    std::cin>>n>>k>>val;
    std::priority_queue<node> q;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    std::sort(a+1,a+1+n);
    q.push((node){0,a[1],1});
    q.push((node){val,val-a[n],2});
    for(int i=1;i<=n-1;i++){
        int x=(a[i]+a[i+1])/2;
        q.push((node){x+1,a[i+1]-x-1,1});
        q.push((node){x,x-a[i],2});
    }
    int cnt=0;
    std::vector<int> ans;
    while(cnt<k){
        int pos=q.top().pos,tp=q.top().tp,x=q.top().x;
        if(mp[pos]){
            q.pop();
            continue;
        }
        cnt++;
        ans.push_back(pos);
        mp[pos]=1;
        if(tp==1) q.push((node){pos+1,x-1,tp});
        else q.push((node){pos-1,x-1,tp});
    }
    std::sort(ans.begin(),ans.end());
    for(auto x:ans) std::cout<<x<<" ";
    std::cout<<'\n';
}
int main(){
    std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0);
    int T;
    std::cin>>T;
    while(T--) solve();
    return 0;
}