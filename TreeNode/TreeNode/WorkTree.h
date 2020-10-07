#pragma once
#include <iostream>
#include "TreeNode.h"
#include "Stack.h"
#include <random>
#include <fstream>

using namespace std;

//// функция вставки узла в бинарное дерево поиска
//// root - корень дерева
//// val - значение
//template <class T>
//TreeNode <T>* InsertNode(TreeNode <T>* root, T val) {
//    if (root == nullptr) {
//        root = new TreeNode<T>(val);
//        if (root != nullptr)
//            root->data = val;
//        return root;
//    }
//    if (val < root->data)
//        root->SetLeft(InsertNode(root->Left(), val));
//    else
//        root->SetRight(InsertNode(root->Right(), val));
//    return root;
//}

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
void PrintVTree(TreeNode<T>* root, ofstream & fout) {
    Stack<TreeNode<T> *> globalStack;
    globalStack.Push(root);
    int emptyLeaf = 32;
    bool isRowEmpty = false;

    while (!isRowEmpty) {
        Stack<TreeNode<T>*> localStack;
        isRowEmpty = true;
        for (unsigned i = 0; i < emptyLeaf; i++)
        {
            fout << " ";
        }
        while (!globalStack.isEmpty()) 
        {
            TreeNode<T> *temp = globalStack.Pop();
            if (temp != nullptr) 
            {
                fout << temp->data;
                localStack.Push(temp->Left());
                localStack.Push(temp->Right());
                if (temp->Left() != nullptr || temp->Right() != nullptr)
                    isRowEmpty = false;
            }
            else
            {
                fout << "  ";
                localStack.Push(nullptr);
                localStack.Push(nullptr);
            }
            for (unsigned i = 0; i < emptyLeaf*2-2; i++)
                fout << " ";
        }
        fout << "\n\n\n";
        emptyLeaf /= 2;
        while (!localStack.isEmpty()) {
            globalStack.Push(localStack.Pop());
        }
    }
}