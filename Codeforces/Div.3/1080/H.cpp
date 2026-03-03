#include<bits/stdc++.h>
using namespace std;
void pt(int x,int y){
    cout<<x<<" "<<y<<" "<<x+1<<" "<<y<<" "<<x<<" "<<y+1<<'\n';
    cout<<x+1<<" "<<y+1<<" "<<x+1<<" "<<y+2<<" "<<x<<" "<<y+2<<'\n';
}
void qt(int x,int y){
    cout<<x<<" "<<y<<" "<<x+1<<" "<<y<<" "<<x<<" "<<y+1<<'\n';
    cout<<x+1<<" "<<y+1<<" "<<x+2<<" "<<y+1<<" "<<x+2<<" "<<y<<'\n';
}
void __(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"2\n";
        cout<<"1 1 1 2 2 1\n2 3 3 2 3 3\n";
    }else if(n%2==0){
        cout<<3*n*n<<'\n';
        for(int i=1;i<=3*n;i+=2){
            for(int j=1;j<=3*n;j+=3){
                pt(i,j);
            }
        }
    }else{
        cout<<3*n*n<<'\n';
        for(int j=1;j<=9;j+=3){
            pt(1,j);
            pt(8,j);
        }
        cout<<"3 1 3 2 4 1\n";
        cout<<"4 2 3 3 3 4\n";
        cout<<"6 1 7 1 7 2\n";
        cout<<"5 1 5 2 6 2\n";
        cout<<"4 3 5 3 5 4\n";
        cout<<"6 3 7 3 7 4\n";
        cout<<"6 4 6 5 7 5\n";
        cout<<"4 4 5 5 5 6\n";
        cout<<"3 5 4 5 4 6\n";
        cout<<"3 6 3 7 4 7\n";
        cout<<"3 8 3 9 4 9\n";
        cout<<"4 8 5 8 5 9\n";
        cout<<"5 7 6 7 6 6\n";
        cout<<"7 6 7 7 6 8\n";
        cout<<"7 8 7 9 6 9\n";
        for(int i=10;i<=3*n;i+=2){
            for(int j=10;j<=3*n;j+=3){
                pt(i,j);
            }
        }
        for(int i=10;i<=3*n;i+=2){
            for(int j=1;j<=9;j+=3){
                pt(i,j);
            }
        }
        for(int i=10;i<=3*n;i+=2){
            for(int j=1;j<=9;j+=3){
                qt(j,i);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--) __();
    return 0;
}