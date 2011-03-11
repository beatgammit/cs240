#include "pagequeue.h"

int queueCheck(void* key, void* item){
	string* sKey = (string*)key;
	string* sValue = (string*)item;

	return sKey->compare(*sValue);
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
