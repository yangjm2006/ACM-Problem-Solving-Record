#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
bool a[N][N],b[N][N];
int n;
int tox1(int i){
    if(i==1){
        return n/2;
    }else if(i==2){
        return n/2+2;
    }else if(i<=n/2+1){
        return i-2;
    }else if(i==n/2+2){
        return n/2+1;
    }else{
        return i;
    }
}
int toy1(int j){
    if(j==1){
        return 1;
    }else if(j==n/2+1){
        return 2;
    }else if(j<=n/2){
        return j*2;
    }else{
        return (j-n/2)*2-1;
    }
}
int tox2(int i){
    if(i==1){
        return n/2-1;
    }else if(i==2){
        return n/2+1;
    }else if(i<n/2){
        return i-2;
    }else if(i==n/2){
        return n/2-2;
    }else if(i==n/2+1){
        return n/2;
    }else{
        return i;
    }
}
int toy2(int j){
    if(j<=n/2){
        return 2*j-1;
    }else{
        return (j-n/2)*2;
    }
}
void __(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            a[i][n-j+1]=1;
        }
    }
    if(n%2==0){
        if(n==4){
            cout<<"0001\n0000\n0011\n1011\n";
            return;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                b[tox2(i)][toy2(j)]=a[i][j];
            }
        }
    }else{
        if(n==3){
            cout<<"001\n000\n011\n";
            return;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                b[tox1(i)][toy1(j)]=a[i][j];
            }
        }

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout<<b[i][j];
        cout<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    // cin>>T;
    T=1;
    while(T--) __();
    return 0;
}