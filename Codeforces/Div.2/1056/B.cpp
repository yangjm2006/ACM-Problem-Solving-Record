#include<bits/stdc++.h>
using namespace std;
int T,n,m;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        m=n*n-m;
        if(n==1){
            if(m) cout<<"NO\n";
            else cout<<"YES\nU\n";
        }else{
            if(m==1) cout<<"NO\n";
            else if(m==0){
                cout<<"YES\n";
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=n;j++) cout<<"U";
                    cout<<'\n';
                }
            }else{
                cout<<"YES\n";
                cout<<"RL";
                m-=2;
                for(int i=3;i<=n;i++){
                    if(m-->0) cout<<"L";
                    else cout<<"R";
                }
                cout<<'\n';
                for(int i=2;i<=n;i++){
                    for(int j=1;j<=n;j++){
                        if(m-->0){
                            if(j==1) cout<<"U";
                            else cout<<"L";
                        }else cout<<"R";
                    }
                    cout<<'\n';
                }
            }
        }
    }
    return 0;
}