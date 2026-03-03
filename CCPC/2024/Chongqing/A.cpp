#include"bits/stdc++.h"
using namespace std;

const int M = 3e3+5;
const int N = 3e3+5;
using ll = long long;

bool np[M];
int cnt,p[M];
int px[M];

void init(){
    for(int i=2;i<=3000;i++){
        if(!np[i]){
            p[++cnt]=i;
        }
        for(int j=1;j<=cnt&&i*p[j]<=3000;j++){
            np[i*p[j]]=1;
            px[i*p[j]]=p[j];
        }
    
    }
}

ll a[N];
ll num[N];



int main(){
    init();
    cout<<cnt<<endl;
    int n;
    cin>>n;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        // if(a[i])
        // while(a[i]>1)
    }
    

    return 0;
}