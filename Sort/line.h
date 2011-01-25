#ifndef LINE_H
#define LINE_H


class Line
{
	public:
		Line();
		void setData(Line tLine);
		void setData(char* pLine, int column);
		char* getLine();
		virtual ~Line();
	protected:
	private:
		char* pOrigLine;
		char* pColumn;
};

#endif // LINE_H
