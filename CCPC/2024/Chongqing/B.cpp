#include"bits/stdc++.h"
#define db double
using namespace std;
int T,a,b,c,d,e,f,ppmax;
const db eps=1e-8;
double acc;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--){
        cin>>ppmax;
        cin>>a>>b>>c>>d>>e>>f;
        acc=1.0*(300*a+300*b+200*c+100*d+50*e+0*f)/300.0/(a+b+c+d+e+f)+eps;
        cout<<fixed<<setprecision(2)<<acc*100<<"% ";
        cout<<int(max(0.0,1.0*(320.0*a+300*b+200*c+100*d+50*e+0*f)/320.0/(a+b+c+d+e+f)-0.8)*5*ppmax+0.5+eps)<<'\n';
    }
    return 0;
}
/*
 2
 630
 3029 2336 377 41 10 61
 3000
 20000 10000 0 0 0 0
 */