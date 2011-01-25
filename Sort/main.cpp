#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include "line.h"
#include "sort240.h"

using namespace std;

int main(int argc, char** args)
{
	bool bReverse = false;
	bool bInsensitive = false;
	bool bAsNumber = false;

	int iColumn = 1;

	// start with the second param
	int iPos = 1;
	if(args[iPos][0] == '-'){
		int iLength = strlen(args[iPos]);
		// skip the initial '-'
		for(int i = 1; i < iLength; i++){
			switch(args[iPos][i]){
				case 'r':{
					bReverse = true;
					break;
				}
				case 'i':{
					bInsensitive = true;
					break;
				}
				case 'n':{
					bAsNumber = true;
					break;
				}
			}
		}
		iPos++;
	}

	iColumn = atoi(args[iPos]);
	iPos++;

	char* pFileName = args[iPos];
	ifstream tFile;
	tFile.open(pFileName);

	Sort240 tSort240;
	tSort240.setFlags(bReverse, bInsensitive, bAsNumber);

	char tLine[MAX_LINE_LENGTH];
	tLine[0] = '\0';
	while(!tFile.eof()){
		tFile.getline(tLine, MAX_LINE_LENGTH, '\n');
		tSort240.addLine(tLine, iColumn);
	}
	tFile.close();

	tSort240.sort();

	tSort240.output();

    return 0;
}
