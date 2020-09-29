#pragma once
#include <iostream>
#include "TreeNode.h"
#include "Stack.h"
#include <random>

using namespace std;

template <class T>
TreeNode<T>* GetTreeNode(T item, TreeNode<T>* lptr = nullptr,
    TreeNode<T>* rptr = nullptr)
{
    TreeNode<T>* p;
    p = new TreeNode<T>(item, lptr, rptr);
    if (p == nullptr)
    {
        cout << "������ ��� ��������� ������!" << endl;
        exit(1);
    }
    return p;
}

// ������� ������� ���� � �������� ������ ������
// root - ������ ������
// val - ��������
template <class T>
TreeNode <T>* InsertNode(TreeNode <T>* root, T val) {
    if (root == nullptr) {
        root = new TreeNode<T>(val);
        if (root != nullptr)
            root->data = val;
        return root;
    }
    if (val < root->data)
        root->SetLeft(InsertNode(root->Left(), val));
    else
        root->SetRight(InsertNode(root->Right(), val));
    return root;
}

// ��� ������� ���������� �������� ����� �����������.
// �� ����� ��������� ���� �����������, �������� �� �� ��������
template<class T>
void CountLeaf(TreeNode<T>* t, int& count)
{
    // ������������ �������� ����� �����������
    if (t != nullptr)
    {
        CountLeaf(t->Left(), count); // ������ ����� ���������
        CountLeaf(t->Right(), count); // ������ ������ ���������
        // ���������, �������� �� ������ ���� ������.
        // ���� ��, �� ���������� ���������� ���������� count
        if (t->Left() == nullptr && t->Right() == nullptr)
            count++;
    }
}

// ��� ������� ���������� �������� ����� ����������� ��� ���������� �������
// ������ � ������� ����������� ���� � ���������� ��������������
// �������� �������, ������ 1 + max(depthLeft, depthRight).
// ������� ������� ������ ����� -1
template <class T>
int Depth(TreeNode<T>* t)
{
    int depthLeft, depthRight, depthval;
    if (t == nullptr)
        depthval = -1;
    else
    {
        depthLeft = Depth(t->Left());
        depthRight = Depth(t->Right());
        depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
    }
    return depthval;
}

// ���������� ����� ��������
const int indentBlock = 6;

// �������� num �������� �� ������� ������
void IndentBlanks(int num)
{
    for (int i = 0; i < num; i++)
        cout << " ";
}

// ����������� ������ �������������
template <class T>
void PrintTree(TreeNode<T>* t, int level)
{
    // �������� ������ � ������ t, ���� t != NULL
    if (t != nullptr)
    {
        // �������� ������ ��������� ���� t
        PrintTree(t->Right(), level + 1);
        // ��������� ������� ������� � ������� ���� ������
        IndentBlanks(indentBlock * level);
        cout << t->data << endl;
        // �������� ����� ���������
        PrintTree(t->Left(), level + 1);
    }
}

// ������ ������ �����������
template<class T>
void PrintVTree(TreeNode<T>* root) {
    Stack<TreeNode<T> *> globalStack;
    globalStack.Push(root);
    int emptyLeaf = 32;
    bool isRowEmpty = false;

    while (!isRowEmpty) {
        Stack<TreeNode<T>*> localStack;
        isRowEmpty = true;
        for (unsigned i = 0; i < emptyLeaf; i++)
        {
            cout << " ";
        }
        while (!globalStack.isEmpty()) 
        {
            TreeNode<T> *temp = globalStack.Pop();
            if (temp != nullptr) 
            {
                cout << temp->data;
                localStack.Push(temp->Left());
                localStack.Push(temp->Right());
                if (temp->Left() != nullptr || temp->Right() != nullptr)
                    isRowEmpty = false;
            }
            else
            {
                cout << "  ";
                localStack.Push(nullptr);
                localStack.Push(nullptr);
            }
            for (unsigned i = 0; i < emptyLeaf*2-2; i++)
                cout << " ";
        }
        cout << "\n\n\n";
        emptyLeaf /= 2;
        while (!localStack.isEmpty()) {
            globalStack.Push(localStack.Pop());
        }
    }
}

// ������� �������� ������ t � ���������� ������ ������ ������
template <class T>
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

// ������������ �������� �������� ��� ����������� ����� ������
//� ������� ������ ���� ��� ��� ���������
template <class T>
void DeleteTree(TreeNode<T>* t)
{
    if (t != NULL)
    {
        DeleteTree(t->Left());
        DeleteTree(t->Right());
        FreeTreeNode(t);
    }
}

template <class T>
void FreeTreeNode(TreeNode<T>* p)
{
    delete p;
}