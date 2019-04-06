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
	//ȫȱʡ���캯�� 
	String(const char* str = "") //ȱʡֵ ""

		:_size(strlen(str))
		, _capacity(_size)
		, _str(new char[_size + 1])
	{
		strcpy(_str, str);
	}

	//�������캯��
	String(const String& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String tmp(s._str);
		Swap(tmp); //�൱��Swap(this, tmp)
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

	//��������
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

	//β��
	void PushBack(const char c)
	{
		//�ж������Ƿ��㹻����������
		if (_size = _capacity)
		{
			size_t newC = (_capacity == 0 ? 15 : 2 * _capacity);
			Reserve(newC);
		}

		_str[_size++] = c; //��_sizeλ�ò��룬֮��_size+1����
		_str[_size] = '\0'; //��'\0'����_sizeλ��
	}

	//βɾ
	void PopBack()
	{
		assert(_size > 0); //ȷ��_size���ٺ���һ��Ԫ��
		_str[--_size] = '\0'; 
	}

	//β���ַ���
	void Append(const char* str)
	{
		size_t sz = strlen(str);
		if (_size + sz > _capacity) //�������
		{
			Reserve(_size + sz); //����
		}
		strcpy(_str + _size, str); //��Ŀ���ַ���������µ��ַ��� 
		_size += sz; //����_size
	}

	//�����ַ�c
	void Insert(size_t pos, const char c)
	{
		assert(pos >= 0 && pos <= _size); //�жϲ���λ���Ƿ���ȷ
		if (_size == _capacity) //�������
		{
			//����
			size_t newC = (_capacity == 0 ? 15 : 2 * _capacity);
			Reserve(newC);
		}
		size_t end = _size;
		//��posλ�ú���ַ��������һ��λ�ÿ�ʼ��������ƶ�
		while (end > pos) 
		{
			_str[end] = _str[end - 1];
			--end;
		}
		_str[end] = c; //�����ַ�
		_str[++_size] = '\0'; //����size������'\0'
	}

	//�����ַ���
	void Insert(size_t pos, const char* str)
	{
		assert(pos >= 0 && pos <= _size); //�жϲ���λ���Ƿ���ȷ
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			Reserve(_size + len);
		}
		size_t end = _size + len;
		//�ƶ�posλ�ú���ַ���������λ��pos��0��ʼ��
		while (end > pos + len - 1)
		{
			//��һ��Ų����Ϊ'\0'
			_str[end] = _str[end - len];
			--end;
		}
		//�����ַ���
		for (int i = 0; i < len; i++)
		{
			_str[i + pos] = str[i];
		}
		_size += len; //����_size
	}

	//����
	void Reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1]; //���ݣ������µĿռ�
			strcpy(tmp, _str); //��ԭ�пռ����ݿ������µĿռ�
			delete[] _str; //�ͷ�ԭ�пռ�
			_str = tmp; //ָ���¿ռ�
			_capacity = n; //��������
		}
	}

	//ɾ�� pos:ɾ��λ�� len:ɾ������
	void Erase(size_t pos, size_t len)
	{
		assert(pos >= 0 && pos < _size);
		//ɾ��λ�ÿ�ʼ��ɾ�����Ӵ����ȴ���_size����ζɾ��pos֮������Ԫ��
		if (pos + len > _size)
		{
			_size = pos; //����_size
			_str[_size] = '\0'; 
		}
		//ɾ������δ����_size
		else
		{
			size_t start = pos + len;
			//��pos+lenλ�ÿ�ʼ��ǰһ��һ�����ƶ��ַ�
			while (start < _size)
			{
				_str[pos++] = _str[start];
				++start;
			}
			_size -= len; //����_size
			_str[_size] = '\0';
		}
	}
	// s1 += s2   -->  �ı�s1
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

	//�����ַ����ҵ���������λ��
	size_t Find(char c)
	{
		for (int i = 0; i < _size; i++)
		{
			if (_str[i] == c)
				return i;
		}
		return npos;
	}

	//�����Ӵ����ҵ����ص�һ�γ��ֵ�λ��
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


	//����[]
	char& operator[](size_t pos)
	{
		//��ֹԽ��
		assert(pos < _size);
		return _str[pos];
	}
	//����[]
	//ֻ���ӿڣ������޸� ����const����
	const char& operator[](size_t pos)const
	{
		//��ֹԽ��
		assert(pos < _size);
		return _str[pos];
	}
	
	
	iterator begin()
	{
		//���ص�һ��Ԫ�ص�λ��(��ַ��
		return _str;
	}
	iterator end()
	{
		//���ص�һ��Ԫ�ص�λ��(��ַ��
		return _str + _size;
	}

	const_iterator begin() const
	{
		//���ص�һ��Ԫ�ص�λ��(��ַ��
		return _str;
	}

	const_iterator end() const
	{
		//���ص�һ��Ԫ�ص�λ��(��ַ��
		return _str + _size;
	}

	friend ostream& operator<<(ostream& _cout, const String& s);

private:
	size_t _size; //��Ч�ַ����ȣ�������\0��
	char* _str; 
	size_t _capacity; //ʵ���ܴ������ַ�������������\0��,��ʵ������Ŀռ�Сһ���ֽ�
	static const size_t npos;

};

const size_t String::npos = -1;

const char* StrStr(const char* dest, const char* substr)
{
	while (*dest)
	{
		//�жϵ�һ���ַ��Ƿ���ͬ
		if (*substr == *dest)
		{
			const char* mdest = dest;
			const char* msubstr = substr;
			//�Ƚ�ÿһ���ַ�
			while (*mdest && *msubstr)
			{
				if (*mdest != *msubstr) //����������ͬ�ַ�ֱ���˳�ѭ��
					break;
				mdest++;
				msubstr++;
			}
			//�ҵ�������dest����λ��
			if (*msubstr == '\0')
			    return dest;
			    
		}
		dest++;
	}
	return nullptr;
}

//����<<
ostream& operator<<(ostream& _cout, const String& s)
{
	for (auto& e : s)
	{
		_cout << e;
	}
	return _cout;
}

//��ӡ
void PrintString(const String& s)
{
	for (int i = 0; i < s.Size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
}

//��������ӡ
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

//���ڷ�Χ��forѭ���Ĵ�ӡ
void PrintStringFor(const String& s)
{
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}