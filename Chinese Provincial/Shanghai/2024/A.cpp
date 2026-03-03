#include<bits/stdc++.h>
using namespace std;
const int N=105;
bool b[10005];
int c[N][N];

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>numx;
    for(int i=1;i<=n*m;i++){
        int w=sqrt(i);
        if(w*w==i){
            numx.emplace_back(i);
            b[i]=1;
        }
    }
    for(int bian=1;bian<=n*m;bian++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                bool op2 = 0;
                for(int x:numx){
                    if(x>bian)break;
                    if(x==bian){
                        pair<int,int>node[3];
                        node[0]=make_pair(i+sqrt(x),j);
                        node[1]=make_pair(i+sqrt(x),j+sqrt(x));
                        node[2]=make_pair(i,j+sqrt(x));
                        bool opx = 1;
                        for(auto [ax,ay]:node){
                            if(ax>n||ay>m){
                                opx=0;
                                break;
                            }
                        }
                        if(opx){
                            op2 = 1;
                            for(auto [ax,ay]:node){
                               c[ax][ay]++;
                            }
                            c[i][j]++;
                        }
                    }
                    else{
                        int w1=x,w2=bian-x;
                        if(!b[w2])continue;
                        pair<int,int>node[3];
                        node[0]=make_pair(i+sqrt(w1),j+sqrt(w2));
                        node[1]=make_pair(i+sqrt(w1)-sqrt(w2),j+sqrt(w2)+sqrt(w1));
                        node[2]=make_pair(i-sqrt(w2),j+sqrt(w1));
                        bool opx = 1;
                        for(auto [ax,ay]:node){
                            if(ax>n||ax<0||ay>m||ay<0){
                                opx=0;
                                break;
                            }
                        }
                        if(opx){
                            op2 = 1;
                            for(auto [ax,ay]:node){
                               c[ax][ay]++;
                            }
                            c[i][j]++;
                        }
                    }
                }
                if(!op2)break;
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<c[i][j]<<' ';
        }
        cout<<endl;
    }
    
}
int main(){
    solve();
    return 0;
}