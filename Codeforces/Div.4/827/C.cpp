#include<bits/stdc++.h>
using namespace std;
void solve(){
    map<int,map<int,int>> mp;
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            char c;
            cin>>c;
            if(c=='B') mp[i][j]=1;
            else if(c=='R') mp[i][j]=2;
        }
    }
    for(int i=1;i<=8;i++){
        bool f1=1,f2=1;
        for(int j=1;j<=8;j++){
            if(mp[i][j]!=2) f2=0;
        }
        if(f2){
            cout<<"R\n";
            return;
        }
        for(int j=1;j<=8;j++){
            if(mp[j][i]!=1) f1=0;
        }
        if(f1){
            cout<<"B\n";
            return;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}