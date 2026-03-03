#include <iostream>
#include <list>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <conio.h>
#include <windows.h>
using namespace std;
class Node {
public:
    int x, y;
    Node(int x1, int y1);
};
 
class UserData {
public:
    string name;
    long long score;
    int gt;
    int gr;
    UserData(string s, long long sc,int gametime,int grade);
    friend bool operator < (UserData a, UserData b);
};
 
#define RIGHT 0x4d
#define LEFT 0x4b
#define UP 0x48
#define DOWN 0x50
#define YELLOW FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define CYAN FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define ORANGE FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define PURPLE FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define RED  FOREGROUND_RED | FOREGROUND_INTENSITY
const int STARTX = 8;
const int STARTY = 4;
const int RANGEX = 60;
const int RANGEY = 20;
int point=10;
const int ENDX = STARTX + RANGEX;
const int ENDY = STARTY + RANGEY;
bool isSnake[RANGEY + 10 ][RANGEX + 10];
int speed;
int sysj;
int gametime;
list<Node> snake;
int curDiraction; //蛇的当前前进方向, 1上, 2下, 3左, 4右
int score; //当前分数
int grade;
int snakeLen; //蛇的长度
int foodx, foody; //食物坐标
int gox, goy; //蛇头坐标
int mj;
void GoTo(short x, short y); //定位光标
void DrawBoard(); //绘制边框
void ShowInformation(); //展示游戏信息
void Init(); //初始化游戏
void RunSnake(int x, int y); //绘制蛇身
void Try(int& x, int& y); //试走
bool IsGoodCoord(int x, int y); //前进坐标是否合法
void AddFood();
void EartFood();
void InitSnake();
bool EndGame();
bool StartGame();
bool GameMenu(); //游戏菜单
void ShowRanking(); //排行榜
void ShowAbout(); //相关信息
void InputData(); //输入玩家名字
 
int main() {
    while (true) {
        if (!GameMenu()) return 0;
    }
    return 0;
}
 
Node::Node(int x1, int y1) { //构造Node对象
    x = x1; y = y1;
}
 
int SuiJi()
{
srand((unsigned)time(NULL));
return (rand()*rand()+rand()*rand())%14;
}
 
bool operator < (UserData a, UserData b) { //重载运算符，按分数由大到小排列
    if(a.score != b.score)
    return a.score > b.score;
    if(a.gt !=b.gt)
    return a.gt > b.gt;
    else
    return a.gr > b.gr;
}
UserData::UserData(string s, long long sc,int gametime_,int _grade) { //构造UserData对象
    name = s; score = sc; gt=gametime_; gr=_grade;
}
 
void color(WORD A)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), A);
}
 
void Color(int a)
{
    switch (a%4)
    {
        case 0:color(RED);break;
        case 1:color(CYAN);break;
        case 2:color(YELLOW);break;
        case 3:color(PURPLE);break;
    }
}
 
void GoTo(short x, short y) { //定位光标
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
 
void ShowInformation() { //输出游戏信息
    color(YELLOW);
    GoTo(78, 5);
    printf("贪吃蛇游戏");
    GoTo(78,18);
    gametime=(clock()-mj)/1000;
    grade=snakeLen-3;
    printf("生存时间：%3d 秒",(clock()-mj)/1000);
    GoTo(78, 8);
    printf("游戏规则：");
    GoTo(78, 10);
    printf("请按 ↑ ↓ ← →  来控制您的蛇吃东西");
    GoTo(78, 12);
    printf("吃的越多，蛇就越长，您的等级也将越高");
    GoTo(78, 14);
    printf("当蛇吃到自己或撞上墙时，游戏结束。");
    GoTo(78,16);
    printf("自动前进时间：%3dms",speed);
    GoTo(78, 20);
    printf("当前等级： %8d", snakeLen-3);
    GoTo(78, 23);
    printf("您的分数： %d", score);
    color(CYAN);
    printf("+%d=%d",score/3,score*3/2);
    color(YELLOW);
    GoTo(78,25);
    printf("剩余时间：%d秒",20+(snakeLen-3)*5-gametime);
    sysj=20+(snakeLen-3)*5-gametime;
}
 
void DrawBoard() { //绘制墙体
 
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); //获得输出句柄
 
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 }; //光标信息
    SetConsoleCursorInfo(hOut, &cursor_info); //隐藏光标
 
    COORD size = { 120, 30 };
    SetConsoleScreenBufferSize(hOut, size); //重设缓冲区大小
 
    SMALL_RECT rc = { 0 , 0, 120, 30 };
    SetConsoleWindowInfo(hOut, true, &rc); //重设窗口大小
 
    SetConsoleTextAttribute(hOut, CYAN);
 
    for (int i = STARTX - 2; i <= ENDX + 2; i += 2) { //横向墙体
        GoTo(i, STARTY - 1);
        printf("■");
        GoTo(i, ENDY + 1);
        printf("■");
    }
    for (int i = STARTY - 1; i <= ENDY + 1; ++i) { //竖向墙体
        GoTo(STARTX - 2, i);
        printf("■");
        GoTo(ENDX + 2, i);
        printf("■");
    }
}
void draw()
{
    char m=snakeLen+62;
    Color(score);
    cout<<m;
 }
