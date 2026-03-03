#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+100;
struct Point{
    ll x,y;int id;
    Point(){}
    Point(ll x,ll y):x(x),y(y){}
    Point operator + (const Point &_){
        return Point(x+_.x,y+_.y);
    }
    Point operator - (const Point &_){
        return Point(x-_.x,y-_.y);
    }
    bool operator < (const Point &_){
        return x<_.x||(x==_.x&&y<_.y);
    }
    ll operator * (const Point &_){
        return x*_.x+y*_.y;
    }
    ll operator ^ (const Point &_){
        return x*_.y-y*_.x;
    }
};
typedef Point Vector;
ll len2(Vector v){
    return v*v;
}
double dist(Point A,Point B,Point C){
    return abs(((A-B)^(A-C))/sqrt(len2(B-C)));
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
Point p[N],ch[N],q[N];
bool vis[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int tot,k;
    cin>>tot>>k;
    for(int i=0;i<tot;i++){
        cin>>p[i].x>>p[i].y;
        p[i].id=i;
    }
    multiset<ll,greater<ll>> st;
    int m=tot;
    for(int o=1;o<=min(k,tot/2);o++){
        vector<Point> v;
        for(int i=0;i<tot;i++) if(!vis[i]) v.push_back(p[i]);
        for(int i=0;i<m;i++) q[i]=v[i];
        int n=Convex_hull(q,m,ch);
        int tp=1,id1,id2;ll ans=-1;
        for(int i=0;i<n;i++){
            while(dist(ch[tp%n],ch[i],ch[(i+1)%n])<dist(ch[(tp+1)%n],ch[i],ch[(i+1)%n])) tp++;
            if(ans<len2(ch[tp%n]-ch[i])){
                ans=len2(ch[tp%n]-ch[i]);
                id1=ch[tp%n].id;
                id2=ch[i].id;
            }
            if(ans<len2(ch[tp%n]-ch[(i+1)%n])){
                ans=len2(ch[tp%n]-ch[(i+1)%n]);
                id1=ch[tp%n].id;
                id2=ch[(i+1)%n].id;
            }
        }
        vis[id1]=vis[id2]=1;
        ll tmp=st.size()<k?-1:*prev(st.end());
        if(ans>tmp){
            st.insert(ans);
            for(int i=0;i<tot;i++) if(!vis[i]){
                if(len2(p[id1]-p[i])>tmp) st.insert(len2(p[id1]-p[i]));
                if(len2(p[id2]-p[i])>tmp) st.insert(len2(p[id2]-p[i]));
            }
            if(st.size()>k) st.erase(prev(st.end(),st.size()-k),st.end());
        }
        m-=2;
    }
    for(int i=1;i<k;i++) st.erase(st.begin());
    cout<<*st.begin();
    return 0;
}