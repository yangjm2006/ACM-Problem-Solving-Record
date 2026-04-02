#include<bits/stdc++.h>
using namespace std;
const int N=110;
const double eps=1e-12;
struct Point{
    double x,y,z;
}p[N];
typedef Point Vector;
Vector operator ^ (const Vector &a,const Vector &b){
    return (Vector){a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x};
}
double operator * (const Vector &a,const Vector &b){
    return a.x*b.x+a.y*b.y+a.z*b.z;
}
Vector operator - (const Vector &a,const Vector &b){
    return (Vector){a.x-b.x,a.y-b.y,a.z-b.z};
}
double len(const Vector &a){
    return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}
int n;
void Convex_hull(){
    double ans=0;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) for(int k=j+1;k<=n;k++){
        bool flag=1;int s=0;
        Vector vert=((p[j]-p[i])^(p[k]-p[i]));
        for(int o=1;o<=n;o++){
            if(o==i||o==j||o==k) continue;
            if(vert*(p[o]-p[i])>0){
                if(s==-1) flag=0;
                s=1;
            }
            else if(vert*(p[o]-p[i])<0){
                if(s==1) flag=0;
                s=-1;
            }
        }
        if(flag) ans+=len(vert)/2;
    }
    cout<<fixed<<setprecision(6)<<ans;
}
mt19937 rnd(1211);
double get_rand(){
    return eps*rnd()/rnd.max();
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y>>p[i].z;
        p[i].x+=get_rand();
        p[i].y+=get_rand();
        p[i].z+=get_rand();
    }
    Convex_hull();
    return 0;
}