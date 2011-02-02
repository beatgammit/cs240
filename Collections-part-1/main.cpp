#include <iostream>
#include "LinkedList.h"
#include "BST.h"

using namespace std;

int main(){
    LinkedList* tList = new LinkedList();

	char* c = new char[3];
	c[1] = '\n';
	c[2] = '\0';

    for(int i = 0; i < 200000; i++){
    	c[0] = (char)i;
    	tList->Insert(c, NULL);
    }

	cout << "LinkedList contents:" << tList->GetSize() << endl;
    //tList->Output(cout);

    tList->Clear();
    LinkedList tNew = *tList;
    //tList->Clear();

    cout << endl << endl << "List Copy contents:" << tNew.GetSize() << endl;
	//tNew.Output(cout);

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


    delete tList;
    delete tBST;
}
