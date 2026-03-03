#include"bits/stdc++.h"
using namespace std;
const int N=2e3+100;
struct node{
    int op,x1,x2,y1,y2,r;char c;
}p[N];
int main(){
    // cerr<<"!\n";
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        string s;
        cin>>s;
        if(s=="Circle"){
            p[i].op=1;
            cin>>p[i].x1>>p[i].y1>>p[i].r>>p[i].c;
        }else if(s=="Rectangle"){
            p[i].op=2;
            cin>>p[i].x1>>p[i].y1>>p[i].x2>>p[i].y2>>p[i].c;
        }else{
            p[i].op=3;
            cin>>p[i].x1>>p[i].y1>>p[i].x2>>p[i].y2;
            map<int,map<int,char>> mp;
            for(int k=1;k<=i;k++){
                if(p[k].op==3) continue;
                if(p[k].op==2){
                    for(int y=p[i].y2;y>=p[i].y1;y--){
                        for(int x=p[i].x1;x<=p[i].x2;x++)
                            if(x>=p[k].x1&&x<=p[k].x2&&y>=p[k].y1&&y<=p[k].y2) mp[x][y]=p[k].c;
                    }
                }else{
                    for(int y=p[i].y2;y>=p[i].y1;y--){
                        for(int x=p[i].x1;x<=p[i].x2;x++)
                            if(1ll*(x-p[k].x1)*(x-p[k].x1)+1ll*(y-p[k].y1)*(y-p[k].y1)<=1ll*p[k].r*p[k].r) mp[x][y]=p[k].c;
                    }
                }
            }
            for(int y=p[i].y2;y>=p[i].y1;y--){
                for(int x=p[i].x1;x<=p[i].x2;x++)
                if(mp[x][y]==0) cout<<'.';
                else cout<<mp[x][y];
                cout<<'\n';
            }
        }
    }
    return 0;
}
/*
7
Circle 0 0 5 *
Circle -2 2 1 @
Circle 2 2 1 @
Rectangle 0 -1 0 0 ^
Rectangle -2 -2 2 -2 _
Render -5 -5 5 5
Render -1 0 1 2
*/ 