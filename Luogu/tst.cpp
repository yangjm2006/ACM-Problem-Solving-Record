#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5;
int n,k,x[maxn],y[maxn];
typedef long long ll;
ll cross(int a,int b,int c){
	return 1ll*(x[c]-x[a])*(y[b]-y[a])-1ll*(x[b]-x[a])*(y[c]-y[a]);
}
ll dist(int a,int b){
	return 1ll*(x[a]-x[b])*(x[a]-x[b])+1ll*(y[a]-y[b])*(y[a]-y[b]);
}
int s[maxn*2],tp;
bool vis[maxn];
pair<int,int> calc(){
	vector<int> ord;
	for(int i=1;i<=n;i++) if(!vis[i]) ord.push_back(i);
	sort(ord.begin(),ord.end(),[](int a,int b){
		if(x[a]!=x[b]) return x[a]<x[b];
		return y[a]<y[b];
	});
	s[0]=ord[0];
	tp=1;
	for(int i=1;i<(int)ord.size();i++){
		while(s[tp-1]!=ord[0]&&1ll*(y[ord[i]]-y[s[tp-1]])*(x[ord[i]]-x[s[tp-2]])>=1ll*(y[ord[i]]-y[s[tp-2]])*(x[ord[i]]-x[s[tp-1]])) tp--;
		s[tp++]=ord[i];
	}
	for(int i=(int)ord.size()-2;i>=0;i--){
		while(s[tp-1]!=ord.back()&&1ll*(y[s[tp-1]]-y[ord[i]])*(x[s[tp-2]]-x[ord[i]])>=1ll*(y[s[tp-2]]-y[ord[i]])*(x[s[tp-1]]-x[ord[i]])) tp--;
		s[tp++]=ord[i];
	}
	tp--;
	if(tp==2) return {s[0],s[1]};
	int cur=0;
	while(cross(s[tp-1],s[0],s[(cur+1)%tp])>cross(s[tp-1],s[0],s[cur])) cur=(cur+1)%tp;
	int a=s[cur],b;
	if(dist(s[cur],s[0])>dist(s[cur],s[tp-1])) b=s[0];
	else b=s[tp-1];
	for(int i=0;i<tp-1;i++){
		while(cross(s[i],s[i+1],s[(cur+1)%tp])>cross(s[i],s[i+1],s[cur])) cur=(cur+1)%tp;
		if(dist(s[cur],s[i])>dist(a,b)){
			a=s[cur];
			b=s[i];
		}
		if(dist(s[cur],s[i+1])>dist(a,b)){
			a=s[cur];
			b=s[i+1];
		}
	}
	return {a,b};
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	k=readint();
	for(int i=1;i<=n;i++){
		x[i]=readint();
		y[i]=readint();
	}
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	for(int i=0;i<min(k,n/2);i++){
		auto res=calc();
		int a=res.first,b=res.second;
		pq.push(dist(a,b));
		if((int)pq.size()>k) pq.pop();
		vis[a]=vis[b]=1;
		for(int j=1;j<=n;j++) if(!vis[j]){
			pq.push(dist(a,j));
			if((int)pq.size()>k) pq.pop();
		}
		for(int j=1;j<=n;j++) if(!vis[j]){
			pq.push(dist(b,j));
			if((int)pq.size()>k) pq.pop();
		}
	}
	printf("%lld\n",pq.top());
	return 0;
}
