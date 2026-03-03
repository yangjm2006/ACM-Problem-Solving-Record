#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const double eps=1e-8;
int sgn(double x){
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator + (const Point &A){
        return Point(x+A.x,y+A.y);
    }
    Point operator - (const Point &A){
        return Point(x-A.x,y-A.y);
    }
    bool operator == (const Point &A){
        return sgn(x-A.x)==0&&sgn(y-A.y)==0;
    }
    bool operator < (const Point &A){
        return sgn(x-A.x)<0||(sgn(x-A.x)==0&&sgn(y-A.y)<0);
    }
};
typedef Point Vector;
double Cross(Vector A,Vector B){
    return A.x*B.y-A.y*B.x;
}
double Distance(Point A,Point B){
    return hypot(A.x-B.x,A.y-B.y);
}
int Convex_hull(Point *p,int n,Point *ch){
    n=unique(p,p+n)-p;
    sort(p,p+n);
    int cnt=0;
    for(int i=0;i<n;i++){
        while(cnt>1&&sgn(Cross(ch[cnt-1]-ch[cnt-2],p[i]-ch[cnt-1]))<=0) cnt--;
        ch[cnt++]=p[i];
    }
    int tmp=cnt;
    for(int i=n-2;i>=0;i--){
        while(cnt>tmp&&sgn(Cross(ch[cnt-1]-ch[cnt-2],p[i]-ch[cnt-1]))<=0) cnt--;
        ch[cnt++]=p[i];
    }
    if(n>1) cnt--;
    return cnt;
}
Point p[N],ch[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
    int cnt=Convex_hull(p,n,ch);
    double ans=0;
    for(int i=0;i<cnt;i++) ans+=Distance(ch[i],ch[(i+1)%cnt]);
    // for(int i=0;i<cnt;i++) cout<<ch[i].x<<" "<<ch[i].y<<'\n';
    cout<<fixed<<setprecision(2)<<ans;
    return 0;
}