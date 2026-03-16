#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#define N 300010 
using namespace std;
struct point{
	double x,y;
	void read(){scanf("%lf%lf",&x,&y);}
	void write(){printf("%lf,%lf ",x,y);}
}a[N],b[N],s1[N],s2[N],s[N],k,O,q;
struct my_stack{
	int t[N],len;
	void push(int x){t[len++]=x;}
	int operator [](int w){return t[len-w];}
	void pop(){len--;}
	void clear(){t[len=0]=0;}
}t;
point operator +(point a,point b)
{return (point){a.x+b.x,a.y+b.y};}
point operator -(point a,point b)
{return (point){a.x-b.x,a.y-b.y};}
double operator *(point a,point b)
{return a.x*b.y-a.y*b.x;}
bool operator ==(point a,point b)
{return a.x==b.x&&a.y==b.y;}
point operator ~(point a){return (point){-a.x,-a.y};}
double sqr(double a){return a*a;}
double calc(point a,point b)
{return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}
bool cmp(point a,point b)
{
	double x=(a-k)*(b-k);
	if(x==0) return calc(a,k)<calc(b,k);
	else return x>0;
}
bool cmp2(point a,point b)
{
	double x=a*b;
	if(x==0) return calc(a,O)<calc(b,O);
	else return x>0;
}
double ans;
void convex(point*p,int&n)
{
	int w=1;
	for(int i=1;i<=n;i++)
		if(p[i].y<p[w].y||(p[i].y==p[w].y&&p[i].x<p[w].x)) w=i;
	swap(p[1],p[w]);k=p[1];
	sort(p+2,p+n+1,cmp);
	t.clear();
	t.push(1),t.push(2);
	for(int i=3;i<=n;i++)
	{
		while(t.len>1&&(p[i]-p[t[2]])*(p[t[1]]-p[t[2]])>=0) t.pop();
		t.push(i);
	}
	n=t.len;
	for(int i=1;i<=n;i++) p[i]=p[t.t[i-1]];
}
int n,m,cnt,T;
void minkowski()
{
	int i,j;
	for(i=1;i<n;i++) s1[i]=a[i+1]-a[i];
	for(i=1;i<m;i++) s2[i]=b[i+1]-b[i];
	s2[m]=b[1]-b[m];s1[n]=a[1]-a[n];
	i=1,j=1;
	s[cnt=1]=a[1]+b[1];
	while(i<=n&&j<=m)
	{
		if(s1[i]*s2[j]>0) s[cnt+1]=s[cnt]+s1[i++];
		else s[cnt+1]=s[cnt]+s2[j++];
		cnt++;
	}
	while(i<=n) s[cnt+1]=s[cnt]+s1[i++],cnt++;
	while(j<=m) s[cnt+1]=s[cnt]+s2[j++],cnt++;
	cout<<"CH3--------------\n";for(int i=2;i<=cnt;i++) cout<<s[i].x<<" "<<s[i].y<<"\n";
}
bool query(point x)
{
	if(x*s[2]>0||s[cnt]*x>0||(x*s[2]==0&&calc(x,O)>calc(s[2],O))
		||(x*s[cnt]==0&&calc(x,O)>calc(s[cnt],O))) return 1;
	int w=lower_bound(s+2,s+cnt+1,x,cmp2)-s-1;
	return (x-s[w])*(s[w+1]-s[w])>0;
}
int main()
{
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n;i++) a[i].read();
	for(int i=1;i<=m;i++) b[i].read(),b[i]=O-b[i];
	convex(a,n),convex(b,m);
	cout<<"CH1--------------\n";for(int i=1;i<=n;i++) cout<<a[i].x<<" "<<a[i].y<<"\n";
	cout<<"CH2--------------\n";for(int i=1;i<=m;i++) cout<<b[i].x<<" "<<b[i].y<<"\n";
	minkowski(),convex(s,cnt);
	k=s[1]; for(int i=1;i<=cnt;i++) s[i]=s[i]-k;
	while(T--)
	{
		q.read();
		printf("%d\n",!query(q-k));
	}
}
