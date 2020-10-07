#pragma once
template <class T>
class BinSTree;

template <class T>
class TreeNode
{
	// указатели на левого и правого сыновей
	TreeNode<T>* left;
	TreeNode<T>* right;

public:
	// Исключения
	enum ERRORS {
		right_null = -1, // правого сына нет
		left_null = -2, // левого сына нет
	};

	T data; // данные, содержащиеся в узле

	TreeNode() {
		left = nullptr;
		right = nullptr;
		data = 0;
	}
	~TreeNode() {
		
	}

	// конструктор
	TreeNode(const T& item, TreeNode<T>* lptr = nullptr,
		TreeNode<T>* rptr = nullptr):data(item), left(lptr), right(rptr) 
	{}

	// методы доступа к указателям узла
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

	// сделать класс BinSTree дружественным, поскольку необходим
	// доступ к полям left и right
	friend class BinSTree<T>;

	// освобождение памяти
	void FreeNode(TreeNode<T>* p) {
		delete p;
	}

};