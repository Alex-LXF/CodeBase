#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
void menu()
{
    printf("         [菜单]         \n");
    printf("*****1.求最大公约数*****\n");
    printf("*****2.获取当前时间*****\n");
    printf("*****3.判断是否闰年*****\n");
    printf("*****4.退出        *****\n");
}

int main()
{
  int input;
  while(1)
  {
    menu();
    pid_t pid;
    pid_t pid1;
    pid_t pid2;
    printf("请输入选项：-> ");
    scanf("%d",&input);
    printf("\n");
    switch(input)
    {
      case 1: pid = fork();
              if(pid < 0)
              {
                printf("1号进程创建失败。\n");
                return -1;
              }
              if(pid == 0)
              {
                execl("./gcd", "./gcd", NULL);
              }
              wait(NULL);
              break;
      case 2: pid1 = fork();
              if(pid1 < 0)
              {
                printf("2号进程创建失败。\n");
                
              }
              if(pid1 == 0)
              {
                execl("./get","./get",NULL);
              }
              wait(NULL);
              break;
      case 3: pid2 = fork();
              if(pid2 < 0)
              {
                printf("3号进程创建失败。\n");
                
              }
              if(pid2 == 0)
              {
                execl("./isly","./isly",NULL);
              }
              wait(NULL);
              break;
      case 4: printf("退出程序！\n");
              return 0;
              break;
      default: printf("输入选项错误！\n");
               break;
    }
    printf("\n");
    printf("--------------------------------------\n");
    printf("\n");
    sleep(1);
  }
  return 0;
}

