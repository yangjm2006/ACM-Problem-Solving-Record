#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int gcd(int a,int b){
    return a%b?gcd(b,a%b):b;
}
int T,n;
vector<int> v[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=2;i<N;i++) for(int j=i;j<N;j+=i) v[j].push_back(i);
    cin>>T;
    while(T--){
        cin>>n;
        int ans=0,g=0;
        vector<int> f(N,0);
        for(int i=1,x;i<=n;i++){
            cin>>x;
            if(!g) g=x;
            for(auto &u:v[x]){
                f[u]++;
                if(f[u]!=i) ans=max(ans,f[u]);
            }
            if(g!=gcd(x,g)){
                ans=max(ans,i-1);
                g=gcd(x,g);
            }
            cout<<ans<<' ';
        }
        cout<<'\n';
    }
    return 0;
}