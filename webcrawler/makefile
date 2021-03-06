STRINGUTIL = utils/obj/StringUtil.o
URLINPUTSTREAM = utils/obj/URLInputStream.o
FILEINPUTSTREAM = utils/obj/FileInputStream.o
HTTPINPUTSTREAM = utils/obj/HTTPInputStream.o
COMANDRUNNER = utils/obj/CommandRunner.o
FILESYSTEM = utils/obj/FileSystem.o
HTMLTOKEN = utils/obj/HTMLToken.o
HTMLTOKENIZER = utils/obj/HTMLTokenizer.o

LIBOBJFILES = $(STRINGUTIL) $(URLINPUTSTREAM) $(FILEINPUTSTREAM) $(HTTPINPUTSTREAM) $(COMANDRUNNER) $(FILESYSTEM) $(HTMLTOKEN) $(HTMLTOKENIZER)

COMPILER = g++
RFLAGS = -c -o
DFLAGS = -g $(RFLAGS)
RELEASE = $(COMPILER) $(RFLAGS)
DEBUG = $(COMPILER) $(DFLAGS)
LIB_OBJFILES = lib/cs240utils.a

DEBUG_OBJECTS = obj/debugwebcrawler.o obj/debugurl.o obj/debughtmlparser.o obj/debuglinkedlist.o obj/debugbst.o obj/debugpagequeue.o obj/debugpagesparsed.o obj/debugkeywordindex.o obj/debugoccurrence.o obj/debugxmlprinter.o $(LIB_OBJFILES);
RELEASE_OBJECTS = obj/webcrawler.o obj/url.o obj/htmlparser.o  obj/linkedlist.o obj/bst.o obj/pagequeue.o obj/pagesparsed.o obj/keywordindex.o obj/occurrence.o obj/xmlprinter.o $(LIB_OBJFILES);

INCLUDES = -I ./include -I ./utils/inc


BST_HEADERS = include/bst.h

HTMLPARSER_HEADERS = include/htmlparser.h include/url.h include/bst.h include/keywordindex.h include/pagequeue.h include/pagesparsed.h include/page.h

KEYWORDINDEX_HEADERS = include/keywordindex.h include/bst.h include/occurrence.h

LINKEDLIST_HEADERS = include/linkedlist.h

OCCURRENCE_HEADERS = include/occurrence.h include/bst.h

PAGE_HEADERS = include/page.h

PAGEQUEUE_HEADERS = include/pagequeue.h include/linkedlist.h include/url.h

PAGESPARSED_HEADERS = include/pagesparsed.h include/page.h include/url.h include/linkedlist.h

URL_HEADERS = include/url.h

UTILS_HEADERS = include/utils.h

WEBCRAWLER_HEADERS = include/webcrawler.h include/keywordindex.h include/pagequeue.h include/pagesparsed.h include/bst.h include/url.h include/htmlparser.h include/xmlprinter.h

XMLPRINTER_HEADERS = include/xmlprinter.h include/url.h include/page.h include/pagesparsed.h include/bst.h include/keywordindex.h include/occurrence.h


