#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+100;
struct node{
    int w;ll val;
    bool operator < (const node &_) const{
        if(w==_.w) return val>_.val;
        return w<_.w;
    }
}a[N];
ll dp[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        a[i].w=s.size();
        cin>>a[i].val;
    }
    sort(a+1,a+1+n);
    vector<node> v;
    for(int i=1;i<=n;i++){
        if(i==1||prev(v.end())->val<a[i].val){
            v.push_back(a[i]);
        }
    }
    for(auto x:v){
        int w=x.w;ll val=x.val;
        for(int j=0;j+w<=m;j++){
            dp[j+w]=max(dp[j+w],dp[j]+val);
        }
    }
    cout<<dp[m];
    return 0;
}