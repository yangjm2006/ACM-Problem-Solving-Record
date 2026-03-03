#include<bits/stdc++.h>
using namespace std;
int T,n,num[10];
bool check(int x,int y,int z){
    int cnt[10];
    for(int i=0;i<=9;i++) cnt[i]=num[i];
    cnt[x]--;cnt[y]--;cnt[z]--;
    if(cnt[x]>=0&&cnt[y]>=0&&cnt[z]>=0) return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        for(int i=0;i<=9;i++) num[i]=0;
        cin>>n;
        for(int i=1,x;i<=n;i++){
            cin>>x;
            num[x%10]++;
        }
        bool f=0;
        for(int i=0;i<=9;i++) for(int j=0;j<=9;j++) for(int k=0;k<=9;k++) if((i+j+k)%10==3){
            if(check(i,j,k)) f=1;
        }
        if(f) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}