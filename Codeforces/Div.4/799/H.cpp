#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
const int INF=1e9;
vector<int> v[N],pos[N];
int T,n,a[N],inv[N],lst[N];
int main(){
   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        map<int,int> mp;set<int> st;int cn=0;
        for(int i=1;i<=n;i++){
            lst[i]=0;
            v[i].clear();pos[i].clear();
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
            st.insert(a[i]);
        }
        for(auto x:st){
            mp[x]=++cn;
            inv[cn]=x;
        }
        for(int i=1;i<=n;i++) a[i]=mp[a[i]];
        for(int i=1;i<=n;i++){
            if(lst[a[i]]==i-1&&i!=1){
                v[a[i]].push_back(1);
                pos[a[i]].push_back(i);
            }
            else{
                v[a[i]].push_back(lst[a[i]]-i+1);
                pos[a[i]].push_back(-1);
                v[a[i]].push_back(1);
                pos[a[i]].push_back(i);
            }
            lst[a[i]]=i;
        }
        int maxx=-INF,ans,ansl,ansr;
        for(int i=1;i<=n;i++){
            for(int j=1;j<v[i].size();j++) v[i][j]+=v[i][j-1];
            int minn=INF,p1;
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]<minn){
                    minn=v[i][j];
                    p1=pos[i][j+1];
                }
                if(maxx<v[i][j]-minn){
                    maxx=v[i][j]-minn;
                    ans=inv[i];
                    ansl=p1;
                    ansr=pos[i][j];
                }
            }
        }
        cout<<ans<<" "<<ansl<<" "<<ansr<<'\n';
    }
    return 0;
}