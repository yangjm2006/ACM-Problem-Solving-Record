#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
    cin>>T;
    fflush(stdout);
    while(T--){
        cin>>n;
        fflush(stdout);
        int l=1,r=n;
        while(l<r){
            int mid=l+r>>1,x,y;
            printf("%d %d %d\n",1,1,mid);
            fflush(stdout);
            scanf("%d",&x);
            fflush(stdout);
            printf("%d %d %d\n",2,1,mid);
            fflush(stdout);
            scanf("%d",&y);
            fflush(stdout);
            if(x==y) l=mid+1;
            else{
                r=mid-(y-x)+1;
            }
        }
        int L=l,x,y;
        printf("%d %d %d\n",1,1,n);
        fflush(stdout);
        scanf("%d",&x);
        fflush(stdout);
        printf("%d %d %d\n",2,1,n);
        fflush(stdout);
        scanf("%d",&y);
        fflush(stdout);
        printf("! %d %d\n",L,L+y-x-1);
        fflush(stdout);
    }
    return 0;
}