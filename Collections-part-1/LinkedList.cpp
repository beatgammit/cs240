#include "LinkedList.h"

//// Public methods


//!  No-arg constructor.  Initializes an empty linked list
LinkedList::LinkedList(){
	head = NULL;
	tail = NULL;
}

//!  Copy constructor.  Makes a complete copy of its argument
LinkedList::LinkedList(const LinkedList & other){
	LLNode* pNode = other.head;

	LLNode* pCurNode = NULL;
	LLNode* pPrevNode = NULL;

	// make sure we initialize our head
	if(pNode){
		pCurNode = new LLNode(*pNode);
		this->head = pCurNode;

		pNode = pNode->next;
	}

	while(pNode){
		pPrevNode = pCurNode;

		pCurNode = new LLNode(*pNode);
		pCurNode->prev = pPrevNode;
		pPrevNode->next = pCurNode;

		pNode = pNode->next;
	}

	// pCurNode is our new tail
	this->tail = pCurNode;
}


//!  Destructor
LinkedList::~LinkedList(){
	this->Clear();
}


//! Assignment operator.  Makes a complete copy of its argument
//! @return A reference to oneself
LinkedList& LinkedList::operator =(const LinkedList & other){
	if(this->head){
		this->Clear();
	}

	LLNode* pNode = other.head;

	LLNode* pCurNode = NULL;
	LLNode* pPrevNode = NULL;

	// make sure we initialize our head
	if(pNode){
		pCurNode = new LLNode(*pNode);
		this->head = pCurNode;

		pNode = pNode->next;
	}

	while(pNode){
		pPrevNode = pCurNode;

		pCurNode = new LLNode(*pNode);
		pCurNode->prev = pPrevNode;
		pPrevNode->next = pCurNode;

		pNode = pNode->next;
	}

	// pCurNode is our new tail
	this->tail = pCurNode;

	return *this;
}


//!  @return true if the list is empty, or false if the list is not empty
bool LinkedList::IsEmpty() const{
	return (head == NULL);
}


//!  Removes all values from the list
void LinkedList::Clear(){
	LLNode* pToDelete;
	LLNode* pCurNode = head;
	while(pCurNode){
		pToDelete = pCurNode;
		pCurNode = pCurNode->next;

		//delete pToDelete;
	}
	head = NULL;
	tail = NULL;
}


//!  @return the number of values in the list
int LinkedList::GetSize() const{
	int iCount = 0;
	LLNode* pCurNode = head;
	while(pCurNode){
		iCount++;
		pCurNode = pCurNode->GetNext();
	}
	return iCount;
}


//!  @return a pointer to the first node in the list, or NULL if the list is empty
LLNode* LinkedList::GetFirst()const{
	return head;
}



//!  @returns a pointer to the last node in the list, or NULL if the list is empty
LLNode* LinkedList::GetLast()const{
	return tail;
}


//!  Inserts value v into the list after node n
//!
//!  @param v The new value being inserted
//!  @param n A node that is already in the list after which the new node should
//!      be inserted.
//!      If n is NULL, the new node should be inserted at the beginning of the list.
//!
//!  @return a pointer to the newly inserted node
LLNode* LinkedList::Insert(const std::string & v, LLNode * n){
	LLNode* pNode;
	LLNode* pPrev = NULL;
	LLNode* pNext = NULL;

	if(n){
		pPrev = n;
		if(n->next){
			pNext = n->next;
		}
		pNode = new LLNode(v, pPrev, pNext);

		if(pNext){
			pNext->prev = pNode;
		}
		n->next = pNode;
		if(n == tail){
			tail = pNode;
		}
	}else{
		pNext = head;
		pNode = new LLNode(v, pPrev, pNext);
		if(head){
			pNode->next = head;
			head->prev = pNode;
			head = pNode;
		}else{
			head = pNode;
			tail = pNode;
		}
	}
	return pNode;
}


//! Searches for the first occurrence of value v that appears in the list
//!   after node n
//!
//!  @param v The value being searched for
//!  @param n The node in the list after which the search should begin.
//!      If n is NULL, the list should be searched from the beginning.
//!
//!  @return a pointer to the node containing v, or NULL if v is not found
LLNode* LinkedList::Find(const std::string & v, LLNode * n) const{
	if(n && n->next){
		if(v.compare(n->next->value) == 0){
			return n->next;
		}else{
			return Find(v, n->next);
		}
	}else if(!n && head){
		if(v.compare(head->value) == 0){
			return head;
		}else{
			return Find(v, head);
		}
	}
	return NULL;
}


//!  Removes node n from the list
//!
//!  @param n The node being removed from the list
void LinkedList::Remove(LLNode * n){
	if(n != NULL){
		if(n->prev != NULL){
			n->prev->next = n->next;
		}
		if(n->next != NULL){
			n->next->prev = n->prev;
		}
		if(n == head){
			head = n->next;
		}
		if(n == tail){
			tail = n->prev;
		}
		//delete n;
	}
}
