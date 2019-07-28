#include <iostream>
#include "MD5.h"

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << argv[0] << "\t0\tfilename" << std::endl;
		std::cout << argv[0] << "\t1\tStringname" << std::endl;
		return 0;
	}
	MD5 md5;
	char option = *argv[1];
	switch(option)
	{
		case '0':
			std::cout << " 此文件的 MD5 是：" << md5.getFileMd5(argv[2]);
			break;
		case '1':
			std::cout << " 此字符串的 MD5 是：" << md5.getStringMd5(argv[2]);
			break;
	}

	return 0;
}