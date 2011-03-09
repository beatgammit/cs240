#include <iostream>
#include <fstream>
#include <string.h>

// my headers
#include "webcrawler.h"
#include "htmlparser.h"

#define MAXLINELENGTH 64

using namespace std;

int main(int argc, char** argv)
{
	// program name, start-url, output-file, stopwords file
	if(argc != 4){
		std::cout << "Give me these parameters:" << std::endl;
		std::cout << "\twebcrawler <start-url> <output-file> <stop-words>" << std::endl;
		return 0;
	}

	cout << "Arg1: " << argv[1] << endl;
	cout << "Arg2: " << argv[2] << endl;
	cout << "Arg3: " << argv[3] << endl;

	cout << endl;

	WebCrawler tCrawler = WebCrawler();
	tCrawler.loadStopWords(argv[3]);

	tCrawler.crawl(string(argv[1]));

    return 0;
}

WebCrawler::WebCrawler(){
	this->pStopWords = NULL;
}

void WebCrawler::loadStopWords(char* pFilePath){
	ifstream tStream;
	tStream.open(pFilePath);

	int lineCount = 0;
	char* sLine = new char[MAXLINELENGTH];
	while(!tStream.eof()){
		tStream.getline(sLine, MAXLINELENGTH, '\n');

		// make sure that we have a word, not an empty line
		if(strlen(sLine)){
			lineCount++;
		}
	}
	tStream.close();

	this->pStopWords = new string[lineCount];

	tStream.open(pFilePath);
	int iPos = 0;
	while(!tStream.eof()){
		tStream.getline(sLine, MAXLINELENGTH, '\n');
		// make sure that we have a word, not an empty line
		if(strlen(sLine)){
			this->pStopWords[iPos] = sLine;
			iPos++;
		}
	}
	tStream.close();

	this->iStopWords = lineCount;
	delete[] sLine;
}

void WebCrawler::crawl(string sURL){
	HTMLParser tParser = HTMLParser(sURL);
	Page* pPage = tParser.parse(&this->pageQueue, &this->pagesParsed, NULL, this->pStopWords, this->iStopWords);

	cout << endl << "URL: " << pPage->pURL << endl << "Description: " << pPage->description << endl;

	while(!pageQueue.IsEmpty()){
		cout << pageQueue.pop() << endl;
	}
}
