#include <iostream>
#include "WorkTree.h"
#include <random>

using namespace std;

int main()
{
    setlocale(0, "");
    TreeNode<int>* root;
    int value;
    root = new TreeNode<int>(8);

    for (unsigned i = 0; i < 5; i++)
    {
        //value = rand() % (100 - 1 + 1) + 1;
        cout << "Введите число: ";
        cin >> value;
        root = InsertNode(root, value);
    }

    cout << endl;
    int leafCount = 0;
    CountLeaf(root, leafCount);
    cout << "Кол-во листьев: " << leafCount << "\n";
    cout << "Глубина дерева: " << Depth(root) << "\n\n";

    cout << "Исходное дерево: " << "\n\n\n";
    PrintTree(root, 1);

    TreeNode <int>* root2 = CopyTree(root);

    cout << "Его копия: " << "\n\n";
    PrintTree(root2, 1);

    //PrintVTree(root);

    DeleteTree(root);
    //DeleteTree(root2);

    return 0;
}
