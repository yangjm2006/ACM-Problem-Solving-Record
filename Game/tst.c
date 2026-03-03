
#include <stdio.h>
#include <windows.h>
int main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 0xC );
    puts("红色文字");
    SetConsoleTextAttribute(hConsole, 0xF );
    puts("白色文字");
    SetConsoleTextAttribute(hConsole, 2 );
    puts("淡绿色文字");
    return 0;
}