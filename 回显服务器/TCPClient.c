#include <stdio.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>
#include <string.h>  
#include <unistd.h>  
#include <sys/wait.h>  
#include <pthread.h>  

int main()  
{  
    //参数入口检查；  
   // if(argc != 2)           
    //{  
      //  perror("argc");  
        //return -1;  
    //}  
    int sockfd;
    int ret; 
      
    struct sockaddr_in server_addr; 
      
    sockfd = socket(AF_INET,SOCK_STREAM,0);        //第一步还是创建套接字  
    if(sockfd < 0)  
    {  
        printf("socket error!");  
        return -1;  
    }  
    printf("socket success...\n");  
    
    server_addr.sin_family = AF_INET;  
    server_addr.sin_port = htons(8888);  
    server_addr.sin_addr.s_addr = inet_addr("192.168.0.232");  
      
    ret = connect(sockfd,(struct sockaddr*)&server_addr,sizeof(struct sockaddr));        //连接服务器  
    if(ret < 0)  
    {  
        printf("connect error");  
        return -1;  
    }  
      
    char sendbuff[20] = {0};  
    int sendcnt = 0;  
      
    while(1)  
    {  
        //输入要发送的数据；  
        printf("Please input a string:\n");  
        scanf("%s",sendbuff);  
          
        //发送数据  
        sendcnt = write(sockfd,sendbuff,strlen(sendbuff));  
        if(sendcnt == -1)  
        {  
            perror("send");  
            return -1;  
        }  
        else  
        {  
            printf("Send to Server %d bytes,data:%s\n",sendcnt,sendbuff);  
        }  
        // 判断数据是否完毕  
        if(strcmp(sendbuff,"end") == 0)  
        {  
            close(sockfd);  
            break;  
        }  
    }  
          
    return 0;  
}  
