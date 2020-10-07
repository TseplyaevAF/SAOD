#pragma once
#include "TreeNode.h"
#include <iostream>

template<class T>
class BinSTree
{
private:
	TreeNode<T>* root; // указатель на корень дерева
	TreeNode<T>* current; // указатель на текущий узел дерева
	int size; // число элементов дерева

	// вернуть новый узел со значением item
	TreeNode<T>* GetTreeNode(T item, TreeNode<T>* lptr, TreeNode<T>* rptr) {
		TreeNode<T>* p;
		p = new TreeNode<T>(item, lptr, rptr);
		if (p == nullptr)
		{
			std::cout << "Ошибка при выделении памяти!" << std::endl;
			std::exit(1);
		}
		return p;
	}
	// очистить память, занятую узлом
	void FreeTreeNode(TreeNode<T>* p) {
		delete p;
	}
	// очистить все узлы в дереве
	void DeleteTree(TreeNode<T>* t) {
		if (t != nullptr)
		{
			DeleteTree(t->Left());
			DeleteTree(t->Right());
			FreeTreeNode(t);
		}
	}

	// искать элемент данных на дереве, если найден, возвратить адрес
	// совпавшего узла и указатель на его родителя, иначе возвратить NULL
	TreeNode<T>* FindNode(const T& item, TreeNode<T>*& parent) const {
		// пробежать по узлам дерева, начиная с корня
		TreeNode<T>* t = root;
		// у корня нет родителя
		parent = nullptr;
		// прерваться на пустом дереве
		while (t != nullptr)
		{
			// остановиться по совпадении
			if (item == t->data)
				break;
			else
			{
				// обновить родительский указатель и идти направо или налево
				parent = t;
				if (item < t->data)
					t = t->left;
				else
					t = t->right;
			}
		}
		// возвратить указатель на узел; NULL, если не найден
		return t;
	}

	// создать дубликат дерева t и возвратить корень нового дерева
	TreeNode<T>* CopyTree(TreeNode<T>* t)
	{
		// newnode - новый узел
		// указатели newlptr и newrptr адресуют сыновей newnode
		TreeNode<T>* newlptr, * newrptr, * newnode;
		// остановить рекурсивное прохождение при достижении пустого дерева
		if (t == nullptr)
			return nullptr;
		// CopyTree строит новое дерево в процессе прохождения узлов дерева t. в каждом
		// узле этого дерева функция CopyTree проверяет наличие левого сына, если он
		// есть, создается его копия, в противном случае возвращается NULL. CopyTree
		// создает копию узла с помощью GetTreeNode и подвешивает к нему копии сыновей.
		if (t->Left() != nullptr)
			newlptr = CopyTree(t->Left());
		else
			newlptr = nullptr;
		if (t->Right() != nullptr)
			newrptr = CopyTree(t->Right());
		else
			newrptr = nullptr;
		// построить новое дерево снизу вверх, сначала создавая
		// двух сыновей, а затем их родителя
		newnode = GetTreeNode(t->data, newlptr, newrptr);
		// вернуть указатель на вновь созданное дерево
		return newnode;
	}

public:

	BinSTree() {

	}

	BinSTree(T item) {
		root = GetTreeNode(item, nullptr, nullptr);
		size = 1;
		current = root;
	}

	~BinSTree() {
		if (size != 0)
		DeleteTree(root);
	}

	// вернуть корень дерева
	TreeNode<T>* GetRoot() const {
		return root;
	}

	// вернуть текущий узел дерева
	TreeNode<T>* GetCurrent() const {
		return current;
	}

	// вернуть размер списка
	int GetSize() const {
		return size;
	}

	// очистить список
	void ClearList() {
		DeleteTree(root);
		size = 0;
	}

	// оператор присваивания
	BinSTree<T>& operator =(const BinSTree<T>& rhs)
	{
		// нельзя копировать дерево в само себя
		if (this == &rhs)
			return *this;

		ClearList(); // очистить текущее дерево
		// скопировать новое дерево в текущий объект
		root = CopyTree(rhs.root);
		// присвоить текущему указателю значение корня
		current = root;
		// задать размер дерева
		size = rhs.size;
		// возвратить ссылку на текущий объект
		return *this;
	}

