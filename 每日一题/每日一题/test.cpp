#define _CRT_SECURE_NO_WARNINGS 1
/* 牛牛举办了一次编程比赛, 参加比赛的有3*n个选手, 每个选手都有一个水平值a_i.
现在要将这些选手进行组队, 一 共组成n个队伍, 即每个队伍3人.
牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
例如 :
一个队伍三个队员的水平值分别是3, 3, 3.那么队伍的水平值是3
一个队伍三个队员的水平值分别是3, 2, 3.那么队伍的水平值是3
一个队伍三个队员的水平值分别是1, 5, 2.那么队伍的水平值是2
为了让比赛更有看点, 牛牛想安排队伍使所有队伍的水平值总和最大。
//*/
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	long long sum = 0;
//	int n = 0;
//	cout << "请输入队伍个数：" ;
//	while (cin >> n)
//	{
//		vector<int> a;
//		a.resize(3 * n);
//		cout << "请输入所有队员的水平值：";
//		for (int i = 0; i < 3 * n; i++)
//		{
//			cin >> a[i];
//		}
//		sort(a.begin(), a.end());
//		// 1 2 3 4 5 6
//		for (int i = n; i < 3 * n - 1; i += 2)
//
//		{
//			sum += a[i];
//		}
//
//		cout << "所有队伍的水平值总和最大为：sum = " << sum << endl;
//		
//	}
//	return 0;
//}
//
//
//
//
//
//
//




//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int main(){
//	int n;
//	while (cin >> n){
//		long long sum = 0;
//		vector<int> a(3 * n);
//		for (int i = 0; i < (3 * n); i++){
//			cin >> a[i];
//		}
//		sort(a.begin(), a.end());
//		for (int i = n; i <= 3 * n - 2; i += 2){
//			sum += a[i];
//		}
//		cout << sum << endl;
//	}
//}
//#include <iostream>
//#include <string>
//
//using namespace std;
//int main()
//{
//	string str1;
//	string str2;
//	cin >> str1;
//	cout << endl;
//	cin >> str2;
//		for (int i = 0; i < str2.size(); i++)
//		{
//			int j = 0;
//			while (j < str1.size())
//			{
//				if (str2[i] == str1[j])
//				{
//					str2.erase(str1.begin()+j);
//				}
//				j++;
//			}
//		}
//		cout << str1 << endl;
//}
//	

//
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//
//	int a[5] = {1,3,5,7,9};
//	int *p = (int *)(&a + 1);
//	printf("%d %d", *(a + 1), *(p - 1));
//	system("pause");
//	return 0;
//}
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <cstdlib>
//using namespace std;
//
//int main()
//{
//	string str1;
//	string str2;
//	cin >> str1 >> str2;
//	int count = 0;
//	int len = str1.length();
//	for (int pos = 0; pos <= len; pos++)
//	{
//		string str = str1.substr(0, pos) + str2 + str1.substr(pos, len);
//		string str4(str.rbegin(), str.rend());
//		if (str == str4)
//		{
//			count++;
//		}
//	}
//	cout << count << endl;
//
//	system("pause");
//	return 0;
//}
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cstdlib>
//
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	int maxsum = 0;
//	cin >> n;
//		int v[n];
//		for (int i = 0; i < v.size(); i++)
//		{
//			cin >> v[i];
//		}
//		for (int i = 0; i < v.size(); i++)
//		{
//			int sum = v[i] + v[i + 1];
//			if (sum > maxsum)
//			{
//				maxsum = sum;
//			}
//		}
//
//		cout << maxsum << endl;
//	}
//	system("pause");
//
//	return 0;
//}


//#include <iostream>
//#include <cstdlib>
//
//using namespace std;
//
//struct A{
//	long a1;
//	short a2;
//	int a3;
//	long long a4;
//};
//int f(int n)
//{
//	if (n == 1)
//		return 1;
//	return (f(n - 1) + n*n*n);
//}
//
//char fun(char a, char b)
//{
//	if (a < b)
//		return a;
//	return b;
//}
//
//int main()
//{
//	int a = '1', b = '1', c = '2';
//	cout << f(3) << endl;
//	//cout << fun(fun(a, b), fun(b, c));
//	system("pause");
//	return 0;
//}
//
//void main()
//{
//	int a = 1, b = 0, c = -1, d = 0;
//	d = ++a || ++b && ++c;
//	cout << d << endl;
//	system("pause");
//	return;
//}
#if 0
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int n;
char a[101][100];
int car1()
{
	int i;
	for (i = 0; i < n - 1; i++)
	if (strcmp(a[i], a[i + 1]) > 0)
		return 0;
	return 1;
}
int car2()
{
	int i;
	for (i = 0; i < n - 1; i++)
	if (strlen(a[i]) > strlen(a[i + 1]))
		return 0;
	return 1;
}
#endif
//int main()
//{
//	cin >> n;
//	int i;
//	for (i = 0; i < n; i++)
//		cin >> a[i];
//	if (car1() && car2())
//		cout << "both" << endl;
//	else if (car1() && !car2())
//		cout << "lexicographically" << endl;
//	else if (!car1() && car2())
//		cout << "lengths" << endl;
//	else if (!car1() && !car2())
//		cout << "none" << endl;
//	system("pause");
//	return 0;
//}


