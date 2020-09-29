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
        cout << "Ошибка при выделении памяти!" << endl;
        exit(1);
    }
    return p;
}

// функция вставки узла в бинарное дерево поиска
// root - корень дерева
// val - значение
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

// эта функция использует обратный метод прохождения.
// во время посещения узла проверяется, является ли он листовым
template<class T>
void CountLeaf(TreeNode<T>* t, int& count)
{
    // Использовать обратный метод прохождения
    if (t != nullptr)
    {
        CountLeaf(t->Left(), count); // пройти левое поддерево
        CountLeaf(t->Right(), count); // пройти правое поддерево
        // Проверить, является ли данный узел листом.
        // Если да, то произвести приращение переменной count
        if (t->Left() == nullptr && t->Right() == nullptr)
            count++;
    }
}

// эта функция использует обратный метод прохождения для вычисления глубины
// левого и правого поддеревьев узла и возвращает результирующее
// значение глубины, равное 1 + max(depthLeft, depthRight).
// глубина пустого дерева равна -1
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

// промежуток между уровнями
const int indentBlock = 6;

// вставить num пробелов на текущей строке
void IndentBlanks(int num)
{
    for (int i = 0; i < num; i++)
        cout << " ";
}

// распечатать дерево горизонтально
template <class T>
void PrintTree(TreeNode<T>* t, int level)
{
    // печатать дерево с корнем t, пока t != NULL
    if (t != nullptr)
    {
        // печатать правое поддерево узла t
        PrintTree(t->Right(), level + 1);
        // выровнять текущий уровень и вывести поле данных
        IndentBlanks(indentBlock * level);
        cout << t->data << endl;
        // печатать левое поддерево
        PrintTree(t->Left(), level + 1);
    }
}

// печать дерева вертикально
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

// создать дубликат дерева t и возвратить корень нового дерева
template <class T>
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

// использовать обратный алгоритм для прохождения узлов дерева
//и удалить каждый узел при его посещении
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