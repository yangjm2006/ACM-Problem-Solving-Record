#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
const int len=700;
const long long vis=(1ll<<32)-1;
struct Query{
    int l,r,id;
    bool operator < (const Query _) const{
        if(l/len==_.l/len){
            if(l/len%2==0) return r<_.r;
            return r>_.r;
        }
        return l<_.l;
    }
}q[N];
int n,m,a[N];
long long ans[N],lcnt,rcnt,sum,lst[N],nxt[N],L=1,R=0,tot[N],ccnt;
void ladd(int x){
    if(tot[a[x]]++==0) ccnt++;
    rcnt+=ccnt;
    lcnt+=min(nxt[x],R+1)-x;
    sum+=lcnt;
    ccnt&=vis;rcnt&=vis;lcnt&=vis;sum&=vis;
}
void ldel(int x){
    sum-=lcnt;
    lcnt-=min(nxt[x],R+1)-x;
    rcnt-=ccnt;
    if(--tot[a[x]]==0) ccnt--;
    ccnt&=vis;rcnt&=vis;lcnt&=vis;sum&=vis;
}
void radd(int x){
    if(tot[a[x]]++==0) ccnt++;
    lcnt+=ccnt;
    rcnt+=x-max(lst[x],L-1);
    sum+=rcnt;
    ccnt&=vis;rcnt&=vis;lcnt&=vis;sum&=vis;
}
void rdel(int x){
    sum-=rcnt;
    rcnt-=x-max(lst[x],L-1);
    lcnt-=ccnt;
    if(--tot[a[x]]==0) ccnt--;
    ccnt&=vis;rcnt&=vis;lcnt&=vis;sum&=vis;
}
void Mo(){
    sort(q+1,q+1+m);
    for(int i=1;i<=m;i++){
        int l=q[i].l,r=q[i].r;
        while(L>l) ladd(--L);
        while(R<r) radd(++R);
        while(L<l) ldel(L++);
        while(R>r) rdel(R--);
        ans[q[i].id]=sum;
    }
}
int mp[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) mp[i]=-1;
    for(int i=1;i<=n;i++){
        lst[i]=mp[a[i]];
        mp[a[i]]=i;
    }
    for(int i=1;i<=n;i++) mp[i]=n+1;
    for(int i=n;i>=1;i--){
        nxt[i]=mp[a[i]];
        mp[a[i]]=i;
    }
    for(int i=1;i<=m;i++){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    Mo();
    for(int i=1;i<=m;i++) cout<<ans[i]<<'\n';
    return 0;
}