// ����������
#include <iostream>
#include <cstdlib>
using namespace std;
template <class T>
struct BSTNode
{
	BSTNode(const T& val = T())
	: _data(val)
	, _pLeft(nullptr)
	, _pRight(nullptr)
	{}

	T _data; // ����
	BSTNode<T>* _pLeft; // ������
	BSTNode<T>* _pRight; // ������
};

template <class T>
class BSTree
{
public:
	typedef BSTNode<T> Node;
	typedef Node* pNode;

	BSTree(const pNode root = nullptr)
		:_root(root)
	{}

	// ����
	pNode find(const T& val)
	{
		// 1. �ж��Ƿ�Ϊ��
		if (root == nullptr)
			return nullptr;
		// 2. ����Ϊ��
		pNode cur = _root;
		while (cur)
		{
			if (cur->_data == val)
				return cur;
			else if (cur->data > val)
			{
				cur = cur->_pLeft;
			}
			else
			{
				cur = cur->_pRight;
			}
		}
		return nullptr;
	}

	// ����
	//  (1) ����Ϊ�գ�ֱ�Ӳ��롣 [_root = nullptr; _root = new Node(val); ]	
	// ��2���Ӹ��ڵ��ߣ��ҵ����һ��Ҷ�ӽڵ㡣
    //		a. �����ǰ�ڵ��ֵ���ڲ���ֵ��������ң�[cur->_data > val; cur = cur->pLeft; ]
	//      b. �����ǰ�ڵ��ֵС�ڲ���ֵ�����ұ��ҡ�[cur->_data < val; cur = cur->pRight; ]
	//      c. ��������ֵ���ڣ�����Ҫ���룬������ʧ�ܣ�����false�� [cur->_data = val; return false;]
	//      d. ѭ�����Ϲ��̡�
	//  (3) ���ҵ�Ҷ�ӽڵ�����������ֵ��
	//      a. �ڲ���λ���ҵ�ʱ��cur = nullptr��������Ҫ�����ڵ�parent��parentΪcur�ĸ��׽ڵ㡣
	//      b. ���׽ڵ��ֵ���ڲ����ֵ��������ߣ�
	//      c. ���׽ڵ��ֵС�ڲ����ֵ�������ұߡ�
	//  (4) ����ɹ�������true��		
			

	bool insert(const T& val)
	{
		pNode cur = _root;
		pNode parent = nullptr; // ��ǰ�ڵ�ĸ��ڵ�
		while (cur)
		{
			parent = cur; // ���½ڵ�
			if (cur->_data > val)
			{
				cur = cur->_pLeft;
			}
			else if (cur->_data < val)
			{
				cur = cur->_pRight;
			}
			else
			{
				return false;
			}
		}
		pNode newNode = new Node(val);
		if (parent->_data > val)
		{
			parent->_pLeft = newNode;
		}
		else
		{
			parent->_pRight = newNode;
		}
		return true;
	}

	bool erase(const T& val)
	{
		if (_root == nullptr)
		{
			return false;
		}
		pNode cur = _root;
		pNode parent = nullptr;
		// ����
		while (cur)
		{
			if (cur->_data == val)
			{
				break;
			}
			else if (cur->_data > val)
			{
				parent = cur;
				cur = cur->_pLeft;
			}
			else 
			{
				parent = cur;
				cur = cur->_pRight;
			}
		}
		// ɾ��
		// 1. ɾ��Ҷ�ӽڵ�
		if (cur->_pLeft == nullptr && cur->_pRight == nullptr)
		{
			// �Ƿ�ɾ��_root
			if (cur != _root)
			{
				if (parent->_pLeft == cur)
				{
					parent->_pLeft = nullptr;
				}
				else
				{
					parent->_pRight = nullptr;
				}
			}
			else
			{
				// ɾ��_root, ��Ϊ��
				_root = nullptr; // ���ÿգ��൱��Ұָ��
			}
			delete cur;
			cur = nullptr;
		}
		else if (cur->_pLeft == nullptr)
		{
			if (cur != _root)
			{
				if(parent->_pLeft == cur)
				{
					parent->_pLeft = cur->_pRight;
				}
				else
				{
					parent->_pRight = cur->_pRight;
				}
			}
			else
			{
				_root = _root->_pRight;
			}
			delete cur;
			cur = nullptr;
		}
		else if (cur->_pRight == nullptr)
		{
			if (cur != _root)
			{
				if (parent->_pLeft == cur)
				{
					parent->_pLeft = cur->_pLeft;
				}
				else
				{
					parent->_pRight = cur->_pLeft;
				}
			}
			else
			{
				_root = _root->_pLeft;
			}
			delete cur;
			cur = nullptr;
		}
		else
		{
			// cur���Һ��Ӷ�����
			// 1. Ѱ���滻�ڵ�
			pNode pNext = cur->_pLeft;
			parent = cur;
			while (pNext->_pRight)
			{
				parent = pNext;
				pNext = pNext->_pRight;
			}

			// 2.�û�
			cur->_data = pNext->_data;
			if (parent->_pRight = pNext)
			{
				parent->_pRight = nullptr;
			}
			else
			{
				parent->_pLeft = nullptr;
			}
			// 3. ɾ���û���㡣
			delete pNext;
			pNext = nullptr;
		}
		return true;
	}

	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}

	void _Inorder(pNode root)
	{
		if (root)
		{
			_Inorder(root->_pLeft);
			cout << root->_data << " ";
			_Inorder(root->_pRight);
		}
	}
	~BSTree()
	{
		Distory(_root);
	}
	
	void Distory(pNode root)
	{
		if (root)
		{
			Distory(root->_pLeft);
			Distory(root->_pRight);
			delete root;
			root = nullptr;
		}
	}

private:
	pNode _root;
};

//int main()
//{
//	BSTree<int> bt;
//	bt.insert(9);
//	bt.Inorder();
//	bt.insert(1);
//	bt.Inorder();
//	bt.insert(5);
//	bt.Inorder();
//	bt.insert(10);
//	bt.Inorder();
//	bt.insert(12);
//	bt.Inorder();
//	bt.insert(8);
//	bt.Inorder();
//	bt.insert(3);
//	bt.Inorder();
//	bt.insert(20);
//	bt.Inorder();
//	
//	return 0;
//}


