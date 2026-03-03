#include<bits/stdc++.h>
using namespace std;
void solve(){
    // cout<<"----------------\n";
    int n;
    cin>>n;
    if(n==2){
        cout<<"-1\n";
    }else if(n==3){
        cout<<"1 3\n2 3\n";
    }else if(n==4){
        cout<<"2 1\n2 3\n2 4\n";
    }else if(n==5){
        cout<<"1 4\n4 5\n2 5\n3 5\n";
    }else if(n==6){
        cout<<"1 2\n1 3\n1 4\n1 6\n2 5\n";
    }
    else{
        for(int i=1;i<=n;i++){
            if(i!=n-4&&i!=2) cout<<"2 "<<i<<'\n';
        }
        cout<<"1 "<<n-4<<"\n";
    }
}
int main(){
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
/*
7
2
3
4
5
6
7
8
*/