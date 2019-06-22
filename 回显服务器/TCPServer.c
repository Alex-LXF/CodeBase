#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>

void *read_msg(void *argc)  
{     
   int fd = *((int *)argc);  
   printf("fd = %d\n",fd);       
      
   char recvbuff[20] = {0};     
   int recvcnt = 0;            
      
   while(1)  
   {
     bzero(recvbuff,sizeof(recvbuff));     //先清空recvbuff里面的内容。  
     recvcnt = read(fd,recvbuff,sizeof(recvbuff));//从recvbuff中读取内容 
     if(recvcnt == -1)  
     {  
       perror("recv");  
       return NULL;  
     }  
     else if(recvcnt == 0)             
     {  
       printf("The Client is closed!\n");  
       break;  
     }  
     else  
     {  
      printf("Recv from Client %d bytes,data:%s\n",recvcnt,recvbuff);  //打印接收到的信息  
     }  
     if(strcmp(recvbuff,"end") == 0)  
     {  
       break;  
     }  
   }  
  close(fd);  
  return NULL;  
}  

int main()
{
  int sockfd;
  pthread_t th;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0)
  {
    printf("socket error!");
    return -1;
  }

  struct sockaddr_in client_addr;
	struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
  server_addr.sin_port = htons(8888);

  int ret;
  ret = bind(sockfd,(struct sockaddr*)&server_addr, sizeof(struct sockaddr));
  if(ret < 0)
  {
    printf("bind error!");
    return -1;
  }
  
  ret = listen(sockfd, 5);
  if(ret < 0)
  {
    printf("listen error!");
    return -1;
  }
  printf("wait for connect...\n");
  int clientfd;
  socklen_t len = sizeof(struct sockaddr);
  while(1)
  {
		clientfd = accept(sockfd,(struct sockaddr*)&client_addr,&len);
		if(clientfd < 0)
    {
      printf("accept error!");
      return -1;
    }
		printf("clinet connect!\n");
    ret = pthread_create(&th, NULL, read_msg, &clientfd);
    if(ret != 0)
    {
      printf("pthread error!");
      return -1;    
    }
  }
  
  close(sockfd);
  return 0;
}
