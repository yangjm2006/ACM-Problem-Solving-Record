#include<bits/stdc++.h>
using namespace std;
void work(string s){
	int len=s.size();
	if(s=="ikimasu"){
		s="itte";
	}else if(s.rfind("chimasu")==len-7){
		s.replace(len-7,7,"tte");
	}else if(s.rfind("rimasu")==len-6){
		s.replace(len-6,6,"tte");
	}else if(s.rfind("mimasu")==len-6){
		s.replace(len-6,6,"nde");
	}else if(s.rfind("bimasu")==len-6){
		s.replace(len-6,6,"nde");
	}else if(s.rfind("nimasu")==len-6){
		s.replace(len-6,6,"nde");
	}else if(s.rfind("kimasu")==len-6){
		s.replace(len-6,6,"ite");
	}else if(s.rfind("gimasu")==len-6){
		s.replace(len-6,6,"ide");
	}else if(s.rfind("shimasu")==len-7){
		s.replace(len-7,7,"shite");
	}else if(s.rfind("imasu")==len-5){
		s.replace(len-5,5,"tte");
	}
	cout<<s<<'\n';
}
int T;
string s;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>s;
		work(s);
	}
	return 0;
} 