#include<bits/stdc++.h>
using namespace std;
map<int,map<int,int>> mp;
bool check(int id,int x,int y){
    bool f1=1,f2=1,f3=1,f4=1;
    for(int i=0;i<=4;i++){
        if(mp[x+i][y]!=id) f1=0;
        if(mp[x][y+i]!=id) f2=0;
        if(mp[x+i][y+i]!=id) f3=0;
        if(mp[x+i][y-i]!=id) f4=0;
    }
    return f1|f2|f3|f4;
}
int n;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
        char c;
        cin>>c;
        if(c=='C') mp[i][j]=1;
        else if(c=='Q') mp[i][j]=2;
    }
    bool f1=0,f2=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        if(check(1,i,j)) f1=1;
        else if(check(2,i,j)) f2=1;
    if(f1&&f2) cout<<"Too late to know who the winner is";
    else if(f1) cout<<"The winner is little C";
    else if(f2) cout<<"The winner is little Q";
    else cout<<"No winner till now";
}