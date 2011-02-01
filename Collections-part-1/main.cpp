#include <iostream>
#include "LinkedList.h"
#include "BST.h"

using namespace std;

int main()
{
    LinkedList* tList = new LinkedList();

    LLNode* tNode;

    tNode = tList->Insert("Test\n", tList->GetFirst());
    tNode = tList->Insert("Cool\n", tNode);
    tNode = tList->Insert("Awesome\n", tNode);
    tNode = tList->Insert("1\n", tNode);
    tList->Remove(tNode);
    tNode = tList->Insert("4\n", tList->GetLast());
    tNode = tList->Insert("2\n", tNode);
    tNode = tList->Insert("3\n", tNode);

    tList->Output(cout);

    delete tList;
}
