#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+100;
ll n,m,a[N],to[N],len,cnt[N],ansl,ansr,ans[N],curl,curr,lt;
struct Query{
    int l,r,id;
    bool operator < (const Query &x) const{
        if((l-1)/len==(x.l-1)/len) return r<x.r;
        return l<x.l;
    }
}q[N];
void addl(int pos){
    cnt[a[pos]]++;
    ansl=max(ansl,cnt[a[pos]]*to[a[pos]]);
}
void addr(int pos){
    cnt[a[pos]]++;
    ansr=max(ansr,cnt[a[pos]]*to[a[pos]]);
}
void del(int pos){
    cnt[a[pos]]--;
}
void cal(int x,int y){
    for(int i=x;i<=y;i++) addl(i);
    for(int i=x;i<=y;i++) del(i);
}
void Mo(){
    len=sqrt(n);
    sort(q+1,q+1+m);
    lt=-1;
    for(int i=1;i<=m;i++){
        if(q[i].l>lt){
            for(int j=1;j<=n;j++) cnt[j]=0;
            curl=lt=((q[i].l-1)/len+1)*len;curr=curl-1;
            ansr=0;
        }
        ansl=0;
        if(q[i].r<=lt){
            cal(q[i].l,q[i].r);
            ans[q[i].id]=ansl;
            continue;
        }
        while(curl<lt) del(curl++);
        while(curr<q[i].r) addr(++curr);
        while(curl>q[i].l) addl(--curl);
        ans[q[i].id]=max(ansl,ansr);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    map<int,int> mp;set<int> st;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        st.insert(a[i]);
    }
    int cn=0;
    for(auto x:st){
        mp[x]=++cn;
        to[cn]=x;
    }
    for(int i=1;i<=n;i++) a[i]=mp[a[i]];
    for(int i=1;i<=m;i++) cin>>q[i].l>>q[i].r,q[i].id=i;
    Mo();
    for(int i=1;i<=m;i++) cout<<ans[i]<<'\n';
    return 0;
}