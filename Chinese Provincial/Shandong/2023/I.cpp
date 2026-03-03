#include<iostream>
using namespace std;
int A,B;
int main(){
	cin>>A>>B;
	for(int i=1;i<=6;i++) for(int j=1;j<=6;j++) for(int k=1;k<=6;k++){
		int a=0,b=0;
		if(i==1||i==4) a+=i;
		else b+=i;
		if(j==1||j==4) a+=j;
		else b+=j;
		if(k==1||k==4) a+=k;
		else b+=k;
		if(A==a&&B==b){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}