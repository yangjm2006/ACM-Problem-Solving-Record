#include<bits/stdc++.h>
#define db double
using namespace std;
const int N=2e5+100;
struct node{
	db x;int id;
	bool operator < (const node &y) const{
		return x<y.x;
	}
}a[N];
int n;
db k,ans[N];
int main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		a[i].id=i;
        scanf("%lf",&a[i].x);
	}
	sort(a+1,a+1+n);
	db l=0,r=k;
	for(int i=1;i<=100;i++){
		db mid=(l+r)/2,res=0;
		res+=mid;
		for(int j=2;j<=n;j++){
			res+=(mid*a[j].x)/(a[1].x+mid*(a[j].x-a[1].x));
		}
		if(res>=k) r=mid;
		else l=mid;
	}
	ans[a[1].id]=l;
	for(int i=2;i<=n;i++) ans[a[i].id]=(l*a[i].x)/(a[1].x+l*(a[i].x-a[1].x));
	for(int i=1;i<=n;i++) printf("%.12lf\n",ans[i]);
	return 0;
}