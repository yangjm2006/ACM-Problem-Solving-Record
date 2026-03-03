#include<bits/stdc++.h>
using namespace std;
void solve(){
    // cout<<"--------------------------------\n";
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    set<int> st;
    for(int i=1;i<=n;i++) st.insert(i);
    int minn=n+1;
    set<pair<int,int>> ans;
    for(int i=1;i<=n;i++){
        st.erase(a[i]);
        while(st.upper_bound(a[i])!=st.end()){
            ans.insert(make_pair(a[i],*st.upper_bound(a[i])));
            // cout<<a[i]<<" "<<*st.upper_bound(a[i])<<"++\n";
            st.erase(st.upper_bound(a[i]));
        }
        minn=min(minn,a[i]);
    }
    st.clear();
    for(int i=1;i<=n;i++) st.insert(i);
    minn=n+1;
    for(int i=1;i<=n;i++){
        st.erase(a[i]);
        if(st.size()>=1&&a[i]<minn&&*prev(st.end())>a[i]){
            ans.insert(make_pair(a[i],*prev(st.end())));
            // cout<<a[i]<<" "<<*prev(st.end())<<"++\n";
        }
        minn=min(minn,a[i]);
    }
    if(ans.size()==n-1){
        cout<<"YES\n";
        for(auto &x:ans) cout<<x.first<<" "<<x.second<<"\n";
    }else cout<<"NO\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}