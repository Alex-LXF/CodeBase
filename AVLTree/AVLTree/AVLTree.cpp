#define _CRT_SECURE_NO_WARNINGS 1
template<class T>
struct AVLNode
{
	AVLNode(const T& val = T())
	: _data(val)
	, _pLeft(nullptr)
	, _pRight(nullptr)
	, _pParent(nullptr)
	, _bf(0)
	{}

	T _data;
	AVLNode<T>* _pLeft;
	AVLNode<T>* _pRight;
	AVLNode<T>* _pParent;

	// 平衡因子
	int _bf;
};


template<class T>
class AVLTree
{
	typedef AVLNode<T> Node;
	typedef Node* pNode;

	bool insert(const T& val)
	{
		if (_root = nullptr)
		{
			_root = new Node(val);
			return true;
		}
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_data > val)  // 当前值大于val，左边走
			{
				cur = cur->_pLeft;
			}
			else if(cur->_pRight < val) // 当前值小于val，右边走
			{
				cur = cur->_pRight;
			}
			else
			{
				return false;     // 当前值存在，返回失败
			}
		}

		pNode newNode = new Node(val);
		if (parent->_data > val)
		{
			parent->_pLeft = newNode;
		}
		else if (parent->_data < val)
		{
			parent->_pRight = newNode;
		}
		newNode->_pParent = parent;
		
		// 调整，保持平衡
		while (parent)
		{
			// 更新平衡因子
			if (parent->_data > val)
			{
				--parent->_bf; // 在左边插入val，平衡因子 -1
			}
			else
			{
				++parent->_bf; // 右边插入val，平衡因子 +1
			}
			// 如果插入之后平衡因子等于0，则停止更新
			if (parent->_bf == 0)
			{
				break;
			}
			// 如果当前平衡因子等于1,或者等于-1，继续向上调整，更新此路径上祖先节点的平衡因子；
			if (parent->_bf == 1 || parent->_bf = -1)
			{
				parent = parent->_pParent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 不平衡，需要调整
				//左旋
				if (parent->_bf == 2 && parent->_pRight->_bf == 1)
				{
					RotateL(parent);
				}
				else if 
				// 旋转结束，已经平衡，结束调整
				break;
			}
		}
	}

	void RotateL(pNode parent)
	{
		pNode subR = parent->_pRight;
		pNode subRL = subR->_pLeft;
		
		// 旋转
		subR->_pLeft = parent;
		parent->_pParent = subRL;

		// 更新三叉链
		// 链接subR和parent
		if (subRL)
		{
			subRL->_pParent = parent;
		}
		// 链接subR和parent->_pParent
		if (parent != _root)
		{
			pNode gParent = parent->_pParent;
			if (gParent->_pLeft = parent)
			{
				gParent->_pLeft = subR;
			}
			else
			{
				gParent->_pRight = subR;
			}
			subR = gParent;
		}
		else
		{
			// parent是根，subR变成新的根
			subR->_pParent = nullptr;
			_root = subR;
		}
		// 链接subR和parent
		parent->_pParent = subR;
		subR->_bf = parent->_bf = 0;
	}

	



private:
	pNode _root = nullptr;
};