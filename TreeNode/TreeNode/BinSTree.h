#pragma once
#include "TreeNode.h"
#include <iostream>

template<class T>
class BinSTree
{
private:
	TreeNode<T>* root; // ��������� �� ������ ������
	TreeNode<T>* current; // ��������� �� ������� ���� ������
	int size; // ����� ��������� ������

	// ������� ����� ���� �� ��������� item
	TreeNode<T>* GetTreeNode(T item, TreeNode<T>* lptr, TreeNode<T>* rptr) {
		TreeNode<T>* p;
		p = new TreeNode<T>(item, lptr, rptr);
		if (p == nullptr)
		{
			std::cout << "������ ��� ��������� ������!" << std::endl;
			std::exit(1);
		}
		return p;
	}
	// �������� ������, ������� �����
	void FreeTreeNode(TreeNode<T>* p) {
		delete p;
	}
	// �������� ��� ���� � ������
	void DeleteTree(TreeNode<T>* t) {
		if (t != nullptr)
		{
			DeleteTree(t->Left());
			DeleteTree(t->Right());
			FreeTreeNode(t);
		}
	}

	// ������ ������� ������ �� ������, ���� ������, ���������� �����
	// ���������� ���� � ��������� �� ��� ��������, ����� ���������� NULL
	TreeNode<T>* FindNode(const T& item, TreeNode<T>*& parent) const {
		// ��������� �� ����� ������, ������� � �����
		TreeNode<T>* t = root;
		// � ����� ��� ��������
		parent = nullptr;
		// ���������� �� ������ ������
		while (t != nullptr)
		{
			// ������������ �� ����������
			if (item == t->data)
				break;
			else
			{
				// �������� ������������ ��������� � ���� ������� ��� ������
				parent = t;
				if (item < t->data)
					t = t->left;
				else
					t = t->right;
			}
		}
		// ���������� ��������� �� ����; NULL, ���� �� ������
		return t;
	}

