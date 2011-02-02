#include <iostream>
#include "LinkedList.h"
#include "BST.h"

using namespace std;

int main(){
    LinkedList* tList = new LinkedList();

    LLNode* tNode;

    tNode = tList->Insert("Test\n", NULL);
    tNode = tList->Insert("Cool\n", NULL);
    tList->Clear();
    tNode = tList->Insert("Awesome\n", NULL);
    tNode = tList->Insert("1\n", tNode);
    //tList->Remove(tNode);
    tNode = tList->Insert("4\n", tList->GetLast());
    tNode = tList->Insert("2\n", tNode);
    tNode = tList->Insert("3\n", tNode);

    //tList->Remove(tList->GetFirst());

	cout << "LinkedList contents:" << tList->GetSize() << endl;
    tList->Output(cout);

    tList->Clear();

    BST* tBST = new BST();
    BSTNode* tBSTNode;

    tBSTNode = tBST->Insert("Cool\n");
    tBSTNode = tBST->Insert("Awesome\n");
    tBSTNode = tBST->Insert("Test\n");
    tBSTNode = tBST->Insert("1\n");
    //tBST->Remove(tBSTNode);
    tBSTNode = tBST->Insert("4\n");
    tBSTNode = tBST->Insert("2\n");
    tBSTNode = tBST->Insert("3\n");

    cout << endl << endl << "BST contents:" << tBST->GetSize() << endl;
    tBST->Output(cout, tBST->GetRoot());

    BST* tNew = new BST(*tBST);

    cout << endl << endl << "BST Copy contents:" << tNew->GetSize() << endl;
	tNew->Output(cout, tNew->GetRoot());

    delete tList;
    delete tBST;
    delete tNew;
}
