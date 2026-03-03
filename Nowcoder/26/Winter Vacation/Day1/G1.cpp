#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;
typedef pair<ll,ll> PII;
typedef array<ll,2> a2;
typedef array<ll,3> a3;

ll l,r;

ll a[N];

ll mi[N];

bool check(ll x){
    ll yushu=0;
    for(int i=x;i>=0;i--) yushu=yushu*10+a[i];
    ll l1=l/mi[x+1],r1=r/mi[x+1];
    if(r1>l1+1) return true;
    else if(r1==l1+1){
        if(yushu>=l%mi[x+1]||yushu<=r%mi[x+1]) return true;
        else return false;
    }else{
        if(yushu>=l%mi[x+1]&&yushu<=r%mi[x+1]) return true;
        else return false;
    }
}


ll cal(){
    
    mi[0]=1;
    for(int i=1;i<=17;i++) mi[i]=mi[i-1]*10;
    for(int i=0;i<=15;i++){
        for(int j=9;j>=0;j--){
            a[i]=j;
            if(check(i)) break; 
        }
        
    }
    vector<int> v;
    for(int i=0;i<=15;i++) v.push_back(a[i]);
    while(v.back()==0) v.pop_back();
    ll sum=0;
    for(auto j:v) sum=sum*10+j;
    return sum;
}

void __(){
    cin>>l>>r;
    ll ans=cal();
    string s1=to_string(l),s2=to_string(r);
    if(s1.size()==s2.size()){
        cout<<ans<<"\n";
        return;
    }
    ll val=1;
    while(val*10<=r) val*=10;
    l=val;
    ans=max(ans,cal());
    cout<<ans<<"\n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _=1;
    cin>>_;
    while(_--){
        __();
    }
}
