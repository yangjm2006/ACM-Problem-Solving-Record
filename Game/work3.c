#include<stdio.h>
#include<time.h>
#include<windows.h>
int main(){
    time_t t1=time(NULL);
    for(int i=1;i<=10;i++){
        system("cls");
        printf("%d",i);
        Sleep(1000);
    }
    time_t t2=time(NULL);
    printf("%d %d %d",t1,t2,difftime(t2,t1));
    return 0;
}