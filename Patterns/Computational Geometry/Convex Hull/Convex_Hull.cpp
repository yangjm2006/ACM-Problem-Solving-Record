// #include<bits/stdc++.h>
// using namespace std;
// const double Pi=acos(-1);
// const double eps=1e-8;
// int sgn(double x){
//     if(fabs(x)<eps) return 0;
//     return x<0?-1:1;
// }
// int dcmp(double x,double y){
//     if(fabs(x-y)<eps) return 0;
//     return x<y?-1:1;
// }
// struct Point{
//     double x,y;
//     Point(){}
//     Point(double x,double y):x(x),y(y){}
//     Point operator + (const Point A){
//         return Point(x+A.x,y+A.y);
//     }
//     Point operator - (const Point A){
//         return Point(x-A.x,y-A.y);
//     }
//     Point operator * (const double k){
//         return Point(x*k,y*k);
//     }
//     Point operator / (const double k){
//         return Point(x/k,y/k);
//     }
//     bool operator == (const Point A){
//         return sgn(x-A.x)==0&&sgn(y-A.y)==0;
//     }
// };
// typedef Point Vector;
// double Distance(Point A,Point B){
//     return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
// }
// double Dot(Vector A,Vector B){
//     return A.x*B.x+A.y*B.y;
// }
// double Len(Vector A){
//     return sqrt(Dot(A,A));
// }
// double Len(Vector A){
//     return Dot(A,A);
// }
// double Angle(Vector A,Vector B){
//     return acos(Dot(A,B)/Len(A)/Len(B));
// }
// double Cross(Vector A,Vector B){
//     return A.x*B.y-A.y-B.x;
// }
// double Area2(Point A,Point B,Point C){
//     return Cross(B-A,C-A);
// }
// Vector Rotate(Vector A,double rad){
//     return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
// }
// Vector Normal(Vector A){
//     return Vector(-A.y/Len(A),A.x/Len(A));
// }
// bool Parallel(Vector A,Vector B){
//     return sgn(Cross(A,B))==0;
// }
// struct Line{
//     Point p1,p2;
//     Line();
//     Line(Point p1,Point p2):p1(p1),p2(p2){}
//     Line(Point p,double angle){
//         p1=p;

//     }
//     Line(double a,double b,double c){
//         if(sgn(b)==0){
//             p1=Point(-c/a,0);
//             p2=Point(-c/a,1);
//         }else{
//             p1=Point(0,-c/b);
//             p2=Point(1,-(c+a)/b);
//         }
//     }
// };
// int Point_line_relation(Point p,Line v){
//     int c=sgn(Cross(p-v))
// }
// typedef Line Segment;

// int main(){
//     return 0;
// }