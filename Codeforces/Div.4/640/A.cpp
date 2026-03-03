#include<bits/stdc++.h>
using namespace std;
int T,x;
vector<int> v;
int main(){
    cin>>T;
    while(T--){
        v.clear();
        cin>>x;
        int vis=1;
        while(x){
            if(x%10) v.push_back(x%10*vis);
            vis*=10;x/=10;
        }
        cout<<v.size()<<'\n';
        for(auto y:v) cout<<y<<" ";
        cout<<'\n';
    }
    return 0;
}