#include<iostream>
#include<limits>
void f(long) { std::cout << "long\n"; }
// void f(long long) { std::cout << "long long\n"; }
int main(){
	std::cout<<sizeof(long double)<<"\n";
	std::cout<<std::numeric_limits<long double>::digits10<<'\n';
	f(1L);
    f(1LL);
    f(1); 
	
}
