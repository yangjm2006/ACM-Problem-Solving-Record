#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+100;
const ll mod=998244353;
const ll INF=1e9;
struct Tree{
    ll mul,add;
}tr[N*4];
ll a[N],b[N];
Tree push_up(Tree ls,Tree rs){
    Tree u;
    u.mul=ls.mul*rs.mul%mod;
    u.add=(ls.add*rs.mul+rs.add)%mod;
    return u;
}
void build(int u,int l,int r){
    if(l==r){
        tr[u].mul=a[l];
        if(a[l]==1) tr[u].add=b[l];
        else tr[u].add=0;
        return;
    }
    int mid=l+r>>1;
    build(u<<1,l,mid);build(u<<1|1,mid+1,r);
    tr[u]=push_up(tr[u<<1],tr[u<<1|1]);
}
Tree query(int u,int l,int r,int L,int R){
    if(L>R) return (Tree){1,0};
    if(l>=L&&r<=R) return tr[u];
    int mid=l+r>>1;
    if(mid>=L&&mid+1<=R) return push_up(query(u<<1,l,mid,L,R),query(u<<1|1,mid+1,r,L,R));
    if(mid>=L) return query(u<<1,l,mid,L,R);
    return query(u<<1|1,mid+1,r,L,R);
}
ll n,q,s[N];
int nxt[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        char c1,c2;
        ll x,y;
        cin>>c1>>x>>c2>>y;
        if(c1=='+'&&c2=='+'){
            a[i]=1;b[i]=max(x,y);
        }else if(c1=='+'&&c2=='*'){
            a[i]=y;b[i]=x;
        }else if(c1=='*'&&c2=='+'){
            a[i]=x;b[i]=y;
        }else{
            a[i]=max(x,y);b[i]=0;
        }
    }
    build(1,1,n);
    int lst=n+1;
    for(int i=n;i>=1;i--){
        nxt[i]=lst;
        if(a[i]>1){
            lst=i;
        }
    }
    for(int i=n;i>=1;i--) s[i]=s[i+1]+b[i];
    cin>>q;
    while(q--){
        int l,r;ll x;
        cin>>x>>l>>r;
        while(l<=r){
            if(a[l]>1){
                if(x*a[l]>=x+b[l]) x*=a[l];
                else x+=b[l];
                l++;
            }else{
                int to=min(r+1,nxt[l]);
                x+=s[l]-s[to];
                l=to;
            }
            if(x>=INF){
                x%=mod;
                Tree t=query(1,1,n,l,r);
                x=(x*t.mul+t.add)%mod;
                l=r+1;
            }
        }
        cout<<x%mod<<'\n';
    }
    return 0;
}
/*
 10
 +3 +1
 +4 *1
 *5 *9
 *2 +6
 +5 +3
 +100 *2
 +99 *3
 +10 *14
 *1000000000 +100
 *2 +10000
 6
 1 1 4
 5 4 5
 10 1 10
 1 1 10
 1 2 9
 3 3 7
*/