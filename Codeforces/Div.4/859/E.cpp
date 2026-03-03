#include<bits/stdc++.h>
using namespace std;
const int N=2e6+100;
int n,a[N];
void solve(){
    cin>>n;
    int tmp=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int k=0;k<=20;k++){
        vector<int> v;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(i&(1<<k)){
                v.push_back(i);
                sum+=a[i];
            }
        }
        if(v.empty()) continue;
        cout<<"? "<<v.size()<<" ";
        for(auto x:v) cout<<x<<" ";
        cout<<'\n';
        cout.flush();
        int ans;
        cin>>ans;
        if(ans!=sum) tmp|=(1<<k);
    }
    cout<<"! "<<tmp<<'\n';
    cout.flush();
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}