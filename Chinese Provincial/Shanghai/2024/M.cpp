#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int m=ceil(sqrt(n));
    vector<pair<int,int>> v1,v2;
    for(int i=1;i<=n;i++){
        if(i%m!=0) v1.push_back(make_pair(i,i+1));
    }
    for(int i=1;i<=m;i++){
        for(int j=1;i+j*m<=n;j++){
            v2.push_back(make_pair(i+(j-1)*m,i+j*m));
        }
    }
    cout<<min(v1.size(),v2.size())<<"\n";
    for(int i=0;i<min(v1.size(),v2.size());i++) cout<<v1[i].first<<" "<<v1[i].second<<'\n';
    for(int i=0;i<min(v1.size(),v2.size());i++) cout<<v2[i].first<<" "<<v2[i].second<<'\n';
}
int main(){
    solve();
    return 0;
}