#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+100;
struct Point{
    ll x,y;
    Point(){}
    Point(ll x,ll y):x(x),y(y){}
    Point operator + (const Point &_) const{
        return Point(x+_.x,y+_.y);
    }
    Point operator - (const Point &_) const{
        return Point(x-_.x,y-_.y);
    }
    bool operator < (const Point &_) const{
        return x<_.x||(x==_.x&&y<_.y);
    }
    ll operator * (const Point &_) const{
        return x*_.x+y*_.y;
    }
    ll operator ^ (const Point &_) const{
        return x*_.y-y*_.x;
    }
    ll operator / (const Point &_) const{
        return x*_.y==y*_.x;
    }
};
typedef Point Vector;
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
Point p1[N],ch1[N],p2[N],ch2[N],ch3[N];
int n,m,q,tot;
int sgn(ll x){
    if(x==0) return 0;
    if(x>0) return 1;
    return -1;
}
bool Compare_Vector_by_Angle(Vector a,Vector b){
    Vector IE=Vector(1,0);
    int a1=sgn(IE*a),a2=sgn(IE^a),b1=sgn(IE*b),b2=sgn(IE^b);
    if(a1==0&&a2<0) return 0;
    if(b1==0&&b2<0) return 1;
    if(a1!=b1) return a1>b1;
    if(a1==1){
        if(a2!=b2) return a2<b2;
        return sgn(a^b)>=0;
    }
    if(a2!=b2) return a2>b2;
    return sgn(a^b)>=0;
}
Vector vec[N];
void Mincowsky(){
    vector<Vector> v;
    for(int i=0;i<n;i++) v.push_back(ch1[(i+1)%n]-ch1[i]);
    for(int i=0;i<m;i++) v.push_back(ch2[(i+1)%m]-ch2[i]);
    sort(v.begin(),v.end(),Compare_Vector_by_Angle);
    ch3[tot++]=ch1[0]+ch2[0];
    ch3[tot++]=ch3[0]+v[0];
    for(int i=1;i<n+m;i++){
        if(v[i]/v[i-1]){
            ch3[tot-1]=ch3[tot-1]+v[i];
        } else{
            ch3[tot]=ch3[tot-1]+v[i];
            tot++;
        }
    }
    tot--;
    for(int i=1;i<tot;i++) vec[i]=ch3[i]-ch3[0];
}
bool in_Convex_hull(Vector p){
    if((vec[1]^p)<0||(vec[tot-1]^p)>0) return 0;
    int l=1,r=tot-2;
    while(l<r){
        int mid=(l+r>>1)+1;
        if((vec[mid]^p)>=0) l=mid;
        else r=mid-1;
    }
    if(((ch3[l+1]-ch3[l])^(p+ch3[0]-ch3[l]))>=0) return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>q;
    for(int i=0;i<n;i++) cin>>p1[i].x>>p1[i].y;
    for(int i=0;i<m;i++){
        cin>>p2[i].x>>p2[i].y;
        p2[i].x=-p2[i].x;p2[i].y=-p2[i].y;
    }
    n=Convex_hull(p1,n,ch1);
    m=Convex_hull(p2,m,ch2);
    Mincowsky();
    while(q--){
        Point p;
        cin>>p.x>>p.y;
        cout<<in_Convex_hull(p-ch3[0])<<'\n';
    }
    return 0;
}