#include <stdio.h>
#include <time.h>

int main()
{
  

  time_t  now;
  struct  tm  *w;
  time(&now);
  w=localtime(&now);
  printf("现在时间为：\n");
  printf("%04d/%02d/%02d\n%02d:%02d:%02d\n",w->tm_year+1900,
         w->tm_mon+1, w->tm_mday, w->tm_hour, w->tm_min, w->tm_sec);
  return 0;
}
