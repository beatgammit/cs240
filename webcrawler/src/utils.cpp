#include "utils.h"
#include "string"

std::string myToLower(std::string orig){
	int iSize = orig.size();
	for(int i = 0; i < iSize; i++){
		orig[i] = tolower(orig[i]);
	}
	return orig;
}
