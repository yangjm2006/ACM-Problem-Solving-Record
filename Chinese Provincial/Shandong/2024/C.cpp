#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
const int N=2e6+100;
int T,n;
ll k,s[N],ans;
set<int> st;
unordered_map<int,int> mp;
struct node{
    int l,r;
    bool operator < (const node &x) const{
        if(l==x.l) return r<x.r;
        return l<x.l;
    }
}p[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        ans=1;
        st.clear();mp.clear();
        cin>>n>>k;
        for(int i=1;i<=2*n;i++) s[i]=0;
        for(int i=1;i<=n;i++){
            cin>>p[i].l>>p[i].r;
            st.insert(p[i].l);st.insert(p[i].r);
        }
        int res=0;
        for(auto x:st){
            mp[x]=++res;
        }
        for(int i=1;i<=n;i++){
            p[i].l=mp[p[i].l];
            p[i].r=mp[p[i].r];
        }
        sort(p+1,p+1+n);
        int l=1;
        for(int i=1;i<=n;i++){
            while(l<=p[i].l){
                s[l]+=s[l-1];
                l++;
            }
            if(k-s[l-1]<=0) ans=0;
            else ans=ans*(k-s[l-1])%mod;
            s[l-1]++;
            s[p[i].r+1]--;
        }
        cout<<ans<<'\n';
    }
    return 0;
}