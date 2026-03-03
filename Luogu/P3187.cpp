#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
const double eps=1e-10;
const double INF=1e18;
int sgn(double x){
    if(fabs(x)<=eps) return 0;
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
    Point operator * (const double &_){
        return Point(x*_,y*_);
    }
    Point operator / (const double &_){
        return Point(x/_,y/_);
    }
    bool operator < (const Point &_){
        return sgn(x-_.x)<0||(sgn(x-_.x)==0&&sgn(y-_.y)<0);
    }
    double operator * (const Point &_){
        return x*_.x+y*_.y;
    }
    double operator ^ (const Point &_){
        return x*_.y-y*_.x;
    }
};
typedef Point Vector;
double len(Vector v){
    return sqrt(v*v);
}
double dist(Point A,Point B,Point C){
    return abs(((A-B)^(A-C)))/len(B-C);
}
double proj(Vector A,Vector B){
    return A*B/len(B);
}
Point ident(Vector A){
    return A/len(A);
}
Point vert(Vector A){
    A=ident(A);
    return Point(-A.y,A.x);
}
int Convex_hull(Point *p,int n,Point *ch){
    sort(p,p+n);
    int cnt=0;
    for(int i=0;i<n;i++){
        while(cnt>1&&((ch[cnt-1]-ch[cnt-2])^(p[i]-ch[cnt-1]))<=0) cnt--;
        ch[cnt++]=p[i];
    }
    int tmp=cnt;
    for(int i=n-2;i>=0;i--){
        while(cnt>tmp&&((ch[cnt-1]-ch[cnt-2])^(p[i]-ch[cnt-1]))<=0) cnt--;
        ch[cnt++]=p[i];
    }
    if(cnt>1) cnt--;
    return cnt;
}
Point p[N],ch[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
    n=Convex_hull(p,n,ch);
    int tph=1,tp1=0,tp2;double ans=INF;Point ansp[5];
    for(int i=0;i<n;i++){
        while(dist(ch[tph%n],ch[i],ch[(i+1)%n])<dist(ch[(tph+1)%n],ch[i],ch[(i+1)%n])) tph++;
        while(proj(ch[tp1%n]-ch[i],ch[(i+1)%n]-ch[i])<proj(ch[(tp1+1)%n]-ch[i],ch[(i+1)%n]-ch[i])) tp1++;
        if(i==0) tp2=tph;
        while(proj(ch[tp2%n]-ch[i],ch[(i+1)%n]-ch[i])>proj(ch[(tp2+1)%n]-ch[i],ch[(i+1)%n]-ch[i])) tp2++;
        double cal=dist(ch[tph%n],ch[i],ch[(i+1)%n])*(proj(ch[tp1%n]-ch[i],ch[(i+1)%n]-ch[i])-proj(ch[tp2%n]-ch[i],ch[(i+1)%n]-ch[i]));
        if(ans>cal){
            Point IE=ident(ch[(i+1)%n]-ch[i]);
            ansp[1]=ch[i]+IE*proj(ch[tp2%n]-ch[i],ch[(i+1)%n]-ch[i]);
            ansp[2]=ch[i]+IE*proj(ch[tp1%n]-ch[i],ch[(i+1)%n]-ch[i]);
            ansp[3]=ansp[2]+vert(ch[(i+1)%n]-ch[i])*dist(ch[tph%n],ch[i],ch[(i+1)%n]);
            ansp[4]=ansp[1]+vert(ch[(i+1)%n]-ch[i])*dist(ch[tph%n],ch[i],ch[(i+1)%n]);
            ans=cal;
        }
    }
    cout<<fixed<<setprecision(5)<<ans<<'\n';
    for(int i=1;i<=4;i++){
        ansp[i]=ansp[i]+Point(eps,eps);
        cout<<ansp[i].x<<" "<<ansp[i].y<<'\n';
    }
    return 0;
}