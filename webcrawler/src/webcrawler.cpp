#include "webcrawler.h"

#define MAXLINELENGTH 64

using namespace std;

int main(int argc, char** argv){
	try{
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

		cout << "Everything's shiny captain.  Here's your XML:" << endl;
		cout << argv[2] << endl;

		return 0;
	}catch(...){
		cout << "Epic fail occurred." << endl;
		return -1;
	}
}

WebCrawler::WebCrawler(){
	this->pStopWords = NULL;
	this->pKeyIndex = new KeywordIndex();
}

void WebCrawler::loadStopWords(char* pFilePath){
	char* sLine = NULL;
	try{
		ifstream tStream;
		tStream.open(pFilePath);

		int lineCount = 0;
		sLine = new char[MAXLINELENGTH];
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
	}catch(IOException ex){
		cout << "IOException on this path: " << pFilePath << endl;
	}
	if(sLine){
		delete[] sLine;
		sLine = NULL;
	}
}

void WebCrawler::crawl(string sURL){
	this->startURL = sURL;

	pageQueue.push(sURL);
	while(!pageQueue.IsEmpty()){
		string tURL = pageQueue.pop();
		cout << tURL << endl;
		HTMLParser tParser = HTMLParser(tURL, this->startURL);
		try{
			Page* pPage = NULL;
			pPage = tParser.parse(&this->pageQueue, &this->pagesParsed, this->pKeyIndex,
									this->pStopWords, this->iStopWords);
			pagesParsed.add(pPage);
		}catch(NetworkException ex){
			cout << "NetworkException on this URL: " << tURL << endl;
		}catch(FileException ex){
			cout << "FileException on this URL: " << tURL << endl;
		}catch(IllegalStateException ex){
			cout << "IllegalStateException on this URL: " << tURL << endl;
		}catch(InvalidArgumentException ex){
			cout << "InvalidArgumentException on this URL: " << tURL << endl;
		}catch(InvalidURLException ex){
			cout << "InvalidURLException on this URL: " << tURL << endl;
		}catch(IOException ex){
			cout << "IOException on this URL: " << tURL << endl;
		}
	}
}

string WebCrawler::toXML(){
	return XMLPrinter::generateXML(this->startURL, &this->pagesParsed, this->pKeyIndex);
}
