#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        map<string,int> mp;
        vector<string> v[4];
        for(int o=1;o<=3;o++){
            for(int i=1;i<=n;i++){
                string s;
                cin>>s;
                mp[s]++;
                v[o].push_back(s);
            }
        }
        for(int o=1;o<=3;o++){
            int ans=0;
            for(int i=0;i<n;i++){
                int x=mp[v[o][i]];
                if(x==1) ans+=3;
                else if(x==2) ans++;
            }
            cout<<ans<<" ";
        }
        cout<<'\n';
    }
    return 0;
}