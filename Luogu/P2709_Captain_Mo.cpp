#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
ll len;
struct Query{
    int l,r,id;
    bool operator < (const Query &x) const{
        if(l/len==x.l/len){
            if(l/len%2) r>x.r;
            else r<x.r;
        }
        return l<x.l;
    }
}q[N];
ll n,m,k,a[N],cnt[N],ans[N],tot;
void add(int pos){
    cnt[a[pos]]++;
    tot+=cnt[a[pos]]*2-1;
}
void del(int pos){
    tot-=cnt[a[pos]]*2-1;
    cnt[a[pos]]--;
}
int curl=1,curr=0;
void Mo(){
    sort(q+1,q+1+m);
    for(int i=1;i<=m;i++){
        while(curl>q[i].l) add(--curl);
        while(curr<q[i].r) add(++curr);
        while(curl<q[i].l) del(curl++);
        while(curr>q[i].r) del(curr--);
        ans[q[i].id]=tot;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    len=n/sqrt(m);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>q[i].l>>q[i].r,q[i].id=i;
    Mo();
    for(int i=1;i<=m;i++) cout<<ans[i]<<'\n';
    return 0;
}