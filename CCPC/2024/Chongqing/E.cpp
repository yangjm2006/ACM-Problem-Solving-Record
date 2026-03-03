#include"bits/stdc++.h"
using namespace std;
const int N=2e5+100;
const int INF=1e9;
int n,m,de[N],maxx=-INF,a[N],max1=-INF,max2=-INF;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==0){
        cout<<a[1];
        return 0;
    }
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        de[u]++;de[v]++;
    }
    for(int i=1;i<=n;i++){
        if(de[i]>1) maxx=max(maxx,a[i]);
        else{
            if(a[i]>max1){
                max2=max1;
                max1=a[i];
            }else if(a[i]>max2){
                max2=a[i];
            }
        }
    }
    cout<<max(max2,maxx);
    return 0;
}

/*
7 7
1 1 2 3 1 2 1
1 2
2 3
1 3
2 4
2 5
5 6
5 7

5 4
3 1 1 1 5
1 2 
2 3
3 4
4 5

5 5
10 2 1 5 3
1 2
1 3
1 4
2 3
4 5

*/
