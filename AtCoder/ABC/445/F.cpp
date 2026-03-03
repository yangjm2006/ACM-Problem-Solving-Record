#include<bits/stdc++.h>
#define ll long long
const ll INF=1e18;
using namespace std;
struct Matrix{
    ll val[120][120];
    Matrix(){
        for(int i=1;i<=100;i++) for(int j=1;j<=100;j++) val[i][j]=INF;
    }
    void IE(){
        for(int i=1;i<=100;i++) val[i][i]=0;
    }
    Matrix operator + (const Matrix _) const{
        Matrix ans;
        for(int i=1;i<=100;i++)
            for(int j=1;j<=100;j++)
                ans.val[i][j]=min(ans.val[i][j],_.val[i][j]);
        return ans;
    }
    Matrix operator * (const Matrix _) const{
        Matrix ans;
        for(int k=1;k<=100;k++)
            for(int i=1;i<=100;i++)
                for(int j=1;j<=100;j++)
                    ans.val[i][j]=min(ans.val[i][j],val[i][k]+_.val[k][j]);
        return ans;
    }
};
int main(){
    Matrix A,ans;
    ans.IE();
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>A.val[i][j];
    for(;k;k>>=1,A=A*A)
        if(k&1) ans=ans*A;
    for(int i=1;i<=n;i++) cout<<ans.val[i][i]<<'\n';
    return 0;
}