clean : 
	@ rm utils/obj/* bin/* obj/* lib/*


lib : $(LIB_OBJFILES)
lib/cs240utils.a : $(LIBOBJFILES)
	@ mkdir -p lib
	@ ld -r -o lib/cs240utils.a $(LIBOBJFILES)

$(STRINGUTIL) : utils/inc/StringUtil.h utils/src/StringUtil.cpp
	@ mkdir -p utils/obj
	@ g++ -c -o $(STRINGUTIL) -I utils/inc utils/src/StringUtil.cpp

$(URLINPUTSTREAM) : utils/inc/StringUtil.h utils/inc/CS240Exception.h utils/inc/HTTPInputStream.h utils/inc/FileInputStream.h utils/inc/InputStream.h utils/inc/URLInputStream.h utils/src/URLInputStream.cpp
	@ mkdir -p utils/obj
	@ g++ -c -o $(URLINPUTSTREAM) -I utils/inc utils/src/URLInputStream.cpp

$(FILEINPUTSTREAM) : utils/inc/FileSystem.h utils/inc/CS240Exception.h utils/inc/UnitTest.h utils/src/FileInputStream.cpp
	@ mkdir -p utils/obj
	@ g++ -c -o $(FILEINPUTSTREAM) -I utils/inc utils/src/FileInputStream.cpp

$(HTTPINPUTSTREAM) : utils/inc/StringUtil.h utils/inc/CS240Exception.h utils/inc/HTTPInputStream.h utils/src/HTTPInputStream.cpp
	@ mkdir -p utils/obj
	@ g++ -c -o $(HTTPINPUTSTREAM) -I utils/inc utils/src/HTTPInputStream.cpp

$(COMANDRUNNER) : utils/inc/StringUtil.h utils/inc/CS240Exception.h utils/inc/CommandRunner.h utils/src/CommandRunner.cpp
	@ mkdir -p utils/obj
	@ g++ -c -o $(COMANDRUNNER) -I utils/inc utils/src/CommandRunner.cpp

$(FILESYSTEM) : utils/inc/CS240Exception.h utils/inc/UnitTest.h utils/inc/FileSystem.h utils/src/FileSystem.cpp
	@ mkdir -p utils/obj
	@ g++ -c -o $(FILESYSTEM) -I utils/inc utils/src/FileSystem.cpp

$(HTMLTOKEN) : utils/inc/HTMLToken.h utils/src/HTMLToken.cpp
	@ mkdir -p utils/obj
	@ g++ -c -o $(HTMLTOKEN) -I utils/inc utils/src/HTMLToken.cpp

$(HTMLTOKENIZER) : utils/inc/HTMLTokenizer.h utils/src/HTMLTokenizer.cpp
	@ mkdir -p utils/obj
	@ g++ -c -o $(HTMLTOKENIZER) -I utils/inc utils/src/HTMLTokenizer.cpp



bin : bin/webcrawler
bin/webcrawler : $(RELEASE_OBJECTS)
	@ mkdir -p bin
	g++ -o bin/webcrawler $(RELEASE_OBJECTS)
	@ chmod +x bin/webcrawler

obj/bst.o : src/bst.cpp $(BST_HEADERS)
	@ mkdir -p obj
	$(RELEASE) obj/bst.o $(INCLUDES) src/bst.cpp

obj/htmlparser.o : src/htmlparser.cpp $(HTMLPARSER_HEADERS)
	@ mkdir -p obj
	$(RELEASE) obj/htmlparser.o $(INCLUDES) src/htmlparser.cpp

obj/keywordindex.o : src/keywordindex.cpp $(KEYWORDINDEX_HEADERS)
	@ mkdir -p obj
	$(RELEASE) obj/keywordindex.o $(INCLUDES) src/keywordindex.cpp

obj/linkedlist.o : src/linkedlist.cpp $(LINKEDLIST_HEADERS)
	@ mkdir -p obj
	$(RELEASE) obj/linkedlist.o $(INCLUDES) src/linkedlist.cpp

obj/occurrence.o : src/occurrence.cpp $(OCCURRENCE_HEADERS)
	@ mkdir -p obj
	$(RELEASE) obj/occurrence.o $(INCLUDES) src/occurrence.cpp

obj/pagequeue.o : src/pagequeue.cpp $(PAGEQUEUE_HEADERS)
	@ mkdir -p obj
	$(RELEASE) obj/pagequeue.o $(INCLUDES) src/pagequeue.cpp

obj/pagesparsed.o : src/pagesparsed.cpp $(PAGESPARSED_HEADERS)
	@ mkdir -p obj
	$(RELEASE) obj/pagesparsed.o $(INCLUDES) src/pagesparsed.cpp

obj/url.o : src/url.cpp $(URL_HEADERS)
	@ mkdir -p obj
	$(RELEASE) obj/url.o $(INCLUDES) src/url.cpp

obj/webcrawler.o : src/webcrawler.cpp $(WEBCRAWLER_HEADERS)
	@ mkdir -p obj
	$(RELEASE) obj/webcrawler.o $(INCLUDES) src/webcrawler.cpp

obj/xmlprinter.o : src/xmlprinter.cpp $(XMLPRINTER_HEADERS)
	@ mkdir -p obj
	$(RELEASE) obj/xmlprinter.o $(INCLUDES) src/xmlprinter.cpp



obj/debugbst.o : src/bst.cpp $(BST_HEADERS)
	@ mkdir -p obj
	$(DEBUG) obj/debugbst.o $(INCLUDES) src/bst.cpp

obj/debughtmlparser.o : src/htmlparser.cpp $(HTMLPARSER_HEADERS)
	@ mkdir -p obj
	$(DEBUG) obj/debughtmlparser.o $(INCLUDES) src/htmlparser.cpp

obj/debugkeywordindex.o : src/keywordindex.cpp $(KEYWORDINDEX_HEADERS)
	@ mkdir -p obj
	$(DEBUG) obj/debugkeywordindex.o $(INCLUDES) src/keywordindex.cpp

obj/debuglinkedlist.o : src/linkedlist.cpp $(LINKEDLIST_HEADERS)
	@ mkdir -p obj
	$(DEBUG) obj/debuglinkedlist.o $(INCLUDES) src/linkedlist.cpp

obj/debugoccurrence.o : src/occurrence.cpp $(OCCURRENCE_HEADERS)
	@ mkdir -p obj
	$(DEBUG) obj/debugoccurrence.o $(INCLUDES) src/occurrence.cpp

obj/debugpagequeue.o : src/pagequeue.cpp $(PAGEQUEUE_HEADERS)
	@ mkdir -p obj
	$(DEBUG) obj/debugpagequeue.o $(INCLUDES) src/pagequeue.cpp

obj/debugpagesparsed.o : src/pagesparsed.cpp $(PAGESPARSED_HEADERS)
	@ mkdir -p obj
	$(DEBUG) obj/debugpagesparsed.o $(INCLUDES) src/pagesparsed.cpp

obj/debugurl.o : src/url.cpp $(URL_HEADERS)
	@ mkdir -p obj
	$(DEBUG) obj/debugurl.o $(INCLUDES) src/url.cpp

obj/debugwebcrawler.o : src/webcrawler.cpp $(WEBCRAWLER_HEADERS)
	@ mkdir -p obj
	$(DEBUG) obj/debugwebcrawler.o $(INCLUDES) src/webcrawler.cpp

obj/debugxmlprinter.o : src/xmlprinter.cpp $(XMLPRINTER_HEADERS)
	@ mkdir -p obj
	$(DEBUG) obj/debugxmlprinter.o $(INCLUDES) src/xmlprinter.cpp



test : bin/test
	bin/test file:///home/jameson/Downloads/cs240test/student/index.html input/out.xml input/stopword.txt
bin/test : $(DEBUG_OBJECTS)
	@ mkdir -p bin
	g++ -g -Wall -o bin/test $(DEBUG_OBJECTS)
	@ chmod +x bin/test
