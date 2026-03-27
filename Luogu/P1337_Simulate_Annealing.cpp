#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const double INF=1e20;
struct node{
    int x,y,w;
}a[N];
int n;
double calculate(double x,double y){
    double res=0;
    for(int i=1;i<=n;i++) res+=hypot(a[i].x-x,a[i].y-y)*a[i].w;
    return res;
}
mt19937 rnd(233);
int get(){
    int range=3000;
    return rnd()%(2*range)-range;
}
double ans_x,ans_y,ans;
void simulate_annealing(){
    double DOWN=0.999,T=100,T0=1e-16;
    int cnt=0;
    while(T>T0){
        double new_x=ans_x+get()*T,new_y=ans_y+get()*T;
        double new_ans=calculate(new_x,new_y);
        if(new_ans<ans){
            ans=new_ans;
            ans_x=new_x;
            ans_y=new_y;
        }else{
            if(exp((ans-new_ans)/T)>1.0*rnd()/rnd.max()){
                ans_x=new_x;
                ans_y=new_y;
            }
        }
        T*=DOWN;
        cnt++;
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].w;
        ans_x+=a[i].x;ans_y+=a[i].y;
    }
    ans_x/=n;ans_y/=n;
    ans=calculate(ans_x,ans_y);
    simulate_annealing();
    cout<<fixed<<setprecision(3)<<ans_x<<" "<<ans_y;
    return 0;
}