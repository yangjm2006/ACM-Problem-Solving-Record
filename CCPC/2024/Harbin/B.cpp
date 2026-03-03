#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
struct Point{
    ll x,y;int id;
    Point(){}
    Point(ll x,ll y):x(x),y(y){}
    Point operator + (const Point &A){
        return Point(x+A.x,y+A.y);
    }
    Point operator - (const Point &A){
        return Point(x-A.x,y-A.y);
    }
    bool operator < (const Point &A){
        return x<A.x||(x==A.x&&y<A.y);
    }
};
typedef Point Vector;
ll Cross(Vector A,Vector B){
    return A.x*B.y-A.y*B.x;
}
int Convex_hull(Point *p,int n,Point *ch){
    sort(p,p+n);
    for(int i=0;i<n;i++) p[i].id=i;
    int cnt=0;
    for(int i=0;i<n;i++){
        while(cnt>1&&Cross(ch[cnt-1]-ch[cnt-2],p[i]-ch[cnt-1])<=0) cnt--;
        ch[cnt++]=p[i];
    }
    int tmp=cnt;
    for(int i=n-2;i>=0;i--){
        while(cnt>tmp&&Cross(ch[cnt-1]-ch[cnt-2],p[i]-ch[cnt-1])<=0) cnt--;
        ch[cnt++]=p[i];
    }
    if(cnt>1) cnt--;
    return cnt;
}
Point p[N],ch1[N],ch2[N],p2[N];
void solve(){
    ll ans=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
    int cnt1=Convex_hull(p,n,ch1);
    vector<bool> vis(n,0);
    for(int i=0;i<cnt1;i++) vis[ch1[i].id]=1;
    for(int i=0;i<cnt1;i++) ans+=Cross(ch1[i],ch1[(i+1)%cnt1]);
    int n2=0;
    for(int i=0;i<n;i++) if(!vis[i]) p2[n2++]=p[i];
    int cnt2=Convex_hull(p2,n2,ch2);
    // for(int i=0;i<cnt1;i++) cout<<ch1[i].x<<" "<<ch1[i].y<<"--\n";
    // for(int i=0;i<cnt2;i++) cout<<ch2[i].x<<" "<<ch2[i].y<<"++\n";
    if(cnt2==0){
        cout<<"-1\n";
        return;
    }
    ll minn=LLONG_MAX,tp=0;
    for(int i=0;i<cnt2;i++){
        if(minn>abs(Cross(ch2[i]-ch1[0],ch2[i]-ch1[1]))){
            minn=abs(Cross(ch2[i]-ch1[0],ch2[i]-ch1[1]));
            tp=i;
        }
    }
    for(int i=1;i<cnt1;i++){
        while(abs(Cross(ch2[tp%cnt2]-ch1[i],ch2[tp%cnt2]-ch1[(i+1)%cnt1]))>abs(Cross(ch2[(tp+1)%cnt2]-ch1[i],ch2[(tp+1)%cnt2]-ch1[(i+1)%cnt1]))){
            tp++;
        }
        minn=min(minn,abs(Cross(ch2[tp%cnt2]-ch1[i],ch2[tp%cnt2]-ch1[(i+1)%cnt1])));
    }
    cout<<ans-minn<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
/*

4

6
-2 0
1-2
5 2
0 4
1 2
3 1

4
0 0
1 0
0 1
1 1

9
484630042 51929469
-40468396 -517784096
98214104 -103353239
629244333 -475172587
106398764 153884485
49211709 -44865749
1 10
166321833 -247717657
406208245 668933360

5
-1000000000 -1000000000
1000000000 -1000000000
-1000000000 1000000000
0 -500000000
1000000000 1000000000

950319193795831919
*/