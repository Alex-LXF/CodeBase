// 二叉搜索树
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

	T _data; // 数据
	BSTNode<T>* _pLeft; // 左子树
	BSTNode<T>* _pRight; // 右子树
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

	// 查找
	pNode find(const T& val)
	{
		// 1. 判断是否为空
		if (root == nullptr)
			return nullptr;
		// 2. 若不为空
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

	// 插入
	//  (1) 若根为空，直接插入。 [_root = nullptr; _root = new Node(val); ]	
	// （2）从根节点走，找到最后一个叶子节点。
    //		a. 如果当前节点的值大于插入值，向左边找；[cur->_data > val; cur = cur->pLeft; ]
	//      b. 如果当前节点的值小于插入值，向右边找。[cur->_data < val; cur = cur->pRight; ]
	//      c. 如果插入的值存在，则不需要插入，即插入失败，返回false。 [cur->_data = val; return false;]
	//      d. 循环以上过程。
	//  (3) 在找到叶子节点后插入待插入的值。
	//      a. 在插入位置找到时，cur = nullptr，所以需要辅助节点parent，parent为cur的父亲节点。
	//      b. 父亲节点的值大于插入的值，插入左边；
	//      c. 父亲节点的值小于插入的值，插入右边。
	//  (4) 插入成功，返回true。		
			

	bool insert(const T& val)
	{
		pNode cur = _root;
		pNode parent = nullptr; // 当前节点的父节点
		while (cur)
		{
			parent = cur; // 更新节点
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
		// 查找
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
		// 删除
		// 1. 删除叶子节点
		if (cur->_pLeft == nullptr && cur->_pRight == nullptr)
		{
			// 是否删除_root
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
				// 删除_root, 树为空
				_root = nullptr; // 不置空，相当于野指针
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
			// cur左右孩子都存在
			// 1. 寻找替换节点
			pNode pNext = cur->_pLeft;
			parent = cur;
			while (pNext->_pRight)
			{
				parent = pNext;
				pNext = pNext->_pRight;
			}

			// 2.置换
			cur->_data = pNext->_data;
			if (parent->_pRight = pNext)
			{
				parent->_pRight = nullptr;
			}
			else
			{
				parent->_pLeft = nullptr;
			}
			// 3. 删除置换结点。
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


