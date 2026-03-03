#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<string.h>
#include<stdbool.h>

#define WHITE 0xF
#define YELLOW 0x6
#define BLUE 0x9
#define RED 0xC
#define GREEN 0x2
#define PURPLE 0xD

void Change_Color(int c){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
    return;
}

void game1(){
    Change_Color(WHITE);
    printf("欢迎来到第一个游戏:猜数!\n");
    printf("让我来想一个1~100的整数,您来猜:\n");
    int ans=rand()%100+1,tms=0,x;
    for(;;){
        Change_Color(WHITE);
        printf("请输入您的猜测(1~100):");
        scanf("%d",&x);
        if(x<1||x>100){
            Change_Color(RED);
            printf("您的猜测超出了值域,请重新输入,本次猜测不计入次数\n");
            continue;
        }
        tms++;
        if(x<ans){
            Change_Color(BLUE);
            printf("猜小了\n");
        }
        else if(x>ans){
            Change_Color(YELLOW);
            printf("猜大了\n");
        }
        else{
            Change_Color(GREEN);
            printf("恭喜您,猜对了!\n");
            break;
        }
    }
    Change_Color(PURPLE);
    printf("您一共猜了%d次\n",tms);
    Change_Color(WHITE);
    return;
}

bool Not_Is_Prime[100000];
int Prime[100000],Cnt_Prime;

void Split(int x){
    if(rand()%2==0||Not_Is_Prime[x]==0){
        printf("%d",x);
        return;
    }
    if(rand()%2==0){
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                printf("%d * %d",i,x/i);
                return;
            }
        }
    }else{
        int y=rand()%15+2;
        printf("%d / %d",x*y,y);
        return;
    }
    return;
}

int Make_Problem(){
    int num=rand()%2+2,ans=0;
    for(int i=1;i<=num;i++){
        int x=rand()%40+5;
        if(i==1){
        	Split(x);
            ans+=x;
        }else{
            if(rand()&1){
                printf(" + ");
                Split(x);
                ans+=x;
            }else{
                printf(" - ");
                Split(x);
                ans-=x;
            }
        }
    }
    printf(" = ?\n");
    return ans;
}

void game2(){
    printf("欢迎来到第二个游戏:口算!\n");
    int Number_Problem=0,Correct_Problem=0,tar;
    time_t Start_Time=time(NULL);
    printf("您准备练习几道题呢?\n");
    scanf("%d",&tar);
    for(;Correct_Problem<tar;){
        int Ans=Make_Problem(),yours;
        scanf("%d",&yours);
        Number_Problem++;
        if(Ans==yours){
            Correct_Problem++;
            Change_Color(GREEN);
            if(tar!=Correct_Problem){
            	printf("恭喜您,答对了,还剩%d题\n",tar-Correct_Problem);
			}else{
				printf("恭喜您,题目已经全部完成\n");
			}
            Change_Color(WHITE);
        }else{
            Change_Color(RED);
            printf("很遗憾,答错了,正确答案是%d,还剩%d题\n",Ans,tar-Correct_Problem);
            Change_Color(WHITE);
        }
    }
    time_t End_Time=time(NULL);
    printf("您一共花了%d秒\n",End_Time-Start_Time);
    printf("您的正确率是:%.2lf%%\n",100.0*Correct_Problem/Number_Problem);
}

int table[5][5];

void Clear_Table(){
    for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) table[i][j]=' ';
    return;
}

void Print_Table(){
    printf("-------------\n");
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            printf("| ");
            if(table[j][4-i]=='X') Change_Color(YELLOW);
            else if(table[j][4-i]) Change_Color(PURPLE);
            printf("%c ",table[j][4-i]);
            Change_Color(WHITE);
        }
        printf("|\n");
        printf("-------------\n");
    }
    return;
}

