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

DEBUG_OBJECTS = obj/debugwebcrawler.o obj/debugurl.o obj/debughtmlparser.o obj/debuglinkedlist.o obj/debugpagequeue.o obj/debugurlresolver.o lib/cs240utils.a;
RELEASE_OBJECTS = obj/webcrawler.o obj/url.o obj/htmlparser.o  obj/linkedlist.o obj/pagequeue.o obj/urlresolver.o lib/cs240utils.a;

DEBUG_CASES = debug/webcrawler.o debug/url.o debug/htmlparser.o debug/linkedlist.o debug/pagequeue.o debug/urlresolver.o lib/cs240utils.a;
RELEASE_CASES = obj/webcrawler.o obj/url.o obj/htmlparser.o obj/linkedlist.o obj/pagequeue.o obj/urlresolver.o lib/cs240utils.a;

INCLUDES = -I ./include -I ./utils/inc


clean : 
	@ rm utils/obj/* bin/* obj/* lib/*


lib : lib/cs240utils.a
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
bin/webcrawler : $(RELEASE_CASES)
	g++ -o bin/webcrawler $(RELEASE_OBJECTS)
	@ chmod +x bin/webcrawler

obj/webcrawler.o : src/webcrawler.cpp
	$(RELEASE) obj/webcrawler.o $(INCLUDES) src/webcrawler.cpp

obj/url.o : src/url.cpp
	$(RELEASE) obj/url.o $(INCLUDES) src/url.cpp

obj/htmlparser.o : src/htmlparser.cpp
	$(RELEASE) obj/htmlparser.o $(INCLUDES) src/htmlparser.cpp

obj/urlresolver.o : src/urlresolver.cpp
	$(RELEASE) obj/urlresolver.o $(INCLUDES) src/urlresolver.cpp

obj/linkedlist.o : src/linkedlist.cpp
	$(RELEASE) obj/linkedlist.o $(INCLUDES) src/linkedlist.cpp

obj/pagequeue.o : src/pagequeue.cpp
	$(RELEASE) obj/pagequeue.o $(INCLUDES) src/pagequeue.cpp



debug/webcrawler.o : src/webcrawler.cpp
	$(DEBUG) obj/debugwebcrawler.o $(INCLUDES) src/webcrawler.cpp

debug/url.o : src/url.cpp
	$(DEBUG) obj/debugurl.o $(INCLUDES) src/url.cpp

debug/htmlparser.o : src/htmlparser.cpp
	$(DEBUG) obj/debughtmlparser.o $(INCLUDES) src/htmlparser.cpp

debug/urlresolver.o : src/urlresolver.cpp
	$(DEBUG) obj/debugurlresolver.o $(INCLUDES) src/urlresolver.cpp

debug/linkedlist.o : src/linkedlist.cpp
	$(DEBUG) obj/debuglinkedlist.o $(INCLUDES) src/linkedlist.cpp

debug/pagequeue.o : src/pagequeue.cpp
	$(DEBUG) obj/debugpagequeue.o $(INCLUDES) src/pagequeue.cpp


test : bin/test
bin/test : $(DEBUG_CASES)
	g++ -g -Wall -o bin/test $(DEBUG_OBJECTS)
	@ chmod +x bin/test
