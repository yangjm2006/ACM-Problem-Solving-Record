#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
struct node{
    int l,r;ll w;
    bool operator < (const node &x) const{
        return w>x.w;
    }
};
int fa[N],num[N];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool same(int x,int y){
    return find(x)==find(y);
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(num[fx]>=num[fy]){
        fa[fy]=fx;
        num[fx]+=num[fy];
    }else{
        fa[fx]=fy;
        num[fy]+=num[fx];
    }
}
ll T,n,a[N],k;
priority_queue<node> q;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        while(!q.empty()) q.pop();
        cin>>n>>k;
        for(int i=1;i<=n;i++) fa[i]=i,num[i]=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]%=k;
        }
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            ll t=(k-a[i])%k;
            int l=1,r=n;
            while(l<r){
                int mid=l+r>>1;
                if(a[mid]>=t) r=mid;
                else l=mid+1;
            }
            // cout<<i<<":"<<a[i]<<" :"<<l<<" "<<a[l]<<"--\n";
            if(a[i]+a[l]<k) q.push((node){1,i,a[i]+a[1]});
            else q.push((node){i,l,(a[i]+a[l])%k});
        }
        int cnt=0;ll ans=0;
        while(cnt!=n-1){
            node x=q.top();q.pop();
            int l=x.l,r=x.r;ll w=x.w;
            if(same(l,r)){
                while(same(l,r)){
                    r++;
                    if(r>n) r-=n;
                    q.push((node){l,r,(a[l]+a[r])%k});
                }
            }else{
                cnt++;
                ans+=w;
                merge(l,r);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
2
 5 3
 1 2 3 4 5
 8 7
 3 1 4 1 5 9 2 6
*/