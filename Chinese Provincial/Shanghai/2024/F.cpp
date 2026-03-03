#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>G[N];
int siz[N];
int fa[N];
bool bx[N];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void merge(int u,int v){
    siz[find(u)]+=siz[find(v)];
    siz[find(v)]=0;
    fa[find(v)]=find(u);
}

bool same(int u,int v){
    return find(u)==find(v);
}

bool dfs(int x,int f){
    bx[x]=1;
    bool op = 0;
    for(int v:G[x]){
        if(v==f)continue;
        if(same(x,v)){
            return 1;
        }
        else{
            merge(x,v);
            op |= dfs(v,x);
        }
    }
    return op;
}

void solve(){
    int n,m;
    cin>>n>>m;
    map<int,int>mp;
    int a,b;
    vector<int>huan,lian;
    for(int i=1;i<=n;i++){
        siz[i]=1;
        fa[i]=i;
        cin>>a>>b;
        if(mp.find(a)==mp.end()){
            mp[a]=i;
        }
        else{
            G[i].emplace_back(mp[a]);
            G[mp[a]].emplace_back(i);
        }
        if(mp.find(b)==mp.end()){
            mp[b]=i;
        }
        else{
            G[i].emplace_back(mp[b]);
            G[mp[b]].emplace_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(!bx[i]){
            bool op =dfs(i,i);
            if(op)huan.emplace_back(siz[find(i)]);
            else lian.emplace_back(siz[find(i)]);
        }
    }
    
    sort(lian.begin(),lian.end(),greater());
    vector<int>sum_huan(huan.size()),sum_lian(lian.size());
    if(!huan.empty())sum_huan[0]=huan[0];
    if(!lian.empty())sum_lian[0]=lian[0];
    for(int i=1;i<huan.size();i++)sum_huan[i]=sum_huan[i-1]+huan[i];
    for(int i=1;i<lian.size();i++)sum_lian[i]=sum_lian[i-1]+lian[i];
    
    vector<int>dp(n+1,0);
    vector<int>huan_bag(n+1,0);
    vector<int>bag;

    if(!huan.empty()){
    for(int x:huan){
        huan_bag[x]++;
    }
    for(int i=1;i<=n;i++){
        int base = 1;
        int val = i;
        int x = huan_bag[i];
        while(x>=base){
            x-=base;
            bag.emplace_back(val*base);
        }
        if(x>0)bag.emplace_back(val*x);
    }
    for(int i=0;i<bag.size();i++){
        for(int w=n;w>=bag[i];w--){
            dp[w]=max(dp[w],dp[w-bag[i]]+bag[i]);
        }
    }
    }
    cout<<0<<' ';

    for(int i=2;i<=n;i++){
        int ans = 0;
        // cout<<i<<" "<<sum_huan[huan.size()-1]<<endl;
        if(!huan.empty()&&sum_huan[huan.size()-1]>=i){
            ans = i;
            // cout<<i<<" "<<dp[i]<<endl;
            if(dp[i]<i)ans--;
        }
        else{
            int x=i;
            if(!huan.empty()){
                x-=sum_huan[huan.size()-1];
                ans+=sum_huan[huan.size()-1];
            }
            int l=0,r=lian.size()-1;
            int mid;
            while(l<=r){
                mid=(l+r)>>1;
                if(sum_lian[mid]<x){
                    l=mid+1;
                }
                else r=mid-1;
            }
            ans+=x-(l+1);
        }
        cout<<ans<<" ";
    }

    
}
int main(){
    solve();
    return 0;
}

/*
3 6
 1 2
 2 5
 1 6

  10 10
 1 2
 2 3
 1 3
 4 5
 5 6
 6 7
 4 7
 8 9
 9 10
 8 10
 
*/