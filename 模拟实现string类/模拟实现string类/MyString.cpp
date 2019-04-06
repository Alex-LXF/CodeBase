#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;
const char* StrStr(const char* dest, const char* substr);

class String
{
public:
	typedef char* iterator;
	typedef const char* const_iterator;
	//全缺省构造函数 
	String(const char* str = "") //缺省值 ""

		:_size(strlen(str))
		, _capacity(_size)
		, _str(new char[_size + 1])
	{
		strcpy(_str, str);
	}

	//拷贝构造函数
	String(const String& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		Swap(tmp); //相当于Swap(this, tmp)
	}

	void Swap(String& tmp)
	{
		swap(_str, tmp._str);
		swap(_size, tmp._size);
		swap(_capacity, tmp._capacity);
	}

	String& operator=(String s)
	{
		Swap(s);
		return *this;
	}

	const char* c_str()
	{
		return _str;
	}

	//析构函数
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

	//尾插
	void PushBack(const char c)
	{
		//判断容量是否足够，不够增容
		if (_size = _capacity)
		{
			size_t newC = (_capacity == 0 ? 15 : 2 * _capacity);
			Reserve(newC);
		}

		_str[_size++] = c; //在_size位置插入，之后_size+1更新
		_str[_size] = '\0'; //将'\0'插入_size位置
	}

	//尾删
	void PopBack()
	{
		assert(_size > 0); //确保_size至少含有一个元素
		_str[--_size] = '\0'; 
	}

	//尾插字符串
	void Append(const char* str)
	{
		size_t sz = strlen(str);
		if (_size + sz > _capacity) //检查容量
		{
			Reserve(_size + sz); //扩容
		}
		strcpy(_str + _size, str); //在目标字符串后插入新的字符串 
		_size += sz; //更新_size
	}

	//插入字符c
	void Insert(size_t pos, const char c)
	{
		assert(pos >= 0 && pos <= _size); //判断插入位置是否正确
		if (_size == _capacity) //检查容量
		{
			//扩容
			size_t newC = (_capacity == 0 ? 15 : 2 * _capacity);
			Reserve(newC);
		}
		size_t end = _size;
		//将pos位置后的字符串从最后一个位置开始挨个向后移动
		while (end > pos) 
		{
			_str[end] = _str[end - 1];
			--end;
		}
		_str[end] = c; //插入字符
		_str[++_size] = '\0'; //更新size，插入'\0'
	}

	//插入字符串
	void Insert(size_t pos, const char* str)
	{
		assert(pos >= 0 && pos <= _size); //判断插入位置是否正确
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			Reserve(_size + len);
		}
		size_t end = _size + len;
		//移动pos位置后的字符串，插入位置pos从0开始。
		while (end > pos + len - 1)
		{
			//第一个挪动的为'\0'
			_str[end] = _str[end - len];
			--end;
		}
		//插入字符串
		for (int i = 0; i < len; i++)
		{
			_str[i + pos] = str[i];
		}
		_size += len; //更新_size
	}

	//扩容
	void Reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1]; //增容，申请新的空间
			strcpy(tmp, _str); //将原有空间内容拷贝至新的空间
			delete[] _str; //释放原有空间
			_str = tmp; //指向新空间
			_capacity = n; //更新容量
		}
	}

	//删除 pos:删除位置 len:删除长度
	void Erase(size_t pos, size_t len)
	{
		assert(pos >= 0 && pos < _size);
		//删除位置开始所删除的子串长度大于_size，意味删除pos之后所有元素
		if (pos + len > _size)
		{
			_size = pos; //更新_size
			_str[_size] = '\0'; 
		}
		//删除长度未超过_size
		else
		{
			size_t start = pos + len;
			//以pos+len位置开始向前一个一个的移动字符
			while (start < _size)
			{
				_str[pos++] = _str[start];
				++start;
			}
			_size -= len; //更新_size
			_str[_size] = '\0';
		}
	}
	// s1 += s2   -->  改变s1
	// s1.operator+=(&s1, s2)  --> Append(&s1, s2._str)
	// +=
	String& operator+=(const String& s)
	{
		Append(s._str);
		return *this;   // this --> &s1
	}

	String& operator+=(const char c)
	{
		PushBack(c);
		return *this;
	}

	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}

	//查找字符，找到返回所在位置
	size_t Find(char c)
	{
		for (int i = 0; i < _size; i++)
		{
			if (_str[i] == c)
				return i;
		}
		return npos;
	}

	//查找子串，找到返回第一次出现的位置
	size_t Find(size_t pos, const char* str)
	{

		// char*  strstr(char* dest, char* substr)
		//char* start = strstr(_str, str);
		const char* start = StrStr(_str, str);

		if (start)
			return start - _str;
		else
			return npos;
	}

	size_t Size()const
	{
		return _size;
	}


	//重载[]
	char& operator[](size_t pos)
	{
		//防止越界
		assert(pos < _size);
		return _str[pos];
	}
	//重载[]
	//只读接口，不能修改 返回const引用
	const char& operator[](size_t pos)const
	{
		//防止越界
		assert(pos < _size);
		return _str[pos];
	}
	
	
	iterator begin()
	{
		//返回第一个元素的位置(地址）
		return _str;
	}
	iterator end()
	{
		//返回第一个元素的位置(地址）
		return _str + _size;
	}

	const_iterator begin() const
	{
		//返回第一个元素的位置(地址）
		return _str;
	}

	const_iterator end() const
	{
		//返回第一个元素的位置(地址）
		return _str + _size;
	}

	friend ostream& operator<<(ostream& _cout, const String& s);

private:
	size_t _size; //有效字符长度，不含‘\0’
	char* _str; 
	size_t _capacity; //实际能存放最大字符数，不包括‘\0’,比实际申请的空间小一个字节
	static const size_t npos;

};

const size_t String::npos = -1;

const char* StrStr(const char* dest, const char* substr)
{
	while (*dest)
	{
		//判断第一个字符是否相同
		if (*substr == *dest)
		{
			const char* mdest = dest;
			const char* msubstr = substr;
			//比较每一个字符
			while (*mdest && *msubstr)
			{
				if (*mdest != *msubstr) //若遇到不相同字符直接退出循环
					break;
				mdest++;
				msubstr++;
			}
			//找到，返回dest所在位置
			if (*msubstr == '\0')
			    return dest;
			    
		}
		dest++;
	}
	return nullptr;
}

//重载<<
ostream& operator<<(ostream& _cout, const String& s)
{
	for (auto& e : s)
	{
		_cout << e;
	}
	return _cout;
}

//打印
void PrintString(const String& s)
{
	for (int i = 0; i < s.Size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
}

//迭代器打印
void PrintStringIIterator(const String& s)
{
	String::const_iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;
}

//基于范围的for循环的打印
void PrintStringFor(const String& s)
{
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}