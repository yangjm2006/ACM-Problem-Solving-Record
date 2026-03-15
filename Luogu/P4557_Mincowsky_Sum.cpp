// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;
// const int N=1e5+100;
// struct Point{
//     ll x,y;
//     Point(){}
//     Point(ll x,ll y):x(x),y(y){}
//     Point operator + (const Point &_){
//         return Point(x+_.x,y+_.y);
//     }
//     Point operator - (const Point &_){
//         return Point(x-_.x,y-_.y);
//     }
//     bool operator < (const Point &_){
//         return x<_.x||(x==_.x&&y<_.y);
//     }
//     ll operator * (const Point &_){
//         return x*_.x+y*_.y;
//     }
//     ll operator ^ (const Point &_){
//         return x*_.y-y*_.x;
//     }
// };
// typedef Point Vector;
// ll len2(Vector v){
//     return v*v;
// }
// double dist(Point A,Point B,Point C){
//     return abs(((A-B)^(A-C))/sqrt(len2(B-C)));
// }
// int Convex_hull(Point *p,int n,Point *ch){
//     sort(p,p+n);
//     int cnt=0;
//     for(int i=0;i<n;i++){
//         while(cnt>1&&((ch[cnt-1]-ch[cnt-2])^(p[i]-ch[cnt-1]))<=0) cnt--;
//         ch[cnt++]=p[i];
//     }
//     int tmp=cnt;
//     for(int i=n-2;i>=0;i--){
//         while(cnt>tmp&&((ch[cnt-1]-ch[cnt-2])^(p[i]-ch[cnt-1]))<=0) cnt--;
//         ch[cnt++]=p[i];
//     }
//     if(cnt>1) cnt--;
//     return cnt;
// }
// Point p[N],ch[N];
// int main(){
//     ios::sync_with_stdio(0);cin.tie(0);
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
//     n=Convex_hull(p,n,ch);
//     cout<<ans;
//     return 0;
// }