#include "pagesparsed.h"
#include "string"

using namespace std;

int pageListComparator(void* first, void* second){
	string* pFirst = (string*)first;
	Page* pSecond = (Page*)second;

	return pFirst->compare(pSecond->pURL);
}

bool PagesParsed::pageProcessed(std::string tURL){
	return Find(&tURL, NULL, pageListComparator) != NULL;
}

void PagesParsed::add(Page* pPage){
	this->Insert(pPage, NULL);
}
