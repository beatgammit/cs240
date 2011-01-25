#include "line.h"
#include <string.h>
#include <ctype.h>

Line::Line(){
}

void Line::setData(Line tLine){
	int tLength = strlen(tLine.pOrigLine);
	pOrigLine = new char[tLength + 1];
	pOrigLine[0] = '\0';

	strncpy(pOrigLine, tLine.pOrigLine, tLength);
	pColumn = pOrigLine + (tLine.pColumn - tLine.pOrigLine);
}

void Line::setData(char* pData, int column)
{
	int tLength = strlen(pData);

	int tFieldsCol = 0;

	int colOffset = 0;

	bool bGettingSpaces = true;
	for(int i = 0; i < tLength; i++){
		if(pData[i] == '\n'){
			// we'll copy everything, even the new line
			pOrigLine = new char[i + 1];
			pOrigLine[0] = '\0';

			strncpy(pOrigLine, pData, i);
			pColumn = &pOrigLine[colOffset];
			break;
		}
		if(bGettingSpaces){
			if(!isspace(pData[i])){
				tFieldsCol++;
				if(tFieldsCol == column){
					colOffset = i;
				}
			}
		}else{
			if(isspace(pData[i])){
				bGettingSpaces = true;
			}
		}
	}
}

char* Line::getLine(){
	return pOrigLine;
}

Line::~Line()
{
	//dtor
}
