STRINGUTIL = utils/obj/StringUtil.o
URLINPUTSTREAM = utils/obj/URLInputStream.o
FILEINPUTSTREAM = utils/obj/FileInputStream.o
HTTPINPUTSTREAM = utils/obj/HTTPInputStream.o
COMANDRUNNER = utils/obj/CommandRunner.o
FILESYSTEM = utils/obj/FileSystem.o
HTMLTOKEN = utils/obj/HTMLToken.o
HTMLTOKENIZER = utils/obj/HTMLTokenizer.o

LIBOBJFILES = $(STRINGUTIL) $(URLINPUTSTREAM) $(FILEINPUTSTREAM) $(HTTPINPUTSTREAM) $(COMANDRUNNER) $(FILESYSTEM) $(HTMLTOKEN) $(HTMLTOKENIZER)

clean : 
	@ rm $(LIBOBJFILES) bin/webcrawler obj/webcrawler.o lib/cs240utils.a


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
bin/webcrawler : obj/webcrawler.o lib/cs240utils.a
	@ g++ -o bin/webcrawler obj/webcrawler.o lib/cs240utils.a
	@ chmod +x bin/webcrawler

obj/webcrawler.o : src/webcrawler.cpp
	@ g++ -c -o obj/webcrawler.o -I inc src/webcrawler.cpp

test : bin
	@ bin/webcrawler


bin/webcrawler : obj/
