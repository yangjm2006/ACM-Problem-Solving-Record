#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,s;
bool f;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        if(s%2) f=1;
        s=s/2-(bool(s<0)*bool(s%2));
        s+=x;
        if(s<0){
            cout<<"-";
        }else if(s==0&&f==0){
            cout<<"0";
        }else{
            cout<<"+";
        }
    }
    return 0;
}
/*
10
2 -1 4 -7 4 -8 3 -6 4 -7
*/