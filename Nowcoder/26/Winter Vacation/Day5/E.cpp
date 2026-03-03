#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+100;
const ll INF=1e18;
ll tr[N<<2];
void pushup(int u){
    tr[u]=max(tr[u<<1],tr[u<<1|1]);
}
void build(int u,int l,int r){
    if(l==r) return tr[u]=-INF,void();
    int mid=l+r>>1;
    build(u<<1,l,mid);build(u<<1|1,mid+1,r);
    pushup(u);
}
void update(int u,int l,int r,int id,ll x){
    if(l==r) return tr[u]=x,void();
    int mid=l+r>>1;
    if(mid>=id) update(u<<1,l,mid,id,x);
    else update(u<<1|1,mid+1,r,id,x);
    pushup(u);
}
ll query(int u,int l,int r,int L,int R){
    if(l>=L&&r<=R) return tr[u];
    int mid=l+r>>1;
    ll ans=-INF;
    if(mid>=L) ans=max(ans,query(u<<1,l,mid,L,R));
    if(mid<R) ans=max(ans,query(u<<1|1,mid+1,r,L,R));
    return ans;
}
struct node{
    int id;
    ll val;
    bool operator < (const node &_) const{
        if(val==_.val) return id<_.id;
        return val<_.val;
    }
}a[N];
void __(){
    int n;
    ll p;
    cin>>n>>p;
    ll sum=0,ans=-1,ansl,s1,ansr=0;
    map<ll,int> mp;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        (sum+=x)%=p;
        a[i].id=i;
        a[i].val=sum;
        mp[sum]=i;
    }
    build(1,1,n);
    // for(int i=1;i<=n;i++){
    //     cout<<a[i].val<<" ";
    // }cout<<"----\n";
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        ll Q=query(1,1,n,a[i].id,n);
        if(Q!=-INF){
            ll cal=(p+Q-a[i].val)%p;
            // cout<<a[i].val<<" "<<query(1,1,n,a[i].id,n)<<"++\n";
            if(cal>ans){
                ans=cal;
                ansl=a[i].id;
                s1=a[i].val;
            }
        }
        update(1,1,n,a[i].id,a[i].val);
    }
    // cout<<ans<<"!!\n";
    for(int i=1;i<=n;i++){
        if(a[i].val>ans){
            ans=a[i].val;
            ansl=0;
            ansr=a[i].id;
        }
    }
    if(ansr) cout<<ansl<<" "<<ansr-1<<" "<<ans;
    else cout<<ansl<<" "<<mp[(ans+s1)%p]-1<<" "<<ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    __();
    return 0;
}