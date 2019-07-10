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

	// ƽ������
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
			if (cur->_data > val)  // ��ǰֵ����val�������
			{
				cur = cur->_pLeft;
			}
			else if(cur->_pRight < val) // ��ǰֵС��val���ұ���
			{
				cur = cur->_pRight;
			}
			else
			{
				return false;     // ��ǰֵ���ڣ�����ʧ��
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
		
		// ����������ƽ��
		while (parent)
		{
			// ����ƽ������
			if (parent->_data > val)
			{
				--parent->_bf; // ����߲���val��ƽ������ -1
			}
			else
			{
				++parent->_bf; // �ұ߲���val��ƽ������ +1
			}
			// �������֮��ƽ�����ӵ���0����ֹͣ����
			if (parent->_bf == 0)
			{
				break;
			}
			// �����ǰƽ�����ӵ���1,���ߵ���-1���������ϵ��������´�·�������Ƚڵ��ƽ�����ӣ�
			if (parent->_bf == 1 || parent->_bf = -1)
			{
				parent = parent->_pParent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// ��ƽ�⣬��Ҫ����
				//����
				if (parent->_bf == 2 && parent->_pRight->_bf == 1)
				{
					RotateL(parent);
				}
				else if 
				// ��ת�������Ѿ�ƽ�⣬��������
				break;
			}
		}
	}

	void RotateL(pNode parent)
	{
		pNode subR = parent->_pRight;
		pNode subRL = subR->_pLeft;
		
		// ��ת
		subR->_pLeft = parent;
		parent->_pParent = subRL;

		// ����������
		// ����subR��parent
		if (subRL)
		{
			subRL->_pParent = parent;
		}
		// ����subR��parent->_pParent
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
			// parent�Ǹ���subR����µĸ�
			subR->_pParent = nullptr;
			_root = subR;
		}
		// ����subR��parent
		parent->_pParent = subR;
		subR->_bf = parent->_bf = 0;
	}

	



private:
	pNode _root = nullptr;
};