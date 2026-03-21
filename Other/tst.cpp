#include<iostream>
int Ans[6][66000];
int A(int m,int n){
    if(m==0) return n+1;
    if(Ans[m][n]) return Ans[m][n];
    if(n==0) return Ans[m][n]=A(m-1,1);
    return Ans[m][n]=A(m-1,A(m,n-1));
}
int main(){
    int T;
    std::cin>>T;
    while(T--){
        int m,n;
        std::cin>>m>>n;
        std::cout<<A(m,n)<<'\n';
    }
    return 0;
}