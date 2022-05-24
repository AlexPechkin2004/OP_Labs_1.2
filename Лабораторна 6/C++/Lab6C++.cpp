#include "Header.h"

int main()
{
    Branch* root = NULL;
    int size;
    double element;
    cout << "Enter the number of elements in tree: ";
    cin >> size;
    cout << "Enter tree elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> element;
        AddElement(root, element);
    }
    TreeOutput(root, 0);

    SwapMaxAndMin(root);
    cout << "Tree with swaped elements: " << endl;
    TreeOutput(root, 0);
}