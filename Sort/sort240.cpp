#include "sort240.h"
#include "string.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

int compare(const void* a, const void* b){
	FILE_LINE* fLineA = (FILE_LINE*)a;
	FILE_LINE* fLineB = (FILE_LINE*)b;

	int result = 0;

	if(fLineA->flags->bNumeric){
		int tA = atoi(fLineA->columnPtr);
		int tB = atoi(fLineB->columnPtr);

		result = tA > tB ? 1 : tA == tB ? 0 : -1;
	}else if(fLineA->flags->bCaseInsensitive){
		result = strcasecmp(fLineA->columnPtr, fLineB->columnPtr);
	}else{
		result = strcmp(fLineA->columnPtr, fLineB->columnPtr);
	}

	return fLineA->flags->bReverse ? result * -1 : result;
}

Sort240::Sort240()
{
	fileLineArray = new FILE_LINE[LINE_ARRAY_LENGTH];
	numLines = 0;
	flags.bReverse = false;
	flags.bCaseInsensitive = false;
	flags.bNumeric = false;
}

void Sort240::addLine(char* tLineData, int iColumn){
	fileLineArray[numLines].origLine = new char[MAX_LINE_LENGTH];
	fileLineArray[numLines].columnPtr = new char[MAX_LINE_LENGTH];
	fileLineArray[numLines].columnPtr[0] = '\0';
	strcpy(fileLineArray[numLines].origLine, tLineData);

	fileLineArray[numLines].flags = &flags;

	// check to see if we actually have something other than whitespace
	char* tCol = strtok(tLineData, " \r\t");
	if(tCol){
		// run strtok on the newly created line so we get real addresses
		int iCol = 1;
		while(tCol && iCol != iColumn){
			tCol = strtok(NULL, " \r\t");
			iCol++;
		}
		strcpy(fileLineArray[numLines].columnPtr, tCol);
		numLines++;
	}
}

void Sort240::setFlags(bool tbReverse, bool tbCaseInsensitive, bool tbNumeric){
	flags.bReverse = tbReverse;
	flags.bCaseInsensitive = tbCaseInsensitive;
	flags.bNumeric = tbNumeric;
}

void Sort240::sort(){
	qsort(&fileLineArray[0], numLines, sizeof(FILE_LINE), compare);
}

void Sort240::output(){
	for(int i = 0; i < numLines; i++){
		cout << fileLineArray[i].origLine << endl;
	}
}

Sort240::~Sort240()
{
	for(int i = 0; i < numLines; i++){
		delete fileLineArray[i].origLine;
		fileLineArray[i].origLine = NULL;
		fileLineArray[i].columnPtr = NULL;
	}
}
