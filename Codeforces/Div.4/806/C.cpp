#include"bits/stdc++.h"
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin>>v[i];
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            string s;
            cin>>s;
            for(auto c:s)
                if(c=='U') v[i]--;
                else v[i]++;
        }
        for(int i=1;i<=n;i++) cout<<(v[i]%10+10)%10<<' ';
        cout<<'\n';
    }
    return 0;
}