int Check_Table(){
    for(int i=1;i<=3;i++){
        if(table[i][1]=='X'&&table[i][2]=='X'&&table[i][3]=='X') return 1;
        if(table[1][i]=='X'&&table[2][i]=='X'&&table[3][i]=='X') return 1;
        if(table[i][1]=='O'&&table[i][2]=='O'&&table[i][3]=='O') return 2;
        if(table[1][i]=='O'&&table[2][i]=='O'&&table[3][i]=='O') return 2;
    }
    if(table[1][1]=='X'&&table[2][2]=='X'&&table[3][3]=='X') return 1;
    if(table[1][1]=='O'&&table[2][2]=='O'&&table[3][3]=='O') return 2;
    if(table[1][3]=='X'&&table[2][2]=='X'&&table[3][1]=='X') return 1;
    if(table[1][3]=='O'&&table[2][2]=='O'&&table[3][1]=='O') return 2;
    bool f=1;
    for(int i=1;i<=3;i++){
        bool f1=0,f2=0;
        for(int j=1;j<=3;j++){
            if(table[i][j]=='X') f1=1;
            if(table[i][j]=='O') f2=1;
        }
        if(!(f1&&f2)) f=0;
    }
    for(int i=1;i<=3;i++){
        bool f1=0,f2=0;
        for(int j=1;j<=3;j++){
            if(table[j][i]=='X') f1=1;
            if(table[j][i]=='O') f2=1;
        }
        if(!(f1&&f2)) f=0; 
    }
    bool f1=0,f2=0;
    for(int i=1;i<=3;i++){
        if(table[i][i]=='X') f1=1;
        if(table[i][i]=='O') f2=1;
    }
    if(!(f1&&f2)) f=0;
    f1=0;f2=0;
    for(int i=1;i<=3;i++){
        if(table[i][4-i]=='X') f1=1;
        if(table[i][4-i]=='O') f2=1;
    }
    if(!(f1&&f2)) f=0;
    if(f) return 3;
    return 0;
}

void Place_Stone(int opx,int opy){
    printf("我下在(%d,%d)\n",opx,opy);
    table[opx][opy]='O';
}

int Calculate_Value(int x,int y){
    int res=0;
    for(int i=1;i<=3;i++){
        int cnt1=0,cnt2=0,cnt0=0;
        if(table[x][i]==' ') cnt0++;
        else if(table[x][i]=='X') cnt1++;
        else cnt2++;
        if(cnt1==0){
            res+=cnt2*3+cnt1+cnt0*2;
        }
    }
    for(int i=1;i<=3;i++){
        int cnt1=0,cnt2=0,cnt0=0;
        if(table[i][y]==' ') cnt0++;
        else if(table[i][y]=='X') cnt1++;
        else cnt2++;
        if(cnt1==0){
            res+=cnt2*3+cnt1+cnt0*2;
        }
    }
    return res;
}

bool Cross1(int col){
    int cnt[3]={0,0,0};
    for(int i=1;i<=3;i++){
        if(table[i][i]=='X') cnt[1]++;
        else if(table[i][i]=='O') cnt[2]++;
        else cnt[0]++;
    }
    if(cnt[col]==2&&cnt[0]==1){
        for(int i=1;i<=3;i++){
            if(table[i][i]==' '){
                Place_Stone(i,i);
                return 1;
            }
        }
    }
    return 0;
}

bool Cross2(int col){
    int cnt[3]={0,0,0};
    for(int i=1;i<=3;i++){
        if(table[i][4-i]=='X') cnt[1]++;
        else if(table[i][4-i]=='O') cnt[2]++;
        else cnt[0]++;
    }
    if(cnt[col]==2&&cnt[0]==1){
        for(int i=1;i<=3;i++){
            if(table[i][4-i]==' '){
                Place_Stone(i,4-i);
                return 1;
            }
        }
    }
    return 0;
}

