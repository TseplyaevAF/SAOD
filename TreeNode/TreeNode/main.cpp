#include <iostream>
#include "WorkTree.h" // здесь хранятся функции печати дерева
#include "BinSTree.h"
#include <random>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    setlocale(0, "");
    BinSTree<int> tree1;
    vector <int> arr = { 30, 20, 45, 5, 10, 40, 50 };
    ofstream fout;
    fout.open("Test BinSTree.txt", ios_base::out);

    for (unsigned i = 0; i < arr.size(); i++)
    {
        tree1.Insert(arr[i]);
    }

    fout << "Дерево tree1: " << endl;
    PrintVTree(tree1.GetRoot(), fout);
    fout << endl;

    fout << "Удалим элемент 5 из дерева tree1: " << endl;
    tree1.Delete(5);
    PrintVTree(tree1.GetRoot(), fout);
    fout << endl;

    fout << "Удалим элемент 45 из дерева tree1: " << endl;
    tree1.Delete(45);
    PrintVTree(tree1.GetRoot(), fout);
    fout << endl;

    fout << "Удалим элемент 50 из дерева tree1: " << endl;
    tree1.Delete(50);
    PrintVTree(tree1.GetRoot(), fout);
    fout << endl;

    BinSTree<int> tree2;
    arr = { 10, 12, 13, -5, -4, -12, -13, 89 };

    for (unsigned i = 0; i < arr.size(); i++)
    {
        tree2.Insert(arr[i]);
    }
    
    fout << "Дерево tree2: " << endl;
    PrintVTree(tree2.GetRoot(), fout);
    fout << endl;

    int el = -13;
    fout << "Найдем элемент " << el << endl;
    if (tree2.Find(el))
        fout << "Элемент найден" << "\n\n";
    else fout << "Элемент не найден";
    el = -133;
    fout << "Найдем элемент " << el << endl;
    if (tree2.Find(el))
        fout << "Элемент найден" << "\n\n";
    else fout << "Элемент не найден" << "\n\n";

    fout << "Скопируем дерево tree1 в tree2: " << endl;
    tree2 = tree1;
    PrintVTree(tree2.GetRoot(), fout);
    fout << endl;

    fout << "Удалим элемент 30 из дерева tree2: " << endl;
    tree2.Delete(30);
    PrintVTree(tree2.GetRoot(), fout);
    fout << endl;

    tree1.ClearList();
    tree2.ClearList();
    fout.close();
    return 0;
}
