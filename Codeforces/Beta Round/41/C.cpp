#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10];
bool check(){
    for(int i=0;i<4;i++) if(a[i]!=1) return 0;
    return 1;
}
int pos1,pos2;
int cnt(){
	int res=0;
	pos1=pos2=-1;
	for(int i=0;i<4;i++) if(a[i]!=1){
		res++;
		if(pos1=-1) pos1=i;
		else pos2=i; 
	}
	return res;
} 
bool cck(){
	int cnt1=0,cnt2=0;
	for(int i=0;i<4;i++){
		if(a[i]==1) cnt1++;
		else if(a[i]%2==0){
			cnt2++;
			pos1=i;
		}
	}
	return (cnt1==2&&cnt2==2);
} 
vector<string> ans;
main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=0;i<4;i++) cin>>a[i];
    while(1){
        bool f;
        do{
            f=0;
            for(int i=0;i<4;i++){
                if(a[i]%2==0&&a[(i+1)%4]%2==0){
                    a[i]/=2;
                    a[(i+1)%4]/=2;
                    string s;
                    s+='/';s+=char('0'+(i+1));
                    ans.push_back(s);
                    f=1;
                }
            }
        }while(f);
        if(check()) break;
        for(int i=0;i<4;i++){
            if(a[i]!=1&&a[i]%2==1){
                a[i]++;a[(i+1)%4]++;
                string s;
                s+='+';s+=char('0'+(i+1));
                ans.push_back(s);
                break;
            }
        }
        do{
            f=0;
            for(int i=0;i<4;i++){
                if(a[i]%2==0&&a[(i+1)%4]%2==0){
                    a[i]/=2;
                    a[(i+1)%4]/=2;
                    string s;
                    s+='/';s+=char('0'+(i+1));
                    ans.push_back(s);
                    f=1;
                }
            }
        }while(f);
        int tmp=cnt();
        if(tmp==1&&a[pos1]%2==0){
        	a[pos1]+=2;a[(pos1+1)%4]++;a[(pos1+3)%4]++;
            string s;
            s+='+';s+=char('0'+(pos1+1));
            ans.push_back(s);
        	s="";
        	if(pos1==0) pos1+=4;
            s+='+';s+=char('0'+pos1);
            ans.push_back(s);
		}else if(cck()){
        	a[pos1]+=2;a[(pos1+1)%4]++;a[(pos1+3)%4]++;
            string s;
            s+='+';s+=char('0'+(pos1+1));
            ans.push_back(s);
        	s="";
        	if(pos1==0) pos1+=4;
            s+='+';s+=char('0'+pos1);
            ans.push_back(s);
		}
    }
    for(auto x:ans) cout<<x<<'\n';
    return 0;
}