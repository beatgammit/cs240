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
	char* pPath = (char*)sPath.c_str();
    bFixup = false;

    head = new char[MAX_STR];
    path = new char[MAX_STR];

    if(pPath[0] == 'h'){
        type = HTTP;

        char* pPos = strstr(&pPath[DOMAIN_START], "/");
        if(pPos){
            strncpy(head, pPath, pPos - pPath);
            strcpy(path, pPos);
        }else{
            strcpy(head, pPath);
            path[0] = '\0';
        }

        //printf("\nHead: %s\n", head);
        //printf("Path: %s\n\n\n", path);
    }else{
        type = FILETYPE;

        strncpy(head, pPath, 7);
        strcpy(path, &pPath[7]);
    }
}

void URL::applyChange(char* tToken){
    //printf("Token:%s\n", tToken);
    if(strcmp(tToken, ".") == 0){
        // don't do anything
    }else if(strcmp(tToken, "..") == 0){
        // go up a directory
        int strLen = strlen(path);
        if(strLen){
            // directory
            if(path[strLen - 1] == '/'){
                path[strLen - 1] = '\0';
                char* pLoc = strrchr(path, '/');

                path[pLoc - path + 1] = '\0';
            }else{
                char* pLoc = strrchr(path, '/');
                //printf("Loc:%s\n", pLoc);
                if(pLoc){
                    path[pLoc - path] = '\0';
                    pLoc = strrchr(path, '/');
                    if(pLoc){
                        path[pLoc - path] = '\0';
                    }
                }
                strcat(path, "/");

                bFixup = true;
            }
        }else{
            strcat(path, "/");
            strcat(path, tToken);
            strcat(path, "/");
            bFixup = true;
        }
    }else if(tToken[0] == '#'){
        strcat(path, tToken);
    }else{
        int strLen = strlen(path);
        if(strLen){
            // we have a directory
            if(path[strLen - 1] == '/'){
                strcat(path, tToken);
                strcat(path, "/");
                bFixup = true;
            }else{
                char* pLoc = strrchr(path, '/');
                path[pLoc - path + 1] = '\0';
                strcat(path, tToken);
                strcat(path, "/");
                bFixup = true;
            }
        }else{
            strcat(path, "/");
            strcat(path, tToken);
            strcat(path, "/");
            bFixup = true;
        }
    }
    //printf("Path: %s\nToken:%s\n", path, tToken);
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
        char* pLoc = strrchr(path, '/');
        path[pLoc - path] = '\0';
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
	int iLen = strlen(this->head);
	// case doesn't matter
	if(strncasecmp(this->head, tURL->head, iLen) == 0){
		return true;
	}
	return false;
}

bool URL::pathMatches(URL* tURL){
	// get the length of the string to the last slash (directory)
	int iLen = (int)(strrchr(this->path, '/') - this->path);

	// case does matter
	if(strncmp(this->head, tURL->head, iLen) == 0){
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
