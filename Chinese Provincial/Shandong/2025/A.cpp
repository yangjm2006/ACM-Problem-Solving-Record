#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
vector<pair<int,int>> v[N];
int n;
vector<int> ans;
bool check(int k){
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            if(res+v[i][j].first+v[i].size()-j>=k){
                for(int o=j;o<v[i].size();o++){
                    ans.push_back(v[i][o].second);
                    res++;
                    if(res==k) return 1;
                }
                break;
            }
        }
    }
    return 0;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) v[i].clear();
    for(int i=1,x,y;i<=n;i++){
        cin>>x>>y;
        v[x].push_back(make_pair(y,i));
    }
    for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
    int l=1,r=n;
    while(l<r){
        int mid=(l+r>>1)+1;
        if(check(mid)) l=mid;
        else r=mid-1;
        ans.clear();
    }
    cout<<l<<'\n';
    ans.clear();
    check(l);
    for(auto x:ans) cout<<x<<' ';
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
/*
2
6
3 0
4 0
3 1
5 3
1 2
3 1
2
1 1
1 0
*/