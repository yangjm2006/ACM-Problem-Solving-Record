#include<bits/stdc++.h>
using namespace std;
const double eps=1e-7;
const double Pi=acos(-1.0);
const int N=2e5+100;
int sgn(double x){
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator + (const Point &_){
        return Point(x+_.x,y+_.y);
    }
    Point operator - (const Point &_){
        return Point(x-_.x,y-_.y);
    }
    double operator ^ (const Point &_){
        return x*_.y-y*_.x;
    }
    bool operator == (const Point &_){
        return sgn(x-_.x)==0&&sgn(y-_.y)==0;
    }
    bool operator < (const Point &_){
        return sgn(x-_.x)<0||(sgn(x-_.x)==0&&sgn(y-_.y)<0);
    }
    Point operator % (const double &ph){
        return Point(x*cos(ph)-y*sin(ph),x*sin(ph)+y*cos(ph));
    }
};
typedef Point Vector;
double Len(Vector v){
    return hypot(v.x,v.y);
}
int Convex_hull(Point *p,int n,Point *ch){
    n=unique(p,p+n)-p;
    sort(p,p+n);
    int cnt=0;
    for(int i=0;i<n;i++){
        while(cnt>1&&sgn((ch[cnt-1]-ch[cnt-2])^(p[i]-ch[cnt-1]))<=0) cnt--;
        ch[cnt++]=p[i];
    }
    int tmp=cnt;
    for(int i=n-2;i>=0;i--){
        while(cnt>tmp&&sgn((ch[cnt-1]-ch[cnt-2])^(p[i]-ch[cnt-1]))<=0) cnt--;
        ch[cnt++]=p[i];
    }
    if(cnt>1) cnt--;
    return cnt;
}
Point p[N],ch[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,_=0;
    double a,b,r,ans=0;
    cin>>n>>a>>b>>r;
    a/=2;b/=2;
    a-=r;b-=r;
    ans+=2*r*Pi;
    for(int i=0;i<n;i++){
        double x,y,o;
        cin>>x>>y>>o;
        p[_++]=Point(x,y)+Point(b,a)%o;
        p[_++]=Point(x,y)+Point(-b,a)%o;
        p[_++]=Point(x,y)+Point(b,-a)%o;
        p[_++]=Point(x,y)+Point(-b,-a)%o;
    }
    int cnt=Convex_hull(p,_,ch);
    // for(int i=0;i<cnt;i++) cout<<ch[i].x<<" "<<ch[i].y<<"--\n";
    for(int i=0;i<cnt;i++) ans+=Len(ch[i]-ch[(i+1)%cnt]);
    cout<<fixed<<setprecision(2)<<ans;
    return 0;
}