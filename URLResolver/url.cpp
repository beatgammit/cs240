#include "url.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include <iostream>

using namespace std;

void URL::initialize(){
	net_loc.domain = NULL;
	net_loc.portNumber = -1;
	path = NULL;
	pathLen = 0;
	query = NULL;
	pathLen = 0;
	fragment = NULL;
	fragmentLen = 0;
}

URL::URL(char* urlRaw){
	initialize();

	int iIndex = 0;
	int length = strlen(urlRaw);

	type = readScheme(&iIndex, length, urlRaw);
	if(type == SCH_HTTP){
		readNetLoc(&iIndex, length, urlRaw);
	}else if(type == SCH_NULL){
		// if it doesn't start with one of the two options, stop parsing
		return;
	}

	readPath(&iIndex, length, urlRaw);
	readQuery(&iIndex, length, urlRaw);
	readFragment(&iIndex, length, urlRaw);
}

URL::URL(URL* clone, bool bAppendPound){
	initialize();

	type = clone->type;
	if(type == SCH_HTTP){
		int domainLen = strlen(clone->net_loc.domain);
		net_loc.domain = new char[domainLen + 1];
		strcpy(net_loc.domain, clone->net_loc.domain);
		net_loc.portNumber = clone->net_loc.portNumber;
	}
	if(clone->path){
		pathLen = strlen(clone->path) + 1;
		path = new char[pathLen + 1];
		strcpy(path, clone->path);
	}
	if(bAppendPound && clone->query){
		char tArray[strlen(clone->query) + 2];
		tArray[0] = '\0';

		strcat(tArray, "?");
		strcat(tArray, clone->query);
		updateURL(tArray);
	}
// I don't think we'll want these hanging ariound...
//	if(clone->query){
//		int queryLen = strlen(clone->query);
//		query = new char[queryLen + 1];
//		strcpy(query, clone->query);
//	}
//	if(clone->fragment){
//		int fragmentLen = strlen(clone->fragment);
//		fragment = new char[fragmentLen + 1];
//		strcpy(fragment, clone->fragment);
//	}
}

void URL::removeFilename(){
	updateURL((char*)"..");
}

void URL::updateURL(char* token){
	if(strcmp(token, ".") == 0){
		// do nothing
	}else if(strcmp(token, "..") == 0){
		// go up one directory
		if(path && path[0]){
			int pathLength = strlen(path);
			// if the last character is already a '/', kill it then run strrchr
			if(path[pathLength - 1] == '/'){
				path[pathLength - 1] = '\0';
			}
			char* lastSlash = strrchr(path, '/');
			if(lastSlash){
				path[lastSlash - path + 1] = '\0';
			}else{
				path[0] = '\0';
			}
		}
	}else{
		int tokenLength = strlen(token);
		if(!path){
			path = new char[tokenLength + 1];
		}
		// append with preceding '/'
		int pathLength = strlen(path);
		// if we can't fit it in the existing path memory, resize it
		if(pathLength + tokenLength + 2 >= pathLen){ // the 2 is a terminating null and a '/'
			char* tNewArray = new char[pathLen * 2];
			pathLen *= 2;

			strcpy(tNewArray, path);
			delete path;
			path = tNewArray;
		}

		// only prepend a '/' if we appending a directory and there isn't already a slash (ignore for queries and fragments
		if(token[0] != '#' && token[0] != '?' && pathLength > 0 && path[pathLength - 1] != '/'){
			strcat(path, "/");
		}
		strcat(path, token);
	}
}

void URL::killPath(){
	if(path){
		path[0] = '\0';
	}
}

SCHEME URL::readScheme(int* iIndex, int iLength, char* rawPath){
	SCHEME tScheme;
	// make sure that the beginning of this string is valid
	if(strcasestr(rawPath, "http://") == rawPath){
		*iIndex += 7; // length of "http://"
		tScheme = SCH_HTTP;
		return SCH_HTTP;
	}else if(strcasestr(rawPath, "file://") == rawPath){
		*iIndex += 7; // length of "file://"
		return SCH_FILE;
	}else{
		return SCH_NULL;
	}
}

// only call me for HTTP addresses
bool URL::readNetLoc(int* iIndex, int iLength, char* rawPath){
	int i = *iIndex;
	for(; i < iLength; i++){
		if(rawPath[i] == ':'){ // check for domain
			int lengthOfArray = i - *iIndex + 1;
			net_loc.domain = new char[lengthOfArray]; // length of net_loc with trailing null
			strncpy(net_loc.domain, &rawPath[*iIndex], lengthOfArray - 1);

			i++;
			// get the port number using atoi (will stop after last number)
			net_loc.portNumber = atoi(&rawPath[i]);
			// do a loop to increment the index
			for(; i < iLength; i++){
				if(rawPath[i] == '/'){
					break;
				}
			}

			*iIndex = i; // set index to the last '/'
			return true;
		}else if(rawPath[i] == '/'){ // no domain
			int lengthOfArray = i - *iIndex + 1;
			net_loc.domain = new char[lengthOfArray]; // length of net_loc with trailing null
			strncpy(net_loc.domain, &rawPath[*iIndex], lengthOfArray - 1);
			net_loc.portNumber = -1; // effectively no domain number

			*iIndex = i; // set index to the last /
			return true;
		}
	}

	// no domain and no filepath (just a vanilla address
	if(i - *iIndex){
		int lengthOfArray = iLength - *iIndex + 1;
		net_loc.domain = new char[lengthOfArray];
		memset(&net_loc.domain[0], 0, lengthOfArray);

		strcpy(net_loc.domain, &rawPath[*iIndex]);
		*iIndex = i;
		return true;
	}
	return false;
}

