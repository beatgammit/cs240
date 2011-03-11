#include <iostream>
#include <fstream>
#include <string.h>

// my headers
#include "webcrawler.h"
#include "utils.h"
#include "htmlparser.h"
#include "xmlprinter.h"


#define MAXLINELENGTH 64

using namespace std;

int main(int argc, char** argv){
	// program name, start-url, output-file, stopwords file
	if(argc != 4){
		std::cout << "Give me these parameters:" << std::endl;
		std::cout << "\twebcrawler <start-url> <output-file> <stop-words>" << std::endl;
		return 0;
	}

	WebCrawler tCrawler = WebCrawler();
	tCrawler.loadStopWords(argv[3]);

	tCrawler.crawl(string(argv[1]));

	string sReturn = tCrawler.toXML();

	ofstream outFile(argv[2], ios::trunc);

	outFile << sReturn;

	outFile.close();

    return 0;
}

WebCrawler::WebCrawler(){
	this->pStopWords = NULL;
	this->pKeyIndex = new KeywordIndex();
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
	this->startURL = sURL;

	pageQueue.push(sURL);
	while(!pageQueue.IsEmpty()){
		string tURL = pageQueue.pop();
		HTMLParser tParser = HTMLParser(tURL);
		Page* pPage = tParser.parse(&this->pageQueue, &this->pagesParsed, this->pKeyIndex,
									this->pStopWords, this->iStopWords);
	}
}

string WebCrawler::toXML(){
	return XMLPrinter::generateXML(this->startURL, &this->pagesParsed, this->pKeyIndex);
}
