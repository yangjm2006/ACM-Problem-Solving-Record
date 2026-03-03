#include<bits/stdc++.h>
#define MAXN 510
using namespace std;
const int INF=1e9;
int n;
int a[MAXN][(MAXN << 1) | 1];

int ans;
bool fl = false;
struct node{
    int x,y;
};
queue<node> q;
int dis[MAXN][MAXN],tx,ty;
void bfs(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*i-1;j++) dis[i][j]=INF;
    }
    q.push((node){1,1});dis[1][1]=0;
    while(!q.empty()){
        int x=q.front().x,y=q.front().y;q.pop();
        if(x==tx&&y==ty){
            ans=dis[tx][ty];
            fl=1;
            return;
        }
        if(y+1<=x*2-1&&dis[x][y+1]>dis[x][y]+1&&a[x][y+1]!=-1){
            dis[x][y+1]=dis[x][y]+1;
            q.push((node){x,y+1});
        }
        if(y-1>=1&&dis[x][y-1]>dis[x][y]+1&&a[x][y-1]!=-1){
            dis[x][y-1]=dis[x][y]+1;
            q.push((node){x,y-1});
        }
        if(y%2==1&&x+1<=n&&dis[x+1][y+1]>dis[x][y]+1&&a[x+1][y+1]!=-1){
            dis[x+1][y+1]=dis[x][y]+1;
            q.push((node){x+1,y+1});
        }
        if(y%2==0&&x-1>=1&&dis[x-1][y-1]>dis[x][y]+1&&a[x-1][y-1]!=-1){
            dis[x-1][y-1]=dis[x][y]+1;
            q.push((node){x-1,y-1});
        }
    }
}

int main(){
    
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 2 * i - 1; j++){
			scanf("%d", &a[i][j]);
		}
	}

	for(int i = 1; i <= n; i++){
		int cnt;
		bool f = (i & 1);

		for(int j = 1; j <= 2 * i - 1; j++){
			if(!f){
				if(a[i][j] != (j-1) % 4 + 1){
					a[i][j] = -1;
				}
			}else{
				if(a[i][j] + (j-1) % 4 != 4){
					a[i][j] = -1;
				}
			}
		}
	}
    scanf("%d %d",&tx,&ty);

	bfs();

    if(fl) printf("%d", ans);
    else printf("-1");
}