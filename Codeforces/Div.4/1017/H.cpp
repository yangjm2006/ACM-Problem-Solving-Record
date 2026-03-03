#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+100;
ll T,n,a[N],q,k,l,r,ans;
vector<ll> v[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<N;i++) v[i].clear();
        for(int i=1;i<=n;i++) v[a[i]].push_back(i);
        while(q--){
            ans=0;
            cin>>k>>l>>r;
            while(l<=r){
                vector<ll> p;p.clear();
                for(int j=1;j*j<=k;j++) if(k%j==0){
                    if(j!=1) p.push_back(j);
                    if(j*j!=k) p.push_back(k/j);
                }
                // cout<<k<<":";for(auto x:p) cout<<x<<" ";cout<<'\n';
                int minn=r;ll zh=-1;
                for(auto x:p){
                    int L=0,R=v[x].size()-1;
                    while(L<R){
                        int mid=L+R>>1;
                        if(v[x][mid]>=l) R=mid;
                        else L=mid+1;
                    }
                    // if(v[x].size()) cout<<x<<" "<<v[x][L]<<" "<<minn<<"--\n";
                    if(v[x].size()>0&&v[x][L]>=l&&v[x][L]<=r&&v[x][L]<=minn){
                        minn=v[x][L];
                        zh=x;
                    }
                }
                // cout<<l<<" "<<minn<<" "<<k<<" "<<zh<<"++\n";
                ans+=(minn-l)*k;
                while(zh!=-1&&k%zh==0) k/=zh;
                ans+=k;
                l=minn+1;
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
/*
3
5 3
2 3 5 7 11
2 1 5
2 2 4
2310 1 5
4 3
18 12 8 9
216 1 2
48 2 4
82944 1 4
1 3
1
9 1 1
12 1 1
17 1 1 
*/