	// функция вставки узла в бинарное дерево поиска со значением item
	void Insert(T item) {
		// t — текущий узел, parent — предыдущий узел
		TreeNode<T>* t = root, * parent = nullptr, * newNode = GetTreeNode(item, nullptr, nullptr);
		// закончить на пустом дереве
		while (t != nullptr)
		{
			// обновить указатель parent и идти направо или налево
			parent = t;
			if (item < t->data)
				t = t->left;
			else
				t = t->right;
		}

		if (root == nullptr) {
			root = newNode;
		}

		// если item меньше родительского узла, вставить в качестве левого сына
		else if (item < parent->data)
			parent->left = newNode;
		else
			// если item больше или равен родительскому узлу,
			// вставить в качестве правого сына
			parent->right = newNode;
		// присвоить указателю current адрес нового узла и увеличить size на единицу
		current = newNode;
		size++;
	}

	// искать item, если найден, присвоить данные узла параметру item
	bool Find(T item)
	{
		//мы используем FindNode, который принимает параметр parent
		TreeNode<T>* parent;
		// искать item, назначить совпавший узел текущим
		current = FindNode(item, parent);
		// если найден, присвоить данные узла и возвратить True
		if (current != nullptr)
		{
			item = current->data;
			return 1;
		}
		else
			// item не найден, возвратить False
			return 0;
	}

	// если элемент находится на дереве, удалить его
	void Delete(const T& item)
	{
		// DNodePtr — указатель на удаляемый узел D
		// PNodePtr — указатель на родительский узел Р узла D
		// RNodePtr — указатель узел R, замещающий узел D
		TreeNode<T>* DNodePtr, * PNodePtr, * RNodePtr;

		// найти узел, данные в котором совпадают с item.
		// получить его адрес и адрес его родителя
		if ((DNodePtr = FindNode(item, PNodePtr)) == nullptr)
			return;

		// если узел D имеет NULL-указатель, то заменяющим
		// узлом является тот, что находится на другой ветви
		if (DNodePtr->right == nullptr)
			RNodePtr = DNodePtr->left;
		else if (DNodePtr->left == nullptr)
			RNodePtr = DNodePtr->right;

		// узел D имеет двух сыновей
		else
		{
			// найти и отсоединить заменяющий узел R для узла D.
			//в левом поддереве узла D найти максимальный узел
			// из всех узлов, меньших чем узел D.
			// отсоединить этот узел от дерева.
			// PofRNodePtr — указатель на родителя заменяющего узла
			TreeNode<T>* PofRNodePtr = DNodePtr;
			// первой возможной заменой является левый сын узла D
			RNodePtr = DNodePtr->left;
			// спуститься вниз по правому поддереву левого сына узла D,
			// сохраняя записи текущего узла и его родителя.
			// остановившись, мы будем иметь заменяющий узел
			while (RNodePtr->right != nullptr)
			{
				PofRNodePtr = RNodePtr;
				RNodePtr = RNodePtr->right;
			}

			if (PofRNodePtr == DNodePtr)
				// левый сын удаляемого узла является заменяющим
				// присоединить правое поддерево узла D к узлу R
				RNodePtr->right = DNodePtr->right;
			else
			{
				// мы спустились вниз по правой ветви как минимум на один узел.
				// удалить заменяющий узел из дерева,
				// присоединив его правую ветвь к родительскому узлу
				PofRNodePtr->right = RNodePtr->left;
			}
		}
		if (PNodePtr == nullptr) {
			root = RNodePtr;
		}
		else

		if (RNodePtr == nullptr)
			if (PNodePtr->left == DNodePtr)
			PNodePtr->left = RNodePtr;
			else PNodePtr->right = RNodePtr;
		// присоединить узел R к узлу Р с правильной стороны
		else if (DNodePtr->data < PNodePtr->data)
			PNodePtr->left = RNodePtr;
		else
			PNodePtr->right = RNodePtr;
		// если у удаляемого узла DNodePtr указатели на левого и правого потомков
		// не равны заменяемому узлу, то присвоить их заменяему узлу RNodePtr
		if ((DNodePtr->left != RNodePtr) && (DNodePtr->right != RNodePtr)) {
			RNodePtr->left = DNodePtr->left;
			RNodePtr->right = DNodePtr->right;
		}
		// удалить узел из памяти и уменьшить размер списка
		FreeTreeNode(DNodePtr);
		size--;
	}

};

