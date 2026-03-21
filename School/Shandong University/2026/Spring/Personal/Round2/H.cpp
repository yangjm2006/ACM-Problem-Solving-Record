#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int tr1[N<<2],tr2[N<<2],a[N],b[N];
void pushup2(int u){
    tr2[u]=tr2[u<<1]^tr2[u<<1|1];
}
void build2(int u,int l,int r){
    if(l==r) return tr2[u]=b[l],void();
    int mid=l+r>>1;
    build2(u<<1,l,mid);
    build2(u<<1|1,mid+1,r);
    pushup2(u);
}
int query2(int u,int l,int r,int L,int R){
    if(l>=L&&r<=R) return tr2[u];
    int mid=l+r>>1;
    int tmp=0;
    if(L<=mid) tmp^=query2(u<<1,l,mid,L,R);
    if(R>mid) tmp^=query2(u<<1|1,mid+1,r,L,R);
    return tmp;
}
void update2(int u,int l,int r,int x,int y){
    if(l==r) return tr2[u]=y,void();
    int mid=l+r>>1;
    if(x<=mid) update2(u<<1,l,mid,x,y);
    else update2(u<<1|1,mid+1,r,x,y);
    pushup2(u);
}
void pushup1(int u){
    tr1[u]=tr1[u<<1]^tr1[u<<1|1];
}
void build1(int u,int l,int r){
    if(l==r) return tr1[u]=a[l],void();
    int mid=l+r>>1;
    build1(u<<1,l,mid);
    build1(u<<1|1,mid+1,r);
    pushup1(u);
}
int query1(int u,int l,int r,int L,int R){
    if(l>=L&&r<=R) return tr1[u];
    int mid=l+r>>1;
    int tmp=0;
    if(L<=mid) tmp^=query1(u<<1,l,mid,L,R);
    if(R>mid) tmp^=query1(u<<1|1,mid+1,r,L,R);
    return tmp;
}
struct Query{
    int l,r,id;
    bool operator < (const Query &_) const{
        return l<_.l;
    }
}q[N];
int nxt[N];
map<int,int> mp;
int ans[N];
void __(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        nxt[i]=mp[a[i]];
        mp[a[i]]=i;
    }
    for(auto &x:mp){
        b[x.second]=x.first;
    }
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    build1(1,1,n);
    build2(1,1,n);
    sort(q+1,q+1+m);
    int tp=1;
    for(int i=1;i<=m;i++){
        int id=q[i].id,l=q[i].l,r=q[i].r;
        while(tp<l){
            update2(1,1,n,tp,a[tp]);
            update2(1,1,n,nxt[tp],a[tp]);
            tp++;
        }
        ans[id]^=query1(1,1,n,l,r);
        ans[id]^=query2(1,1,n,l,r);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    __();
    return 0;
}