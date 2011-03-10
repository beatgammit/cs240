#include "bst.h"

//// public wethods


//!  No-arg constructor.  Initializes an empty BST
BST::BST(){
	pRoot = NULL;
}


//!  Copy constructor.  Makes a complete copy of its argument
BST::BST(const BST & other){
	this->pRoot = NULL;
	if(other.pRoot){
		this->pRoot = new BSTNode(*other.pRoot);
		this->pRoot->left = NULL;
		this->pRoot->right = NULL;

		this->CopyChildren(this->pRoot, other.pRoot);
	}
}


//!  Destructor
BST::~BST(){
	this->Clear();
}


//!  Assignment operator.  Makes a complete copy of its argument
//!  @return Reference to oneself
BST& BST::operator =(const BST & other){
	if(pRoot){
		this->Clear();
	}

	if(other.pRoot){
		this->pRoot = new BSTNode(*other.pRoot);
		this->pRoot->left = NULL;
		this->pRoot->right = NULL;

		this->CopyChildren(this->pRoot, other.pRoot);
	}
	return *this;
}


//!  @return a pointer to the root node of the tree, or NULL if the tree is empty.
//!  @note This is useful for BST clients that need to traverse the tree.)
BSTNode* BST::GetRoot()const{
	return pRoot;
}


//!  @return true if the BST is empty, or false if the BST is not empty
bool BST::IsEmpty() const{
	return (pRoot == NULL);
}


//!  Removes all values from the BST
void BST::Clear(BSTNode* pStart){
	BSTNode* pNode = (pStart != NULL) ? pStart : this->pRoot;

	if(pNode){
		if(pNode->left){
			this->Clear(pNode->left);
		}
		if(pNode->right){
			this->Clear(pNode->right);
		}

		if(pNode == pRoot){
			this->pRoot = NULL;
		}
		delete pNode;
	}
}


//!  @return the number of values in the BST
int BST::GetSize(BSTNode* pStart, int size) const{
	int iReturn = size;

	BSTNode* pNode = (pStart != NULL) ? pStart : pRoot;
	if(pNode){
		iReturn++;
		if(pNode->left){
			iReturn += this->GetSize(pNode->left, 0);
		}
		if(pNode->right){
			iReturn += this->GetSize(pNode->right, 0);
		}
	}

	return iReturn;
}


//!  Inserts value v into the BST
//!
//!  @param v The new value being inserted
//!
//!  @return a pointer to the newly inserted node, or NULL if v was already
//!          in the tree (i.e., NULL is used to indicate a duplicate insertion)
BSTNode* BST::Insert(void* v, BSTNode* pStart, int (*comparator)(void* key, void* elem)){
	if(true){
		if(!pRoot){
			pRoot = new BSTNode(v);
			return pRoot;
		}else{
			BSTNode* pNode = (pStart != NULL) ? pStart : pRoot;
			int iCmp = comparator(v, pNode->value);
			if(iCmp < 0){
				if(pNode->left){
					return this->Insert(v, pNode->left, comparator);
				}else{
					pNode->left = new BSTNode(v);
					return pNode->left;
				}
			}else if(iCmp > 0){
				if(pNode->right){
					return this->Insert(v, pNode->right, comparator);
				}else{
					pNode->right = new BSTNode(v);
					return pNode->right;
				}
			}
		}
	}
	return NULL;
}


//!  Searches the tree for value v
//!
//!  @param v The new value being searched for
//!
//!  @return a pointer to the node containing v, or NULL if v is not in the tree
BSTNode* BST::Find(void* v, BSTNode* pStart, int (*comparator)(void* key, void* elem)) const{
	BSTNode* pNode = (pStart != NULL) ? pStart : pRoot;
	if(pNode){
		int iCmp = comparator(v, pNode->value);

		if(iCmp < 0){
			if(pNode->left){
				return this->Find(v, pNode->left, comparator);
			}else{
				return NULL;
			}
		}else if(iCmp > 0){
			if(pNode->right){
				return this->Find(v, pNode->right, comparator);
			}else{
				return NULL;
			}
		}else{
			return pNode;
		}
	}
	return NULL;
}

//// public methods

void BST::CopyChildren(BSTNode* pNode, BSTNode* pOrig){
	if(pOrig->left){
		pNode->left = new BSTNode(*pOrig->left);
		pNode->left->left = NULL;
		pNode->left->right = NULL;

		this->CopyChildren(pNode->left, pOrig->left);
	}
	if(pOrig->right){
		pNode->right = new BSTNode(*pOrig->right);
		pNode->right->left = NULL;
		pNode->right->right = NULL;

		this->CopyChildren(pNode->right, pOrig->right);
	}
}
