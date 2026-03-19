#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+100;
int a1[N],a2[N],a3[N];
map<pair<int,int>,int> mp12,mp13,mp23;
map<int,int> mp1,mp2,mp3;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++){
        cin>>a1[i]>>a2[i]>>a3[i];
        mp1[a1[i]]++;
        mp2[a2[i]]++;
        mp3[a3[i]]++;
        mp12[make_pair(a1[i],a2[i])]++;
        mp13[make_pair(a1[i],a3[i])]++;
        mp23[make_pair(a2[i],a3[i])]++;
    }
    for(int i=1;i<=n;i++){
        ll b12=mp12[make_pair(a1[i],a2[i])],b13=mp13[make_pair(a1[i],a3[i])],b23=mp23[make_pair(a2[i],a3[i])];
        ll o1=mp1[a1[i]],o2=mp2[a2[i]],o3=mp3[a3[i]];
        b12--;b13--;b23--;
        o1--;o2--;o3--;
        o1-=b12+b13;
        o2-=b12+b23;
        o3-=b13+b23;
        ll b=b12+b13+b23,o=o1+o2+o3;
        ans+=b*(b-1)/2+b*o+o1*o2+o2*o3+o1*o3;
    }
    cout<<ans;
    return 0;
}