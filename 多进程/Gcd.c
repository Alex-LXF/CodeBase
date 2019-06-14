#include <stdio.h>

int Gcd(int a, int b)
{
  int c;
	if(a < b)
	{	a = a + b;
		b = a -b;
		a = a -b;
	}
	c = a % b;
	while(a % b != 0)
	{	a = b;
		b = c;
		c = a % b;	
	}
	return b;
}

int main()
{
  int a = 0;
  int b = 0;
  printf("请输入两个数：");
  scanf("%d%d",&a, &b);
  int gcd = Gcd(a, b);
  printf("%d和%d的最大公约数为：%d\n",a,b,gcd);
  return 0;
}
