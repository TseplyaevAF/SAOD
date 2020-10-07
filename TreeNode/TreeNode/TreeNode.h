#pragma once
template <class T>
class BinSTree;

template <class T>
class TreeNode
{
	// ��������� �� ������ � ������� �������
	TreeNode<T>* left;
	TreeNode<T>* right;

public:
	// ����������
	enum ERRORS {
		right_null = -1, // ������� ���� ���
		left_null = -2, // ������ ���� ���
	};

	T data; // ������, ������������ � ����

	TreeNode() {
		left = nullptr;
		right = nullptr;
		data = 0;
	}
	~TreeNode() {
		
	}

	// �����������
	TreeNode(const T& item, TreeNode<T>* lptr = nullptr,
		TreeNode<T>* rptr = nullptr):data(item), left(lptr), right(rptr) 
	{}

	// ������ ������� � ���������� ����
	TreeNode<T>* Left(void) const {
		if (left != nullptr)
			return left;
		else return nullptr;
		//return left;
	}
	TreeNode<T>* Right(void) const {
		if (right != nullptr)
			return right;
		else return nullptr;
		//return right;
	}

	void SetLeft(TreeNode<T>* left) {
		this->left = left;
	}

	void SetRight(TreeNode<T>* right) {
		this->right = right;
	}

	// ������� ����� BinSTree �������������, ��������� ���������
	// ������ � ����� left � right
	friend class BinSTree<T>;

	// ������������ ������
	void FreeNode(TreeNode<T>* p) {
		delete p;
	}

};