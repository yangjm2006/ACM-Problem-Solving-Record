#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
const int INF=1e9;
int T,n,k;
map<int,int> cnt;
set<int> st;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        st.clear();cnt.clear();
        cin>>n>>k;
        for(int i=1,x;i<=n;i++){
            cin>>x;
            st.insert(x);
            st.insert(x+1);
            cnt[x]++;
        }
        int lst=INF,maxx=-1,ansl,ansr;
        for(auto x:st){
            if(cnt[x]>=k){
                if(lst==INF) lst=x;
                if(x-lst+1>maxx){
                    maxx=x-lst+1;
                    ansl=lst;ansr=x;
                }
            }else lst=INF;
        }
        if(maxx==-1) cout<<"-1\n";
        else cout<<ansl<<" "<<ansr<<'\n';
    }
    return 0;
}