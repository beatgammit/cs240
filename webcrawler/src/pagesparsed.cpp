#include "pagesparsed.h"

using namespace std;

int pageListComparator(void* first, void* second){
	string* pFirst = (string*)first;
	Page* pSecond = (Page*)second;

	return pFirst->compare(pSecond->url);
}

bool PagesParsed::pageProcessed(std::string tURL){
	return Find(&tURL, NULL, pageListComparator) != NULL;
}

void PagesParsed::add(Page* pPage){
	this->Insert(pPage, NULL);
}

void PagesParsed::Remove(LLNode * n){
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
			Page* pPage = (Page*)n->value;
			delete pPage;
		}
		delete n;
	}
}

void PagesParsed::Clear(){
	LLNode* pToDelete;
	LLNode* pCurNode = head;
	while(pCurNode){
		pToDelete = pCurNode;
		pCurNode = pCurNode->next;

		if(pToDelete->value){
			Page* pPage = (Page*)pToDelete->value;
			delete pPage;
		}
		delete pToDelete;
	}
	head = NULL;
	tail = NULL;
}

PagesParsed::~PagesParsed(){
	this->Clear();
}
