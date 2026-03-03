#include<bits/stdc++.h>
using namespace std;
const int N=3e5+100;
int a[N];
void __(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> v1,v2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int minn1=N,pos1;
    for(int i=x+1;i<=y;i++){
        if(a[i]<minn1){
            minn1=a[i];
            pos1=i;
        }
    }
    for(int i=pos1;i<=y;i++){
        v1.push_back(a[i]);
    }
    for(int i=x+1;i<=pos1-1;i++){
        v1.push_back(a[i]);
    }
    for(int i=1;i<=x;i++){
        v2.push_back(a[i]);
    }
    for(int i=y+1;i<=n;i++){
        v2.push_back(a[i]);
    }
    bool f=0;
    for(auto k:v2){
        if(v1.size()!=0&&f==0&&v1[0]<k){
            for(auto m:v1){
                cout<<m<<" ";
            }
            f=1;
        }
        cout<<k<<" ";
    }
    if(f==0){
        for(auto m:v1){
            cout<<m<<" ";
        }
    }
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}