#include"bits/stdc++.h"
#define ll long long
using namespace std;
const int N=3e5+100;
struct Tree{
    bool l,r;
    int cnt;
}tr[N<<2];
Tree push_up(Tree ls,Tree rs){
    Tree fa;
    fa.cnt=ls.cnt+rs.cnt;
    fa.l=ls.l;fa.r=rs.r;
    if(ls.r&&rs.l) fa.cnt--;
    return fa;
}
void build(int u,int l,int r){
    if(l==r) return tr[u].cnt=tr[u].l=tr[u].r=1,void();
    int mid=l+r>>1;
    build(u<<1,l,mid);build(u<<1|1,mid+1,r);
    tr[u]=push_up(tr[u<<1],tr[u<<1|1]);
}
void update(int u,int l,int r,int x){
    if(l==r) return tr[u].cnt=tr[u].l=tr[u].r=0,void();
    int mid=l+r>>1;
    if(mid>=x) update(u<<1,l,mid,x);
    else update(u<<1|1,mid+1,r,x);
    tr[u]=push_up(tr[u<<1],tr[u<<1|1]);
}
Tree query(int u,int l,int r,int L,int R){
    if(R<L) return (Tree){0,0,0};
    if(l>=L&&r<=R) return tr[u];
    int mid=l+r>>1;
    if(mid>=L&&mid<R) return push_up(query(u<<1,l,mid,L,R),query(u<<1|1,mid+1,r,L,R));
    else if(mid>=L) return query(u<<1,l,mid,L,R);
    else return query(u<<1|1,mid+1,r,L,R);
}
int n,a[N];
ll ans;
void solve(){
    cin>>n;
    build(1,1,n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(1,1,n,a[i]);
        if(a[i]>a[i-1]){
            ans+=query(1,1,n,a[i-1],a[i]).cnt;
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}