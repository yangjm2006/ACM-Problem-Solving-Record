#include"bits/stdc++.h"
using namespace std;
struct node{
    int id,t;
    bool operator < (const node &x) const{
        return t<x.t;
    }
};
vector<node> v1,v2;
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(c&&d){
            if(a<b) v1.push_back((node){i,a});
            else v2.push_back((node){i,b});
        }else if(c) v1.push_back((node){i,a});
        else v2.push_back((node){i,b});
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    cout<<v1.size()<<" ";for(auto &x:v1) cout<<x.id<<" ";cout<<'\n';
    cout<<v2.size()<<" ";for(auto &x:v2) cout<<x.id<<" ";cout<<'\n';
    return 0;
}
/*
 8
 9 11 0 1
 1 8 0 1
 15 7 1 0
 3 13 1 1
 6 12 0 1
 16 5 1 0
 4 2 1 0
 10 14 1 0
*/