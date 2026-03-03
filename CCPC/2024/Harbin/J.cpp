#include<iostream>
#define ll long long
using namespace std;
const int N=2e5+9;
ll a[N],tr[N<<2];
struct node{
	ll add,mul;
}tag[N<<2];
void push_up(int u){
	tr[u]=(tr[u<<1]+tr[u<<1|1]);
}
void build(int u,int l,int r){
	tag[u].mul=1;
	if(l==r) return tr[u]=a[l],void();
	int mid=l+r>>1;
	build(u<<1,l,mid);build(u<<1|1,mid+1,r);
	push_up(u);
}
void update_add(int u,ll add,int len){
	tr[u]=tr[u]+add*len;
	tag[u].add=tag[u].add+add;
}
void update_mul(int u,ll mul){
	tr[u]=tr[u]*mul;
	tag[u].add=tag[u].add*mul;
	tag[u].mul=tag[u].mul*mul;
}
void push_down(int u,int l,int r){
	int mid=l+r>>1;
	if(tag[u].mul!=1) update_mul(u<<1,tag[u].mul);update_mul(u<<1|1,tag[u].mul);
	if(tag[u].add!=0) update_add(u<<1,tag[u].add,mid-l+1);update_add(u<<1|1,tag[u].add,r-mid);
	tag[u].add=0;tag[u].mul=1;
}
void add(int u,int l,int r,int L,int R,ll x){
	if(l>=L&&r<=R) return update_add(u,x,r-l+1),void();
	push_down(u,l,r);
	int mid=l+r>>1;
	if(mid>=L) add(u<<1,l,mid,L,R,x);
	if(mid<R) add(u<<1|1,mid+1,r,L,R,x);
	push_up(u);
}
void mul(int u,int l,int r,int L,int R,ll x){
	if(l>=L&&r<=R) return update_mul(u,x),void();
	push_down(u,l,r);
	int mid=l+r>>1;
	if(mid>=L) mul(u<<1,l,mid,L,R,x);
	if(mid<R) mul(u<<1|1,mid+1,r,L,R,x);
	push_up(u);
}
ll query(int u,int l,int r,int L,int R){
	if(l>=L&&r<=R) return tr[u];
	push_down(u,l,r);
	ll res=0;int mid=l+r>>1;
	if(mid>=L) res+=query(u<<1,l,mid,L,R);
	if(mid<R) res+=query(u<<1|1,mid+1,r,L,R);
	push_up(u);
	return res;
}
ll T,n,m,c[N],lst[N],x[N],t[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m;
		ll tot=0,sum=0;
		for(int i=1;i<=n;i++){
			cin>>c[i];
			sum+=c[i];
			lst[i]=0;
		}
		for(int i=1;i<=m;i++){
			cin>>x[i]>>t[i];
			a[i]=x[i]-x[i-1];
		}
        for(int i=1;i<=4*m;i++) tag[i].add=0;
		build(1,1,m);
		for(int i=1;i<=m;i++){
			if(x[i]>sum+tot) break;
			int L=lst[t[i]]+1;
			int l=L,r=i;
			while(l<r){
				int mid=(l+r>>1)+1; 
				if(query(1,1,m,L,mid)<=c[t[i]]) l=mid;
				else r=mid-1;
			}
            // cout<<i<<":"<<" "<<L<<" "<<l<<"++\n";
			ll tmp=query(1,1,m,L,l);
			if(tmp>c[t[i]]){
				add(1,1,m,l,l,-c[t[i]]);
				tot+=c[t[i]];
			}else{
				tot+=tmp;
				mul(1,1,m,L,l,0);
				if(l+1<=i){
					add(1,1,m,l+1,l+1,-(c[t[i]]-tmp));
					tot+=c[t[i]]-tmp;
				}
			}
			lst[t[i]]=i;
            // for(int j=1;j<=m;j++) cout<<query(1,1,m,j,j)<<" ";cout<<"==\n";
            // for(int j=1;j<=m;j++) cout<<query(1,1,m,1,j)<<" ";cout<<"--\n";
		}
		cout<<sum+tot<<'\n';
	}
	return 0;
}
/*
6

3 1
3 3 3
8 1

2 2
5 2
1 2
2 1

2 2
10 100 
100 1 
105 1

2 2
10 100 
5 1
100 1

4 4
10 2 2 100
100 1
105 2 
107 3
109 1

4 5

10 2 2 100
100 1
105 2 
107 2
109 1
1000 1
*/