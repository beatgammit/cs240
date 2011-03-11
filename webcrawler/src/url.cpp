/*
 * File:   URL.cpp
 * Author: testtake
 *
 * Created on February 2, 2011, 4:14 PM
 */

#include "url.h"
#include "string.h"
#include "string"
#include <stdio.h>

using namespace std;

#define DOMAIN_START 8

URL::URL(string sPath) {
	bFixup = false;

    head = "";
    path = "";

    if(sPath.find("http://") == 0){
        type = HTTP;

		size_t tPos = sPath.find("/", DOMAIN_START);
        if(tPos != string::npos){
        	head = sPath.substr(0, tPos);
        	path = sPath.substr(tPos);
        }else{
        	head = sPath;
            path[0] = '\0';
        }

        //printf("\nHead: %s\n", head);řř
        //printf("Path: %s\n\n\n", path);
    }else{
        type = FILETYPE;

		head = sPath.substr(0, 7);
		path = sPath.substr(7);
    }
}

void URL::applyChange(char* tToken){
    if(strcmp(tToken, ".") == 0){
        // don't do anything
    }else if(strcmp(tToken, "..") == 0){
        // go up a directory
        int strLen = path.length();
        if(strLen){
            // directory
            if(path[strLen - 1] == '/'){
                path[strLen - 1] = '\0';
                size_t tPos = path.rfind("/");
               	path = path.erase(tPos + 1);
            }else{
            	size_t tPos = path.rfind("/");
                if(tPos){
                	path = path.erase(tPos);
                    tPos = path.rfind('/');
                    path = tPos != string::npos ? path.erase(tPos) : path;
                }
                path += "/";

                bFixup = true;
            }
        }else{
        	path += "/";
        	path += tToken;
        	path += "/";
            bFixup = true;
        }
    }else if(tToken[0] == '#'){
    	path += tToken;
    }else{
        int strLen = path.length();
        if(strLen){
            // we have a directory
            if(path[strLen - 1] == '/'){
            	path += tToken;
            	path += "/";
                bFixup = true;
            }else{
            	size_t tPos = path.rfind("/");
            	path.erase(tPos + 1);
            	path.append(tToken).append("/");
                bFixup = true;
            }
        }else{
        	path.append("/").append(tToken).append("/");
            bFixup = true;
        }
    }
}

string URL::output(){
	string sReturn = head;
	sReturn += path;
	return sReturn;
}

void URL::clearPath(){
    path[0] = '\0';
}

void URL::fixup(){
    if(bFixup){
    	size_t tPos = path.rfind("/");
    	path.erase(tPos);
    }
}

string URL::resolve(string relative){
	string relCopy = string(relative);

	if(relCopy[0] == '/'){
		this->clearPath();
	}

	char* pToken = strtok((char*)relCopy.c_str(), "/");

	while(pToken){
		this->applyChange(pToken);
		pToken = strtok(NULL, "/");
	}

	this->fixup();

	return this->output();
}

URL::URL(const URL& orig) {
}

URL::~URL() {
}

bool URL::domainMatches(URL* tURL){
	int iLen = this->head.length();
	// case doesn't matter
	if(strncasecmp(this->head.c_str(), tURL->head.c_str(), iLen) == 0){
		return true;
	}
	return false;
}

bool URL::pathMatches(URL* tURL){
	// get the length of the string to the last slash (directory)
	size_t tPos = path.rfind("/");

	// case does matter
	if(head.compare(tURL->head) == 0){
		return true;
	}
	return false;
}

bool URL::isRelative(std::string tURL){
	return tURL.find("http://") == 0 ? false : true;
}

string URL::getExtension(){
	string sPath = this->path;
	size_t tPos = sPath.rfind('#');
	if(tPos > 0){
		sPath = sPath.substr(0, tPos);
	}
	tPos = sPath.rfind('?');
	if(tPos > 0){
		sPath = sPath.substr(0, tPos);
	}
	tPos = sPath.rfind('/');
	if(tPos > 0){
		sPath = sPath.substr(tPos);
	}

	tPos = sPath.rfind('.');
	return sPath.substr(tPos + 1);
}
