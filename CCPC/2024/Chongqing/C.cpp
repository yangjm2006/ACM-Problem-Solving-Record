#include"bits/stdc++.h"
using namespace std;
const int N=2e5+100;
int T,n,t1,t2;
string s1,s2,ans[10],tmp;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>s1>>s2;
        bool f1=1,f2=1;
        tmp="";
        for(int i=0;i<n;i++){
            tmp+=".";
            if(s1[i]=='.') f1=0;
            if(s2[i]=='.') f2=0;
        }
        if(f1&&f2){
            cout<<"YES\n";
            for(int i=1;i<=7;i++) cout<<s1<<'\n';
            continue;
        }
        if(f1^f2){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        ans[1]=s1;ans[7]=s2;
        for(int i=0;i<n;i++){
            if(s1[i]=='.') s1[i]='#';
            else s1[i]='.';
        }
        ans[2]=s1;
        for(int i=0;i<n;i++){
            if(s2[i]=='.') s2[i]='#';
            else s2[i]='.';
        }
        ans[6]=s2;
        for(int i=0;i<n;i++){
            if(s1[i]=='.'&&((i>0&&s1[i-1]=='#')||(i<n-1&&s1[i+1]=='#'))) t1=i;
        }
        for(int i=0;i<n;i++){
            if(s2[i]=='.'&&((i>0&&s2[i-1]=='#')||(i<n-1&&s2[i+1]=='#'))) t2=i;
        }
        ans[3]=ans[5]=ans[4]=tmp;
        ans[3][t1]='#';ans[5][t2]='#';
        if(t1>t2) swap(t1,t2);
        if(t1==t2){
            ans[4][t1]='#';
        }else{
            for(int i=t1+1;i<=t2-1;i++) ans[4][i]='#';
            if(ans[4]==tmp) ans[4][t1]='#';
        }
        for(int i=1;i<=7;i++) cout<<ans[i]<<'\n';
    }
    return 0;
}
/*
5
4
#..#
.##.
5
##.#.
.#.##
6
######
.####.
27
.######.######.####.#.#####
.####...####..#.......#####
6
######
######
*/