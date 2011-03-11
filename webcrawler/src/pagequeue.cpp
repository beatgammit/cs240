#include "pagequeue.h"

int queueCheck(void* key, void* item){
	string* sKey = (string*)key;
	string* sValue = (string*)item;

	return sKey->compare(*sValue);
}

void PageQueue::Remove(LLNode * n){
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
		if(n->value){
			string* pPage = (string*)n->value;
			delete pPage;
		}

		delete n;
	}
}

string PageQueue::pop(){
	if(!this->IsEmpty()){
		string tURL = *((string*)this->GetFirst()->GetValue());
		this->Remove(this->GetFirst());
		return tURL;
	}
	return "";
}

void PageQueue::push(string tURL){
	this->Insert(new string(tURL), this->GetLast());
}

bool PageQueue::contains(string tURL){
	return this->Find(&tURL, NULL, queueCheck) != NULL;
}

PageQueue::~PageQueue(){
	LLNode* pToDelete;
	LLNode* pCurNode = head;
	while(pCurNode){
		pToDelete = pCurNode;
		pCurNode = pCurNode->next;

		if(pToDelete->value){
			string* pPage = (string*)pToDelete->value;
			delete pPage;
		}
		delete pToDelete;
	}
	head = NULL;
	tail = NULL;
}

