#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+100;
int n,s[4][N],a,a1[N],b1[N],c1[N],a2[N],b2[N],c2[N],ans=0;
set<int> s1,s2,s3;
map<int,int> mp1,mp2,mp3;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>a>>a>>a;
    for(int i=1;i<=n;i++){
        cin>>a1[i]>>b1[i]>>c1[i]>>a2[i]>>b2[i]>>c2[i];
        if(a1[i]>a2[i]) swap(a1[i],a2[i]);
        if(b1[i]>b2[i]) swap(b1[i],b2[i]);
        if(c1[i]>c2[i]) swap(c1[i],c2[i]);
        s1.insert(a1[i]);s1.insert(a2[i]);
        s2.insert(b1[i]);s2.insert(b2[i]);
        s3.insert(c1[i]);s3.insert(c2[i]);
    }
    int res=0;
    for(auto x:s1){
        mp1[x]=++res;
    }
    res=0;
    for(auto x:s2){
        mp2[x]=++res;
    }
    res=0;
    for(auto x:s3){
        mp3[x]=++res;
    }
    for(int i=1;i<=n;i++){
        a1[i]=mp1[a1[i]];a2[i]=mp1[a2[i]];
        b1[i]=mp2[b1[i]];b2[i]=mp2[b2[i]];
        c1[i]=mp3[c1[i]];c2[i]=mp3[c2[i]];
        s[1][a1[i]]++;s[1][a2[i]+1]--;
        s[2][b1[i]]++;s[2][b2[i]+1]--;
        s[3][c1[i]]++;s[3][c2[i]+1]--;
    }
    for(int i=1;i<=2*n;i++){
        s[1][i]+=s[1][i-1];
        s[2][i]+=s[2][i-1];
        s[3][i]+=s[3][i-1];
    }
    for(int i=1;i<=2*n;i++){
        ans=max(ans,s[1][i]);
        ans=max(ans,s[2][i]);
        ans=max(ans,s[3][i]);
    }
    cout<<ans;
    return 0;
}