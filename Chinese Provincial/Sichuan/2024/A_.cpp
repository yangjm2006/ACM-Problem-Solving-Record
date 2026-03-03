#include"bits/stdc++.h"
using namespace std;
const int N=3e5+100;
int n,a[N],mp[200][200];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
        if(a[i]>a[j]) mp[i][a[j]]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout<<mp[i][j]<<" ";
        cout<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
/*
9
 5 9 1 8 2 6 4 7 3
*/