#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#define Length 100

int main()
{	
    int fd, len;
    char str[Length];
    fd = open("hello.txt",O_CREAT|O_RDWR|O_APPEND,S_IRUSR|S_IWUSR);
    const char* msg = "This is My Schoolnumber:16407010328.";
    len = strlen(msg);
    if(fd)
    {
	write(fd,msg,len);
    	close(fd);	
    }
    else if(fd < 0)
    {
       perror("open error1!");
       return 1;
    }
    fd = open("hello.txt",O_RDONLY);
    if(fd < 0)
    {
       perror("open error2!");
       return 1;
    }

    while(1)
    {
       ssize_t s = read(fd, str, len);
       if(s > 0)
       {
	  printf("%s",str);
	  printf("\n");
       }
       else
       {
          break;
       }
    }
    close(fd);	
    
    return 0;
}