	// ������� �������� ������ t � ���������� ������ ������ ������
	TreeNode<T>* CopyTree(TreeNode<T>* t)
	{
		// newnode - ����� ����
		// ��������� newlptr � newrptr �������� ������� newnode
		TreeNode<T>* newlptr, * newrptr, * newnode;
		// ���������� ����������� ����������� ��� ���������� ������� ������
		if (t == nullptr)
			return nullptr;
		// CopyTree ������ ����� ������ � �������� ����������� ����� ������ t. � ������
		// ���� ����� ������ ������� CopyTree ��������� ������� ������ ����, ���� ��
		// ����, ��������� ��� �����, � ��������� ������ ������������ NULL. CopyTree
		// ������� ����� ���� � ������� GetTreeNode � ����������� � ���� ����� �������.
		if (t->Left() != nullptr)
			newlptr = CopyTree(t->Left());
		else
			newlptr = nullptr;
		if (t->Right() != nullptr)
			newrptr = CopyTree(t->Right());
		else
			newrptr = nullptr;
		// ��������� ����� ������ ����� �����, ������� ��������
		// ���� �������, � ����� �� ��������
		newnode = GetTreeNode(t->data, newlptr, newrptr);
		// ������� ��������� �� ����� ��������� ������
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

	// ������� ������ ������
	TreeNode<T>* GetRoot() const {
		return root;
	}

	// ������� ������� ���� ������
	TreeNode<T>* GetCurrent() const {
		return current;
	}

	// ������� ������ ������
	int GetSize() const {
		return size;
	}

	// �������� ������
	void ClearList() {
		DeleteTree(root);
		size = 0;
	}

	// �������� ������������
	BinSTree<T>& operator =(const BinSTree<T>& rhs)
	{
		// ������ ���������� ������ � ���� ����
		if (this == &rhs)
			return *this;

		ClearList(); // �������� ������� ������
		// ����������� ����� ������ � ������� ������
		root = CopyTree(rhs.root);
		// ��������� �������� ��������� �������� �����
		current = root;
		// ������ ������ ������
		size = rhs.size;
		// ���������� ������ �� ������� ������
		return *this;
	}

	// ������� ������� ���� � �������� ������ ������ �� ��������� item
	void Insert(T item) {
		// t � ������� ����, parent � ���������� ����
		TreeNode<T>* t = root, * parent = nullptr, * newNode = GetTreeNode(item, nullptr, nullptr);
		// ��������� �� ������ ������
		while (t != nullptr)
		{
			// �������� ��������� parent � ���� ������� ��� ������
			parent = t;
			if (item < t->data)
				t = t->left;
			else
				t = t->right;
		}

		if (root == nullptr) {
			root = newNode;
		}

		// ���� item ������ ������������� ����, �������� � �������� ������ ����
		else if (item < parent->data)
			parent->left = newNode;
		else
			// ���� item ������ ��� ����� ������������� ����,
			// �������� � �������� ������� ����
			parent->right = newNode;
		// ��������� ��������� current ����� ������ ���� � ��������� size �� �������
		current = newNode;
		size++;
	}

	// ������ item, ���� ������, ��������� ������ ���� ��������� item
	bool Find(T item)
	{
		//�� ���������� FindNode, ������� ��������� �������� parent
		TreeNode<T>* parent;
		// ������ item, ��������� ��������� ���� �������
		current = FindNode(item, parent);
		// ���� ������, ��������� ������ ���� � ���������� True
		if (current != nullptr)
		{
			item = current->data;
			return 1;
		}
		else
			// item �� ������, ���������� False
			return 0;
	}

	// ���� ������� ��������� �� ������, ������� ���
	void Delete(const T& item)
	{
		// DNodePtr � ��������� �� ��������� ���� D
		// PNodePtr � ��������� �� ������������ ���� � ���� D
		// RNodePtr � ��������� ���� R, ���������� ���� D
		TreeNode<T>* DNodePtr, * PNodePtr, * RNodePtr;

		// ����� ����, ������ � ������� ��������� � item.
		// �������� ��� ����� � ����� ��� ��������
		if ((DNodePtr = FindNode(item, PNodePtr)) == nullptr)
			return;

		// ���� ���� D ����� NULL-���������, �� ����������
		// ����� �������� ���, ��� ��������� �� ������ �����
		if (DNodePtr->right == nullptr)
			RNodePtr = DNodePtr->left;
		else if (DNodePtr->left == nullptr)
			RNodePtr = DNodePtr->right;

		// ���� D ����� ���� �������
		else
		{
			// ����� � ����������� ���������� ���� R ��� ���� D.
			//� ����� ��������� ���� D ����� ������������ ����
			// �� ���� �����, ������� ��� ���� D.
			// ����������� ���� ���� �� ������.
			// PofRNodePtr � ��������� �� �������� ����������� ����
			TreeNode<T>* PofRNodePtr = DNodePtr;
			// ������ ��������� ������� �������� ����� ��� ���� D
			RNodePtr = DNodePtr->left;
			// ���������� ���� �� ������� ��������� ������ ���� ���� D,
			// �������� ������ �������� ���� � ��� ��������.
			// �������������, �� ����� ����� ���������� ����
			while (RNodePtr->right != nullptr)
			{
				PofRNodePtr = RNodePtr;
				RNodePtr = RNodePtr->right;
			}

			if (PofRNodePtr == DNodePtr)
				// ����� ��� ���������� ���� �������� ����������
				// ������������ ������ ��������� ���� D � ���� R
				RNodePtr->right = DNodePtr->right;
			else
			{
				// �� ���������� ���� �� ������ ����� ��� ������� �� ���� ����.
				// ������� ���������� ���� �� ������,
				// ����������� ��� ������ ����� � ������������� ����
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
		// ������������ ���� R � ���� � � ���������� �������
		else if (DNodePtr->data < PNodePtr->data)
			PNodePtr->left = RNodePtr;
		else
			PNodePtr->right = RNodePtr;
		// ���� � ���������� ���� DNodePtr ��������� �� ������ � ������� ��������
		// �� ����� ����������� ����, �� ��������� �� ��������� ���� RNodePtr
		if ((DNodePtr->left != RNodePtr) && (DNodePtr->right != RNodePtr)) {
			RNodePtr->left = DNodePtr->left;
			RNodePtr->right = DNodePtr->right;
		}
		// ������� ���� �� ������ � ��������� ������ ������
		FreeTreeNode(DNodePtr);
		size--;
	}

};

