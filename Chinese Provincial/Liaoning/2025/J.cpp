#include<bits/stdc++.h>
using namespace std;
const int N=4e5+100;
vector<int> v[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int id,x;
            cin>>id>>x;
            v[id].push_back(x);
        }else if(op==2){
            int id1,p1,id2,p2;
            cin>>id1>>p1>>id2>>p2;
            swap(v[id1][p1-1],v[id2][p2-1]);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<v[i].size()<<" ";
        for(auto x:v[i]) cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
}