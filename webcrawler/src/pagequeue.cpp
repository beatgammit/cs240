#include "pagequeue.h"

string PageQueue::pop(){
	if(!this->IsEmpty()){
		string tURL = this->GetFirst()->GetValue();
		this->Remove(this->GetFirst());
		return tURL;
	}
	return "";
}

void PageQueue::push(string tURL){
	this->Insert(tURL, this->GetLast());
}
