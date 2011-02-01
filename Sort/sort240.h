#ifndef SORT240_H
#define SORT240_H

#define LINE_ARRAY_LENGTH 1024
#define MAX_LINE_LENGTH 1024

class Sort240;

struct FLAGS{
	bool bReverse;
	bool bCaseInsensitive;
	bool bNumeric;
};

struct FILE_LINE{
	char* origLine;
	char* columnPtr;
	FLAGS* flags;
};

class Sort240
{
	public:
		Sort240();
		virtual ~Sort240();
		void addLine(char* tLine, int iColumn);
		void setFlags(bool bReverse, bool bCaseInsensitive, bool bNumeric);
		void output();
		void sort();
	protected:
	private:
		FILE_LINE** fileLineArray;
		int numLines;
		FLAGS flags;
};

#endif // SORT240_H
