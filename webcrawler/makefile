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

DEBUG_OBJECTS = obj/debugwebcrawler.o obj/debugurl.o obj/debughtmlparser.o obj/debuglinkedlist.o obj/debugbst.o obj/debugpagequeue.o obj/debugpagesparsed.o obj/debugutils.o obj/debugkeywordindex.o obj/debugoccurrence.o obj/debugxmlprinter.o $(LIB_OBJFILES);
RELEASE_OBJECTS = obj/webcrawler.o obj/url.o obj/htmlparser.o  obj/linkedlist.o obj/bst.o obj/pagequeue.o obj/pagesparsed.o obj/utils.o obj/keywordindex.o obj/occurrence.o obj/xmlprinter.o $(LIB_OBJFILES);

INCLUDES = -I ./include -I ./utils/inc


clean : 
	@ rm utils/obj/* bin/* obj/* lib/*


lib : $(LIB_OBJFILES)
lib/cs240utils.a : $(LIBOBJFILES)
	@ ld -r -o lib/cs240utils.a $(LIBOBJFILES)

$(STRINGUTIL) : utils/inc/StringUtil.h utils/src/StringUtil.cpp
	@ g++ -c -o $(STRINGUTIL) -I utils/inc utils/src/StringUtil.cpp

$(URLINPUTSTREAM) : utils/inc/StringUtil.h utils/inc/CS240Exception.h utils/inc/HTTPInputStream.h utils/inc/FileInputStream.h utils/inc/InputStream.h utils/inc/URLInputStream.h utils/src/URLInputStream.cpp
	@ g++ -c -o $(URLINPUTSTREAM) -I utils/inc utils/src/URLInputStream.cpp

$(FILEINPUTSTREAM) : utils/inc/FileSystem.h utils/inc/CS240Exception.h utils/inc/UnitTest.h utils/src/FileInputStream.cpp
	@ g++ -c -o $(FILEINPUTSTREAM) -I utils/inc utils/src/FileInputStream.cpp

$(HTTPINPUTSTREAM) : utils/inc/StringUtil.h utils/inc/CS240Exception.h utils/inc/HTTPInputStream.h utils/src/HTTPInputStream.cpp
	@ g++ -c -o $(HTTPINPUTSTREAM) -I utils/inc utils/src/HTTPInputStream.cpp

$(COMANDRUNNER) : utils/inc/StringUtil.h utils/inc/CS240Exception.h utils/inc/CommandRunner.h utils/src/CommandRunner.cpp
	@ g++ -c -o $(COMANDRUNNER) -I utils/inc utils/src/CommandRunner.cpp

$(FILESYSTEM) : utils/inc/CS240Exception.h utils/inc/UnitTest.h utils/inc/FileSystem.h utils/src/FileSystem.cpp
	@ g++ -c -o $(FILESYSTEM) -I utils/inc utils/src/FileSystem.cpp

$(HTMLTOKEN) : utils/inc/HTMLToken.h utils/src/HTMLToken.cpp
	@ g++ -c -o $(HTMLTOKEN) -I utils/inc utils/src/HTMLToken.cpp

$(HTMLTOKENIZER) : utils/inc/HTMLTokenizer.h utils/src/HTMLTokenizer.cpp
	@ g++ -c -o $(HTMLTOKENIZER) -I utils/inc utils/src/HTMLTokenizer.cpp



bin : bin/webcrawler
bin/webcrawler : $(RELEASE_OBJECTS)
	g++ -o bin/webcrawler $(RELEASE_OBJECTS)
	@ chmod +x bin/webcrawler

obj/webcrawler.o : src/webcrawler.cpp
	$(RELEASE) obj/webcrawler.o $(INCLUDES) src/webcrawler.cpp

obj/url.o : src/url.cpp
	$(RELEASE) obj/url.o $(INCLUDES) src/url.cpp

obj/htmlparser.o : src/htmlparser.cpp
	$(RELEASE) obj/htmlparser.o $(INCLUDES) src/htmlparser.cpp

obj/linkedlist.o : src/linkedlist.cpp
	$(RELEASE) obj/linkedlist.o $(INCLUDES) src/linkedlist.cpp

obj/pagequeue.o : src/pagequeue.cpp
	$(RELEASE) obj/pagequeue.o $(INCLUDES) src/pagequeue.cpp

obj/pagesparsed.o : src/pagesparsed.cpp
	$(RELEASE) obj/pagesparsed.o $(INCLUDES) src/pagesparsed.cpp

obj/utils.o : src/utils.cpp
	$(RELEASE) obj/utils.o $(INCLUDES) src/utils.cpp

obj/bst.o : src/bst.cpp
	$(RELEASE) obj/bst.o $(INCLUDES) src/bst.cpp

obj/keywordindex.o : src/keywordindex.cpp
	$(RELEASE) obj/keywordindex.o $(INCLUDES) src/keywordindex.cpp

obj/occurrence.o : src/occurrence.cpp
	$(RELEASE) obj/occurrence.o $(INCLUDES) src/occurrence.cpp

obj/xmlprinter.o : src/xmlprinter.cpp
	$(RELEASE) obj/xmlprinter.o $(INCLUDES) src/xmlprinter.cpp



obj/debugwebcrawler.o : src/webcrawler.cpp
	$(DEBUG) obj/debugwebcrawler.o $(INCLUDES) src/webcrawler.cpp

obj/debugurl.o : src/url.cpp
	$(DEBUG) obj/debugurl.o $(INCLUDES) src/url.cpp

obj/debughtmlparser.o : src/htmlparser.cpp
	$(DEBUG) obj/debughtmlparser.o $(INCLUDES) src/htmlparser.cpp

obj/debuglinkedlist.o : src/linkedlist.cpp
	$(DEBUG) obj/debuglinkedlist.o $(INCLUDES) src/linkedlist.cpp

obj/debugpagequeue.o : src/pagequeue.cpp
	$(DEBUG) obj/debugpagequeue.o $(INCLUDES) src/pagequeue.cpp

obj/debugpagesparsed.o : src/pagesparsed.cpp
	$(DEBUG) obj/debugpagesparsed.o $(INCLUDES) src/pagesparsed.cpp

obj/debugutils.o : src/utils.cpp
	$(DEBUG) obj/debugutils.o $(INCLUDES) src/utils.cpp

obj/debugbst.o : src/bst.cpp
	$(DEBUG) obj/debugbst.o $(INCLUDES) src/bst.cpp

obj/debugkeywordindex.o : src/keywordindex.cpp
	$(DEBUG) obj/debugkeywordindex.o $(INCLUDES) src/keywordindex.cpp

obj/debugoccurrence.o : src/occurrence.cpp
	$(DEBUG) obj/debugoccurrence.o $(INCLUDES) src/occurrence.cpp

obj/debugxmlprinter.o : src/xmlprinter.cpp
	$(DEBUG) obj/debugxmlprinter.o $(INCLUDES) src/xmlprinter.cpp



test : bin/test
	bin/test http://www.beatgammit.com/index.html input/out.xml input/stopword.txt
bin/test : $(DEBUG_OBJECTS)
	g++ -g -Wall -o bin/test $(DEBUG_OBJECTS)
	@ chmod +x bin/test
