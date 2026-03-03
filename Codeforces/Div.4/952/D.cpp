#include<bits/stdc++.h>
using namespace std;
int T,n,m;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>m;
        int maxx=0,minx=n,maxy=0,miny=m;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='.') continue;
            maxx=max(maxx,i);
            maxy=max(maxy,j);
            minx=min(minx,i);
            miny=min(miny,j);
        }
        cout<<(maxx+minx)/2<<" "<<(maxy+miny)/2<<'\n';
    }
    return 0;
}