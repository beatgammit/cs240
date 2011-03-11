#include "occurrence.h"

using namespace std;

int compareUrlToOccurrence(void* key, void* elem){
	string tKey = *(string*)(key);
	Instance* pElem = (Instance*)elem;

	return tKey.compare(pElem->url);
}

int compareOccurrence(void* key, void* elem){
	Instance* pKey = (Instance*)key;
	Instance* pElem = (Instance*)elem;

	return pKey->url.compare(pElem->url);
}

void Occurrence::put(string url){
	BSTNode* pNode = this->Find(&url, compareUrlToOccurrence);
	if(pNode){
		Instance* pInstance = (Instance*)pNode->GetValue();
		pInstance->count += 1;
	}else{
		Instance* pInstance = new Instance;
		pInstance->url = url;
		pInstance->count = 1;

		this->Insert(pInstance, compareOccurrence);
	}
}

void Occurrence::recurse(void (*function)(Instance* data, void* pData), void* pData){
	if(pRoot){
		recurse(this->pRoot, function, pData);
	}
}

void Occurrence::recurse(BSTNode* pNode, void (*function)(Instance* data, void* pData),
						void* pData){
	if(pNode){
		function((Instance*)pNode->GetValue(), pData);
		if(pNode->left){
			this->recurse(pNode->GetLeft(), function, pData);
		}
		if(pNode->right){
			this->recurse(pNode->GetRight(), function, pData);
		}
	}
}

//!  Removes all values from the BST
void Occurrence::Clear(BSTNode* pStart){
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

		if(pNode->value){
			Instance* pInstance = (Instance*)pNode->value;
			delete pInstance;
		}
		delete pNode;
	}
}


Occurrence::~Occurrence(){
	this->Clear(this->pRoot);
}
