#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+100;
struct node{
    ll a,b,id;
    bool operator < (const node &x) const{
        return a>x.a;
    }
}p[N];
ll T,n,s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        s=0;
        cin>>n;
        n=2*n-1;
        for(int i=1;i<=n;i++){
            cin>>p[i].a>>p[i].b;
            p[i].id=i;
            s+=p[i].b;
        }
        sort(p+1,p+1+n);
        ll s1=0;
        for(int i=1;i<=n;i+=2){
            s1+=p[i].b;
        }
        vector<int> v;
        if(s1*2>=s){
            for(int i=1;i<=n;i+=2) v.push_back(p[i].id);
        }else{
            v.push_back(p[1].id);
            for(int i=2;i<=n;i+=2) v.push_back(p[i].id);
        }
        sort(v.begin(),v.end());
        cout<<"YES\n";
        for(auto x:v) cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
}