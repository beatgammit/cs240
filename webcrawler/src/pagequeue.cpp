#include "pagequeue.h"

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
