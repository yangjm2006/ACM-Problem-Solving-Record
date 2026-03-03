#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,q,s[3][N];
set<int> st[3];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        s[x%3][i]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            s[j][i]+=s[j][i-1];
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        if(s[0][r]-s[0][l]>=1||(s[1][r]-s[1][l]>=1&&s[2][r]-s[2][l]>=1)||s[2][r]-s[2][l]>=3||s[1][r]-s[1][l]>=3) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}