//struct A
//{
//	int a;
//	short b;
//	int c;
//	char d;
//};
//
//struct B
//{
//	int a;
//	short b;
//	char c;
//	int d;
//};
//
//int foo(int n)
//{
//	if (n < 2)
//		return n;
//	else
//		return 2 * foo(n - 1) + foo(n - 2);
//}


//int main()
//{
//
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	cout << foo(5) << endl;
//	system("pause");
//	return 0;
//}
#if 0
void main()
{
	int x, y;
	x = 3, y = 3;
	switch (x % 2){
	case 1:
		switch (y){
		case 0: cout << "first";
		case 1: cout << "second"; break;
		default:cout << "hello";
		}
	case 2: cout << "third";
	}
	system("pause");

}
#endif

#include <iostream>
#include <cstdlib>
using namespace std;
#if 0
int Fun(int n)
{
	if (n == 5)
		return 2;
	return 2 * Fun(n + 1);
}

int main()
{

/*
	int num = 9999;
	int count = 0;
	while (num)
	{
		count++;
		num = num & (num - 1);
	}
	cout << Fun(2) << endl;
	cout << count << endl;*/
	int i = 1;
	if (i <= 0)
		printf("*****\n");
	else
		printf("%%%%%\n");


	system("pause");
	return 0;
}
#endif
#if 0
struct A
{
	void foo()
	{
		cout << "foo" << endl;
	}
	virtual void bar()
	{
		cout << "bar" << endl;
	}

	A()
	{
		bar();
	}
};
struct  B : A
{
	void foo()
	{
		cout << "b_foo" << endl;
		
	}
	void bar()
	{
		cout << "b_bar" << endl;
	}
};
#include <iostream>
#include <string>
using namespace std;

class Printer
{
public:
	Printer(string name)
	{
		cout << name << endl;
	}
};
class Container
{
public:
	Container() :b("b"), a("a"){}
	Printer a;
	Printer b;
};


int main()
{
	/*A* b = new B;
	b->foo();
	b->bar();*/

	Container c;


	system("pause");
	return 0;
}
#endif

#if 0

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string password;
	while (getline(cin, password)){
		int len = password.size();
		int score = 0;
		int alphabet = 0;
		int Alphabet = 0;
		int num = 0;
		int num_count = 0;
		int symbol = 0;
		int symbol_count = 0;
		if (len <= 4)
			score += 5;
		else if (len > 4 && len <= 7)
			score += 10;
		else if (len >= 8)
			score += 20;
		for (int i = 0; i < len; i++)
		{
			
			if (password[i] >= 'a' && password[i] <= 'z')
			{
				alphabet = 1;
			}

			else if (password[i] >= 'A' && password[i] <= 'Z')
			{
				Alphabet = 1;
			}

			else if (password[i] >= '0' && password[i] <= '9')
			{
				num = 1;
				num_count++;
			}
			else
			{
				symbol = 1;
				symbol_count++;
			}
		}
		if ((alphabet == 1 && Alphabet == 0) || (alphabet == 0 && Alphabet == 1))
			score += 10;
		else if (alphabet == 1 && Alphabet == 1)
			score += 20;
		if (symbol_count > 1)
			score += 25;
		else if(num_count == 1)
			score += 10;
		if (Alphabet && alphabet && num && symbol)
			score += 5;
		else if ((Alphabet || alphabet) && num && symbol)
			score += 3;
		else if ((Alphabet || alphabet) && num)
			score += 2;

		switch (score / 10){
		case 9: cout << "VERY_SECURE" << endl;
			break;
		case 8: cout << "SECURE" << endl;
			break;
		case 7: cout << "VERY_STRONG" << endl;
			break;
		case 6: cout << "STRONG" << endl;
			break;
		case 5: cout << "AVERAGE" << endl;
			break;
		default:
		{
				   if (score >= 25)
					   cout << "WEAK" << endl;
				   else if (score >= 0)
					   cout << "VERY_WEAK" << endl;
		}
		}

	}
	return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

int main()
{
	int n[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl;

	system("pause");
	return 0;
}



#include <iostream>

using namespace std;

#define SQR(A) A*A

void main()
{
	int x = 6, y = 3, z = 2;

	x /= SQR(y + z) / SQR(y + z);
	cout << x << endl;
	system("pause");
}
#endif
#if 0
#include <iostream>

int main()
{
	int i, a[10];
	for (i = 9; i >= 0; i--)
	{
		a[i] = 10 - i;

	}
	cout << a[2] << a[5] << a[8] << endl;

	system("pause");
	return 0;
}
#endif
#if 0
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{

	char ccstring1[] = "Is Page Falut ??";
	char ccstring2[] = "No Page Falut ??";
	strcpy(ccstring1,"No");
	/*if (strcmp(ccstring1, ccstring2) == 0){
		cout << ccstring2;
	}
	else{
		cout << ccstring1;*/

	//}
	cout << ccstring1;
	/*char dog[] = "wang\0miao";
	cout <<	strlen(dog);
	cout<<sizeof(dog);*/
	system("pause");
	return 0;
}

#endif

#include <iostream>
using namespace std;

int function(unsigned int n)
{
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);

	return n;
}



int main()
{
	cout << function(197);

	system("pause");
	return 0;
}

