#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+100;
const ll mod=998244353;
ll ksm(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
    return ans;
}
ll inv(ll a){
    return ksm(a,mod-2);
}
ll tr[N],sum[N];
void pushup(int u){
    tr[u]=tr[u<<1]+tr[u<<1|1];
    sum[u]=sum[u<<1]+sum[u<<1|1];
}
void update(int u,int l,int r,int x,ll y){
    // cout<<u<<" "<<l<<" "<<r<<"---\n";
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
ll a[N],b[N],n;
map<ll,int> mp;
set<ll> st;
pair<ll,ll> cal(int x,int y){
    int pos=find(1,1,n,x);
    ll sr=query(1,1,n,pos+1,n)-*st.upper_bound(b[pos])*(y-x);
    ll sl=*(--st.lower_bound(b[pos]))*(x-1)-query(1,1,n,1,pos-1);
    return make_pair(sr-sl,max(sr,sl));
}
void __(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        st.insert(a[i]);
    }
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++){
        mp[b[i]]=i;
    }
    st.clear();
    for(int i=1;i<=n;i++){
        st.insert(a[i]);
        update(1,1,n,mp[a[i]],a[i]);
        if(i>=3){
            int l=2,r=i-1;
            while(l<r){
                int mid=(l+r>>1)+1;
                if(cal(mid,i).first>=0) l=mid;
                else r=mid-1;
            }
            if(l<i-1) cout<<min(cal(l,i).second,cal(l+1,i).second)%mod*inv(i-2)%mod<<"\n";
            else cout<<cal(l,i).second%mod*inv(i-2)%mod<<"\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    __();
    return 0;
}