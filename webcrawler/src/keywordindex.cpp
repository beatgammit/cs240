#include "keywordindex.h"

using namespace std;

int compareKeyword(void* key, void* elem){
	Occurrence* pOccurrence = (Occurrence*)key;
	Occurrence* pElem = (Occurrence*)elem;

	return pOccurrence->word.compare(pElem->word);
}

int compareWord(void* key, void* elem){

	string* pWord = (string*)key;
	Occurrence* pElem = (Occurrence*)elem;

	return pWord->compare(pElem->word);
}

KeywordIndex::KeywordIndex(){
	this->pRoot = NULL;
}

void KeywordIndex::put(string word, string url){
	BSTNode* pNode = this->Find(&word, compareWord);
	// if we already have this one, then we'll jush update the count... put will do that
	if(pNode){
		Occurrence* pOccurrence = (Occurrence*)pNode->GetValue();
		pOccurrence->put(url);
		return;
	}

	Occurrence* pOccurrence = new Occurrence(word);
	pOccurrence->put(url);
	this->Insert(pOccurrence, compareKeyword);
}

void KeywordIndex::recurse(void (*function)(Occurrence* pOccurrence, void* data), void* pData){
	recurse(pRoot, function, pData);
}

void KeywordIndex::recurse(BSTNode* pStart, void (*function)(Occurrence* pOccurrence, void* data),
							void* pData){
	if(pStart){
		function((Occurrence*)pStart->GetValue(), pData);

		if(pStart->left){
			recurse(pStart->left, function, pData);
		}
		if(pStart->right){
			recurse(pStart->right, function, pData);
		}
	}
}
