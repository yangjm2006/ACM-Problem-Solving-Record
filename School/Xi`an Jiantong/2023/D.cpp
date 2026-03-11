#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    int xmin=INF,xmax=-INF,ymin=INF,ymax=-INF;
    for(int i=1,x,y;i<=n;i++){
        cin>>x>>y;
        xmax=max(xmax,x);
        xmin=min(xmin,x);
        ymax=max(ymax,y);
        ymin=min(ymin,y);
    }
    if(n!=(xmax-xmin+1)*(ymax-ymin+1)||xmin>0||ymin>0||xmax<0||ymax<0) cout<<"-1";
    else cout<<xmax-xmin+ymax-ymin;
    return 0;
}