#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,a[N],pos1,pos2,posmax,posmin,maxx,minn;
bool f=0;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    maxx=minn=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]>maxx){
            maxx=a[i];
            posmax=i;
        }
        if(maxx!=a[1]&&a[i]<maxx){
            pos1=posmax;
            pos2=i;
            f=1;
        }
        if(a[i]<minn){
            minn=a[i];
            posmin=i;
        }
        if(minn!=a[1]&&a[i]>minn){
            pos1=posmin;
            pos2=i;
            f=1;
        }
    }
    if(f) cout<<3<<'\n'<<1<<" "<<pos1<<" "<<pos2;
    else cout<<0;
    return 0;
}
/*
4
2 100 200 150
*/