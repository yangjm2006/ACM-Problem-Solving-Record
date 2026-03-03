#include<bits/stdc++.h>
#define ll unsigned long long
#define db double
using namespace std;
const ll mod=998244353;
const int N=1e6+100;
const ll base=1e9+7;
int len=600;
struct query{
    int l,r,id;
    bool operator < (const query &x) const{
        if(l/len==x.l/len){
            if(l/len%2==0) return r>x.r;
            return r<x.r;
        }
        return l<x.l;
    }
}qu[N];
ll n,k,q,a[N],ans[N],b[N],s[N],cnt[N],as;
void add(int pos){
    as+=cnt[s[pos]];
    cnt[s[pos]]++;
}
void del(int pos){
    cnt[s[pos]]--;
    as-=cnt[s[pos]];
}
void Mo(){
    int L=1,R=0;
    for(int i=1;i<=q;i++){
        int l=qu[i].l,r=qu[i].r;
        while(R<r) add(++R);
        while(L>l) add(--L);
        while(R>r) del(R--);
        while(L<l) del(L++);
        ans[qu[i].id]=as;
    }
}
string str;
set<ll> st;
map<ll,int> mp;
ll tot[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k>>q;
    cin>>str;
    for(int i=1;i<=n;i++) a[i]=str[i-1]-'a'+1;
    b[1]=1;
    for(int i=2;i<=26;i++) b[i]=b[i-1]*base;
    for(int i=1;i<=n;i++){
        tot[a[i]]++;
        s[i]=s[i-1]+b[a[i]];
        if(tot[a[i]]%k==0) s[i]-=b[a[i]]*k;
        st.insert(s[i]);
    }
    st.insert(0);
    s[0]=1;
    int res=0;
    for(auto x:st){
        mp[x]=++res;
    }
    for(int i=1;i<=n;i++) s[i]=mp[s[i]];
    // for(int i=1;i<=n;i++) cout<<s[i]<<" ";cout<<"---------\n";
    for(int i=1;i<=q;i++){
        cin>>qu[i].l>>qu[i].r;
        qu[i].l--;
        qu[i].id=i;
    }
    sort(qu+1,qu+1+q);
    Mo();
    for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
    return 0;
}