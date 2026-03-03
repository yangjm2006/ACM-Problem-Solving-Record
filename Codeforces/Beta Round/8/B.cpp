#include<bits/stdc++.h>
using namespace std;
string s;
int mp[300][300],d1[4]={0,0,1,-1},d2[4]={1,-1,0,0};
int main(){
    cin>>s;
    if(s.size()==1){
        cout<<"OK";
        return 0;
    }
    int x=150,y=150;
    mp[x][y]++;
    for(int i=0;i<s.size();i++){
        if(s[i]=='U') x++;
        if(s[i]=='D') x--;
        if(s[i]=='L') y++;
        if(s[i]=='R') y--;
        mp[x][y]++;
    }
    bool f=1;
    for(int i=2;i<=297;i++) for(int j=2;j<=297;j++) if(mp[i][j]){
        if(mp[i][j]>=2) f=0;
        int tot=0;
        for(int k=0;k<=3;k++){
            if(mp[i+d1[k]][j+d2[k]]) tot++;
        }
        if(tot>=3) f=0;
    }
    for(int k=0;k<=3;k++){
       if(x+d1[k]==150&&y+d2[k]==150) f=0;
    }
    if(f) cout<<"OK";
    else cout<<"BUG";
    return 0;
}