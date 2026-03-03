#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll T,a,b,t1,t2,t,v;
int main(){
    cin>>T;
    while(T--){
        cin>>v>>t1>>a>>t2>>b;
        t=t2-t1;
        if(v*t>=a){
            printf("%.7lf %.7lf\n",1.0*a/v,1.0*b/v);
        }else{
            double ans1=0,ans2=0;
            ans1+=t;a-=v*t;
            ans1+=2.0*min(a,b)/v;ans2+=2.0*min(a,b)/v;
            if(a>=b) ans1+=1.0*(a-b)/v;
            else ans2+=1.0*(b-a)/v;
            printf("%.7lf %.7lf\n",ans1,ans2);
        }
    }
    return 0;
}
/*
 4 
 5 0 10 10 4 
 3 2 7 2 1 
 3 2 100 3 7 
 36158 7639 29138 89521 95632
*/