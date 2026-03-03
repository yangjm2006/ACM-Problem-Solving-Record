#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
const ll INF=1e10;
ll tr[N],sum[N];
void pushup(int u){
    tr[u]=tr[u<<1]+tr[u<<1|1];
    sum[u]=sum[u<<1]+sum[u<<1|1];
}
void update(int u,int l,int r,int x,ll y){
    if(l==r) return tr[u]+=y,sum[u]++,void();
    int mid=l+r>>1;
    if(x<=mid) update(u<<1,l,mid,x,y);
    else update(u<<1|1,mid+1,r,x,y);
    pushup(u);
}
ll query(int u,int l,int r,int L,int R){
    if(l>=L&&r<=R) return tr[u];
    int mid=l+r>>1;ll res=0;
    if(L<=mid) res+=query(u<<1,l,mid,L,R);
    if(R>mid) res+=query(u<<1|1,mid+1,r,L,R);
    return res;
}
int find(int u,int l,int r,int k){
    if(l==r) return l;
    int mid=l+r>>1;
    if(sum[u<<1]>=k) return find(u<<1,l,mid,k);
    return find(u<<1|1,mid+1,r,k-sum[u<<1]);
}
struct node{
    ll x,y;int pos;
    bool operator < (const node _) const{
        return y>_.y;
    }
}a[N];
ll n,m,ans[N],minn[N],siz[N],pre[N];
bool cmp(node a,node b){
    return a.x>b.x;
}
void __(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++) a[i].pos=i;
    sort(a+1,a+1+n);
    for(int i=0;i<=n;i++){
        ans[i]=siz[i]=0;
        minn[i]=INF;
    }
    for(int i=0;i<=4*n;i++) tr[i]=sum[i]=0;
    int tp=1;
    for(int i=n;i>=0;i--){
        while(tp<=n&&a[tp].y>=i){
            update(1,1,n,a[tp].pos,a[tp].x);
            minn[i]=min(minn[i],a[tp].x);
            siz[i]++;
            tp++;
        }
        ans[i]=query(1,1,n,1,find(1,1,n,i+1));
    }
    pre[n]=ans[n];
    for(int i=n-1;i>=0;i--){
        minn[i]=min(minn[i],minn[i+1]);
        siz[i]+=siz[i+1];
        pre[i]=max(ans[i],pre[i+1]);
        // ans[i]=max(ans[i],ans[i+1]);
    }
    ll maxx=-1;
    for(int i=0;i<=n;i++) maxx=max(maxx,ans[i]);
    while(m--){
        ll x,y;
        cin>>x>>y;
        if(y==0) cout<<max(maxx,x)<<' ';
        else if(siz[y]<y+1) cout<<max(maxx,x+pre[y])<<' ';
        else cout<<max(maxx,x+ans[y]-minn[y])<<' ';
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}