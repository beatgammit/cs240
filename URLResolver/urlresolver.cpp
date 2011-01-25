#include "urlresolver.h"
#include "stdio.h"
#include "string.h"

URLResolver::URLResolver(){
}

void URLResolver::resolve(URL* baseURL, char* relativeURL, char** output){
	int iIndex = 0;
	URL tURL(baseURL, relativeURL[0] == '#');
	if(relativeURL[0] == '/'){
		// we're starting from the base
		tURL.killPath();
		iIndex++;
	}

	if(relativeURL[0] != '#' && relativeURL[0] != '?'){
		tURL.removeFilename();
	}
	char* token = strtok(&relativeURL[iIndex], "/");
	while(token){
		tURL.updateURL(token);
		token = strtok(NULL, "/");
	}

	tURL.toString(output);
}

URLResolver::~URLResolver(){
	if(baseURL){
		delete baseURL;
	}
}
