#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 设置随机数种子
    srand(time(NULL));
    
    // 生成1-100之间的随机数
    int answer = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    
    printf("欢迎来到猜数字游戏！\n");
    printf("我已经想好了一个1到100之间的数字。\n");
    
    // 游戏主循环
    do {
        printf("请输入你的猜测（1-100）：");
        scanf("%d", &guess);
        attempts++;
        
        if (guess < answer) {
            printf("猜小了！\n");
        } else if (guess > answer) {
            printf("猜大了！\n");
        } else {
            printf("恭喜你！猜对了！\n");
            printf("正确答案是：%d\n", answer);
            printf("你一共猜了%d次。\n", attempts);
        }
    } while (guess != answer);
    
    return 0;
}