bool URL::readPath(int* iIndex, int iLength, char* rawPath){
	// make sure we're at the beginning of a path (there could be none...)
	if(rawPath[*iIndex] == '/'){
		(*iIndex)++;
		int iCount = 0;
		for(int i = *iIndex; i < iLength; i++, iCount++){
			if(rawPath[i] == '?' || rawPath[i] == '#'){
				break;
			}
		}

		pathLen = iCount + 1;
		path = new char[pathLen]; // length of the string plus a trailing null
		strncpy(path, &rawPath[*iIndex], iCount);
		*iIndex += iCount; // will be at the trailing # or ? if it exists
		return true;
	}
	return false;
}

bool URL::readQuery(int* iIndex, int iLength, char* rawPath){
	if(rawPath[*iIndex] == '?'){
		(*iIndex)++;
		int iCount = 0;
		for(int i = *iIndex; i < iLength && rawPath[i] != '#'; i++, iCount++);

		queryLen = iCount + 1;
		query = new char[queryLen];
		strncpy(query, &rawPath[*iIndex], iCount);
		*iIndex += iCount;
	}
	return false;
}

bool URL::readFragment(int* iIndex, int iLength, char* rawPath){
	if(rawPath[*iIndex] == '#'){
		(*iIndex)++;
		int iCount = 0;
		for(int i = *iIndex; i < iLength; i++, iCount++);

		fragmentLen = iCount + 1;
		fragment = new char[fragmentLen];
		strncpy(fragment, &rawPath[*iIndex], iCount);

		*iIndex += iCount;
		return true;
	}
	return false;
}

void URL::toString(char** tOutput){
	switch(type){
		case SCH_FILE:{
			if(path){
				bool bPath = path ? true : false;
				bool bQuery = query ? true: false;
				bool bFragment = fragment ? true : false;

				int iCount = 7; // length of "file://"
				iCount += bPath ? strlen(path) + 1 : 0; // plus 1 for the leading '/'
				iCount += bQuery ? strlen(query) + 1: 0; // plus 1 for the leading '?'
				iCount += bFragment ? strlen(fragment) + 1: 0; // plus 1 for the leading '#'

				*tOutput = new char[iCount + 1];
				if(bPath && bQuery && bFragment){
					sprintf(*tOutput, "file:///%s?%s#%s", path, query, fragment);
				}else if(bPath && bQuery){
					sprintf(*tOutput, "file:///%s?%s", path, query);
				}else if(bPath && bFragment){
					sprintf(*tOutput, "file:///%s#%s", path, fragment);
				}else{
					sprintf(*tOutput, "file:///%s", path);
				}
			}else{
				*tOutput = new char[15];
				(*tOutput)[0] = '\0';
				strcpy(*tOutput, "No path set...");
			}
			break;
		}
		case SCH_HTTP:{
			if(net_loc.domain){
				bool bPort = net_loc.portNumber > 0 ? true : false;
				bool bPath = path ? true : false;
				bool bQuery = query ? true: false;
				bool bFragment = fragment ? true : false;

				int iCount = 7;
				iCount += strlen(net_loc.domain);
				iCount += bPort ? log10(net_loc.portNumber) + 2 : 0; // plus 1 for the log and plus 1 for the leading colon
				iCount += bPath ? strlen(path) + 1 : 0; // plus 1 for the leading '/'
				iCount += bQuery ? strlen(query) + 1: 0; // plus 1 for the leading '?'
				iCount += bFragment ? strlen(fragment) + 1: 0; // plus 1 for the leading '#'

				*tOutput = new char[iCount + 1]; // the 1 is the trailing null
				(*tOutput)[0] = '\0';
				if(bPort){
					if(bPath && bQuery && bFragment){
						sprintf(*tOutput, "http://%s:%d/%s?%s#%s", net_loc.domain, net_loc.portNumber, path, query, fragment);
					}else if(bPath && bQuery){
						sprintf(*tOutput, "http://%s:%d/%s?%s", net_loc.domain, net_loc.portNumber, path, query);
					}else if(bPath && bFragment){
						sprintf(*tOutput, "http://%s:%d/%s#%s", net_loc.domain, net_loc.portNumber, path, fragment);
					}else if(bPath){
						sprintf(*tOutput, "http://%s:%d/%s", net_loc.domain, net_loc.portNumber, path);
					}else{
						sprintf(*tOutput, "http://%s:%d", net_loc.domain, net_loc.portNumber);
					}
				}else{
					if(bPath && bQuery && bFragment){
						sprintf(*tOutput, "http://%s/%s?%s#%s", net_loc.domain, path, query, fragment);
					}else if(bPath && bQuery){
						sprintf(*tOutput, "http://%s/%s?%s", net_loc.domain, path, query);
					}else if(bPath && bFragment){
						sprintf(*tOutput, "http://%s/%s#%s", net_loc.domain, path, fragment);
					}else if(bPath){
						sprintf(*tOutput, "http://%s/%s", net_loc.domain, path);
					}else{
						sprintf(*tOutput, "http://%s", net_loc.domain);
					}
				}
			}else{
				*tOutput = new char[17];
				(*tOutput)[0] = '\0';
				strcpy(*tOutput, "No domain set...");
			}
			break;
		}
		default:{
			*tOutput = new char[18];
			(*tOutput)[0] = '\0';
			strcpy(*tOutput, "Error occurred...");
			break;
		}
	}
}

// handy-dandy destructor =D
URL::~URL()
{
	if(net_loc.domain){
		delete[] net_loc.domain;
		net_loc.domain = NULL;
	}
	if(path){
		delete[] path;
		path = NULL;
	}
	if(query){
		delete[] query;
		query = NULL;
	}
	if(fragment){
		delete[] fragment;
		fragment = NULL;
	}
}