void Artificial_Fool(){
    Sleep(2000);
    for(int i=1;i<=3;i++){
        int cnt2=0,cnt0=0;
        for(int j=1;j<=3;j++){
            if(table[i][j]=='O') cnt2++;
            if(table[i][j]==' ') cnt0++;
        }
        if(cnt2==2&&cnt0==1){
            for(int j=1;j<=3;j++){
                if(table[i][j]==' '){
                    Place_Stone(i,j);
                }
            }
            return;
        }
    }
    for(int i=1;i<=3;i++){
        int cnt2=0,cnt0=0;
        for(int j=1;j<=3;j++){
            if(table[j][i]=='O') cnt2++;
            if(table[j][i]==' ') cnt0++;
        }
        if(cnt2==2&&cnt0==1){
            for(int j=1;j<=3;j++){
                if(table[j][i]==' '){
                    Place_Stone(j,i);
                }
            }
            return;
        }
    }
    if(Cross1(2)||Cross2(2)) return;
    for(int i=1;i<=3;i++){
        int cnt1=0,cnt0=0;
        for(int j=1;j<=3;j++){
            if(table[i][j]=='X') cnt1++;
            if(table[i][j]==' ') cnt0++;
        }
        if(cnt1==2&&cnt0==1){
            for(int j=1;j<=3;j++){
                if(table[i][j]==' '){
                    Place_Stone(i,j);
                }
            }
            return;
        }
    }
    for(int i=1;i<=3;i++){
        int cnt1=0,cnt0=0;
        for(int j=1;j<=3;j++){
            if(table[j][i]=='X') cnt1++;
            if(table[j][i]==' ') cnt0++;
        }
        if(cnt1==2&&cnt0==1){
            for(int j=1;j<=3;j++){
                if(table[j][i]==' '){
                    Place_Stone(j,i);
                }
            }
            return;
        }
    }
    if(Cross1(1)||Cross2(1)) return;
    int stcx[1000],stcy[1000],tp=0;
    int val[4][4]={{0,0,0,0},{0,rand()%4,rand()%4,rand()%4},{0,rand()%4,rand()%10,rand()%4},{0,rand()%4,rand()%4,rand()%4}};
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(table[i][j]==' '){
                int value=val[i][j]*Calculate_Value(i,j)+1;
                for(int k=1;k<=value;k++){
                    stcx[tp]=i;stcy[tp]=j;
                    tp++;
                }
            }
        }
    }
    int Rd=rand()%tp;
    Place_Stone(stcx[Rd],stcy[Rd]);
    return;
}

void game3(){
    printf("欢迎来到第三个游戏:井字棋!\n");
    printf("让我来和您下棋,您先下:\n");
    Clear_Table();
    Print_Table();
    int cnt=1;
    for(;;){
        if(cnt&1){
            printf("轮到您走了,您要下在哪里?(x,y):\n");
            int opx,opy;
            scanf("%d%d",&opx,&opy);
            if((opx<1||opx>3||opy<1||opy>3)||(table[opx][opy]!=' ')){
                Change_Color(RED);
                printf("您输入的坐标不合法!请重新输入!\n");
                Change_Color(WHITE);
                continue;
            }
            table[opx][opy]='X';
        }else{
            Artificial_Fool();
        }
        Print_Table();
        int chk=Check_Table();
        if(chk==3){
            printf("平局了!\n");
            return;
        }else if(chk==1){
            printf("您赢了!\n");
            return;
        }else if(chk==2){
            printf("我赢了!\n");
            return;
        }
        cnt++;
    }
    return;
}

bool Begin(){
    system("cls");
    Change_Color(WHITE);
    printf("游戏目录:\n1.猜数\n2.口算\n3.井字棋\n");
    printf("请问您想要玩第几个游戏?(请输入对应的数字)\n");
    int x;
    scanf("%d",&x);
    system("cls");
    if(x==1) game1();
    else if(x==2) game2();
    else if(x==3) game3();
    Sleep(1000);
    printf("游戏结束!\n");
    Sleep(1000); 
    printf("您还想要再玩吗?(1继续游玩/2结束游玩)\n");
    int cnn;
    scanf("%d",&cnn);
    system("cls");
    return cnn==2;
}

void init(){
    for(int i=2;i<=1000;i++){
        if(!Not_Is_Prime[i]){
            Prime[++Cnt_Prime]=i;
        }
        for(int j=1;j<=Cnt_Prime&&Prime[j]*i<=1000;j++){
            Not_Is_Prime[Prime[j]*i]=1;
            if(i%Prime[j]==0) break;
        }
    }
    Change_Color(WHITE);
    printf("欢迎来到小游戏合集!\n作者:\n    杨佳明、徐浩腾、薛心昊、杨盛超、马子腾、李脉琦\n");
    srand(time(NULL));
    Sleep(3000);
    return;
}

int main(){
    init();
    for(;;){
        if(Begin()) break;
    }
    printf("再见!");
    return 0;
}