void Init() { //初始化游戏
    system("cls");
    memset(isSnake, 0, sizeof(isSnake));
    speed = 200;
    curDiraction = 4;
    score = 0;
    DrawBoard();
    InitSnake();
    ShowInformation();
    AddFood();
    mj=clock();
    point=20;
    sysj=20;
}
 
void RunSnake(int x, int y) { //绘制蛇身
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    score += snakeLen + 1;
    if (x == foodx && y == foody) {
        EartFood();
        AddFood();
        return;
    }
    DrawBoard();
    snake.push_front(Node(x, y));
    isSnake[y][x] = true;
    GoTo(x, y);
    draw();
    Node back = snake.back();
    snake.pop_back();
    isSnake[back.y][back.x] = false;
    GoTo(back.x, back.y);
    printf(" ");
}
 
void Try(int& x, int& y) { //试走
    int key, cnt = 100;
    while (cnt--) { //多次检测键盘状态
        if (_kbhit()) {
            key = getch();
            switch (key) {
            case UP:
//                if (curDiraction == 1 || curDiraction == 2) break;
                --y; curDiraction = 1; return;
            case DOWN:
//                if (curDiraction == 1 || curDiraction == 2) break;
                ++y; curDiraction = 2; return;
            case LEFT:
//                if (curDiraction == 3 || curDiraction == 4) break;
                x -= 2; curDiraction = 3; return;
            case RIGHT:
//                if (curDiraction == 3 || curDiraction == 4) break;
                x += 2; curDiraction = 4; return;
            }
        }
    }
    if (curDiraction == 1) --y; //用户没有输入时
    else if (curDiraction == 2) ++y;
    else if (curDiraction == 3) x -= 2;
    else x += 2;
}
 
bool IsGoodCoord(int x, int y) { //判断光标是否合法
    if (x <= ENDX && y <= ENDY && x >= STARTX && y >= STARTY)
        return true;
    else
        return false;
}
 
void AddFood() { //增加食物
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), PURPLE);
    srand((unsigned)time(NULL));
    while (true) {
        foodx = (rand()%ENDX) + 1;
        foody = (rand()%ENDY) + 1;
        if (foodx&1) foodx++;
        if (!isSnake[foody][foodx] && IsGoodCoord(foodx, foody)) break;
    }
    GoTo(foodx, foody);
    int a=rand()%5;
    if(a>=4)
    printf("@");
    else if(a<=1)
    printf("#");
    else
    printf("&");
}
 
void EartFood() { //吃东西
    point+=4;
    int sb=gametime=(clock()-mj)/1000;
    sysj=point-sb;
    score+=score/2;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    snake.push_front(Node(foodx, foody));
    isSnake[foody][foodx] = true;
    ++snakeLen;
    if (speed >= 55) speed -= 5;
 
    GoTo(foodx, foody);
    draw();
    AddFood();
}
 
void InitSnake() { //初始化蛇身
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    snakeLen = 3, gox = 18, goy = 14;
    snake.clear();
    snake.push_front(Node(12, 14));
    snake.push_front(Node(14, 14));
    snake.push_front(Node(16, 14));
    for (int i = 12; i <= 16; i += 2) {
        GoTo(i, 14);
        draw();
        isSnake[14][i] = true;
    }
}
bool EndGame() { //结束游戏
    system("cls");
    DrawBoard();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    GoTo(28, 10);
    printf("您的本局游戏得分： %d分", score);
    GoTo(32, 18);
    printf("....你挂了....");
    GoTo(27, 20);
    printf("是否继续游戏: 是(1), 否(0)");
    GoTo(27, 22);
    char key = getch();
    while (true) {
        if (key == '1') return false;
        else if (key == '0')
        {GoTo(ENDX+1,ENDY+2);
        exit(0);return true;
        }
        else key = getch();
    }
}
 
bool StartGame() { //启动游戏
 
    Init();
 
    while (sysj>0) { //开挂
        RunSnake(gox, goy);
        ShowInformation();
        Try(gox, goy);
        Sleep(speed);
    }
    InputData();
    return true;
}
 
