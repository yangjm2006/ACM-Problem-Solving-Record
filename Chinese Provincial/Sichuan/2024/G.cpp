#include<bits/stdc++.h>
using namespace std;
const int N=3e5+100;
int n,q,a[N],tot;
struct Tree{
    int ch[2];
}tr[N*31];
int insert(int x){
    int u=0;
    for(int k=30,c;k>=0;k--){
        if(x&(1<<k)) c=1;
        else c=0;
        if(!tr[u].ch[c]) tr[u].ch[c]=++tot;
        u=tr[u].ch[c];
    }
    return u;
}
map<int,int> mp;
int getmax(int x){
    int u=0;
    for(int k=30,c;k>=0;k--){
        if(x&(1<<k)) c=1;
        else c=0;
        if(tr[u].ch[!c]) u=tr[u].ch[!c];
        else u=tr[u].ch[c];
    }
    return mp[u];
}
int getmin(int x){
    int u=0;
    for(int k=30,c;k>=0;k--){
        if(x&(1<<k)) c=1;
        else c=0;
        if(tr[u].ch[c]) u=tr[u].ch[c];
        else u=tr[u].ch[!c];
    }
    return mp[u];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int u=insert(a[i]);
        if(!mp[u]) mp[u]=i;
    }
    for(int i=1,x,y;i<=q;i++){
        cin>>x>>y;
        int l=getmin(x),r=getmax(x);
        if(1ll*((a[l]^x)-y)*((a[r]^x)-y)>0){
            cout<<"-1\n";
            continue;
        }
        if(l>r) swap(l,r);
        if((a[l]^x)==y){
            if(l==n)cout<<l-1<<"\n";
            else cout<<l<<'\n';
            continue;
        }

        int L=l;
        while(l<r){
            int mid=(l+r>>1)+1;
            if(1ll*((a[mid]^x)-y)*((a[L]^x)-y)>0) l=mid;
            else r=mid-1;
        }
        cout<<l<<'\n';
    }
    return 0;
}