bool GameMenu() { //游戏菜单
    system("cls");
    DrawBoard();
    GoTo(STARTX + 22, STARTY + 4);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
    printf("欢迎进入贪吃蛇游戏!");
    GoTo(STARTX + 24, STARTY + 10);
    printf("1: 新游戏");
    GoTo(STARTX + 24, STARTY + 12);
    printf("2: 排行榜");
    GoTo(STARTX + 24, STARTY + 14);
    printf("3: 关于游戏");
    GoTo(STARTX + 24, STARTY + 16);
    printf("4: 退出游戏");
 
    while (true) {
        if (_kbhit()) {
            char key = getch();
            switch (key) {
            case '1':
                if (!StartGame()) return false;
                else return true;
            case '2':
                ShowRanking(); return true;
            case '3':
                ShowAbout(); return true;
            case '4':
                GoTo(1,ENDY+2);
                return false;
            default:
                return true;
            }
        }
    }
}
 
void ShowRanking() { //展示排行榜
    vector<UserData> vu;
    FILE *fp = fopen("Gamedata2.txt", "r");
    if (fp == NULL) fp = fopen("Gamedata2.txt", "w+");
    char name[20];
    int len = 0;
    while (fscanf(fp, "%s", name) != EOF) {
        ++len;
        int score,g=grade;
        fscanf(fp, "%d%d%d%*c", &score,&gametime,&g);
        vu.push_back(UserData(string(name), score,gametime,g));
    }
    fclose(fp);
    sort(vu.begin(), vu.end()); //对得分进行排名
    system("cls");
    DrawBoard();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CYAN);
    GoTo(STARTX + 8, STARTY + 2);
    printf("用户");
    GoTo(STARTX + 20, STARTY + 2);
    printf("分数");
    GoTo(STARTX + 32, STARTY + 2);
    printf("生存时间");
    GoTo(STARTX + 44, STARTY + 2);
    printf("排行");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
 
    for (int i = 0; i < len && i < 10; ++i) { //打印前十名用户数据
        char const *p = vu[i].name.c_str();
        Color(score);
        GoTo(STARTX + 8, STARTY + 4 + i);
        printf("%s", p);
        GoTo(STARTX + 20, STARTY + 4 + i);
        printf("%d分", vu[i].score);
        GoTo(STARTX + 32, STARTY + 4 + i);
        printf("%d秒", vu[i].gt);
        GoTo(STARTX + 44, STARTY + 4 + i);
        printf(" %d", i + 1);
    }
 
    GoTo(STARTX + 4, ENDY - 2);
    printf("-----------------  按'1'返回游戏菜单  ---------------");
    while (true) {
        if (_kbhit()) {
            char key = getch();
            if (key == '1') break;
        }
    }
}
 
void ShowAbout() { //展示游戏相关
    system("cls");
    DrawBoard();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
 
    GoTo(STARTX + 4, STARTY + 2);
    printf("-------------------  贪吃蛇游戏  -------------------");
    GoTo(STARTX + 10,STARTY + 8);
    printf("贪吃蛇游戏");
    GoTo(STARTX + 10,STARTY + 10);
    printf("游戏规则：");
    GoTo(STARTX + 10,STARTY + 12);
    printf("请按 ↑ ↓ ← →  来控制您的蛇吃东西");
    GoTo(STARTX + 10,STARTY + 14);
    printf("吃的越多，蛇就越长，您的等级也将越高");
    GoTo(STARTX + 10,STARTY + 16);
    printf("当蛇吃到自己或撞上墙时，游戏结束。");
 
    GoTo(STARTX + 4, ENDY - 2);
    printf("-----------------  按'1'返回游戏菜单  ---------------");
    while (true) {
        if (_kbhit()) {
            char key = getch();
            if (key == '1') break;
        }
    }
}
 
void InputData() { //用户输入名字
    char name[20];
    if(score>=1000)
    {
    GoTo(STARTX + 10, STARTY + 10);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
    printf("请输入你的名字: ");
    COORD coord = { STARTX + 10, STARTY + 12 };
    SetConsoleCursorPosition(GetStdHandle(STD_INPUT_HANDLE), coord);
    while (true) { //忽略非法字符
        scanf("%s", name);
        if (name[0] != 0 && name[0] != ' ') break;
    }FILE *fp = fopen("Gamedata2.txt", "a");
    if (fp == NULL) fp = fopen("Gamedata2.txt", "w+");
    fprintf(fp, "%s %d %d \n", name, score,gametime);
    fclose(fp);
    }
    else
    {
        GoTo(STARTX + 20, STARTY + 10);
        cout<<"哟！这分数也能上榜？？"<<endl;
        Sleep(1000);
     }
    EndGame();
 
}