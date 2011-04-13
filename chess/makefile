################################################################################
# CS 240 Chess Project Makefile
# 
# Last Modified: 22 March 2011 by Jacob Austin 
#
# INSTRUCTIONS: This is a starting makefile for the chess project. You are to 
# keep this up-to-date as you add source files. In addition to keeping it 
# up-to-date with new files you create, you need to make the following changes 
# to this makefile:
# 
#	- compile the object files associated with the View into a shared library, 
#	- add pseudo-targets for the different run modes (namely "runhh", "runhc",
#		"runch", and "runcc"),
#	- add a "test" pseudo-target (you will probably want to make a new executable
#		for this with its own main method),
#	- add a "lib" pseudo-target,
#	- edit the command associated with the memcheck pseudo-target (i.e.,
#		the valgrind command. See the note above it for details).
# 
# NOTES: 
# 1. All the code for the GUI side of this project is provided for you. As a 
# result, there are some things in this makefile which you do not need to alter.
# Such items will be clearly marked with comments.
# 2. Out-of-the-box, without making any changes to this initial makefile, 
# running "make run" will compile the code and bring up an empty GUI. 
################################################################################

 
############### --- BEGIN UNTOUCHABLE SECTION - Do Not Edit --- ################
# Macros for GUI libraries.
GTKMM = gtkmm-2.4
SIGC = sigc++-2.0
LIBGLADE = libglademm-2.4

# TODO Re-phrase: CFLAGS are the -I values needed to compile files using the 
# GTKMM, SIGC, and LIBGLADE libraries
CFLAGS = `pkg-config $(GTKMM) $(SIGC) $(LIBGLADE) --cflags`
LIBS   = `pkg-config $(GTKMM) $(SIGC) $(LIBGLADE) --libs`
####################### --- END UNTOUCHABLE SECTION --- ########################


# My additions
GAME = obj/game.o
CHESSCONTROLLER = obj/chesscontroller.o
PIECE = obj/piece.o
HISTORY = obj/history.o
MOVE = obj/move.o
PLAYER = obj/player.o
IO = obj/io.o
SIMPLEAI = obj/simpleai.o
KNIGHT = obj/knight.o
KING = obj/king.o
QUEEN = obj/queen.o
ROOK = obj/rook.o
BISHOP = obj/bishop.o
PAWN = obj/pawn.o
HUMAN = obj/human.o
TINYXML = obj/tinyxml.o
TINYXML_ERROR = obj/tinyxml_error.o
TINYXML_PARSER = obj/tinyxml_parser.o
TINYXML_STR = obj/tinyxml_str.o

CHESSVIEW_LIB = lib/chessview.a

# TODO Re-phrase: Macros for directory tree locations
MODEL_SRC = model/src/
MODEL_INC = model/inc/
MODEL_OBJ = model/obj/
VIEW_SRC = view/src/
VIEW_INC = view/inc/
VIEW_OBJ = view/obj/
CONT_SRC = controller/src/
CONT_INC = controller/inc/
CONT_OBJ = controller/obj/
EXE = bin/chess			# normal executable
MEXE = bin/mchess			# executable for memory testing

# Macros for compilation flags
INCLUDES = -I$(MODEL_INC) -I$(VIEW_INC) -I$(CONT_INC) -I ./include -I ./utils/tinyxml
DEBUG = -g # Uncomment this if you want to compile with debug info


# There are two different main.o files. One is for memory testing.
MAIN_O = $(CONT_OBJ)main.o
MEMMAIN_O = $(CONT_OBJ)memcheck_main.o

# This macro should be used to store all of the object files created 
# from *your* source files
MY_OBJS = $(CHESSCONTROLLER) $(GAME) $(BOARD) $(PIECE) $(HISTORY) $(MOVE) $(PLAYER) $(IO) $(SIMPLEAI) $(KNIGHT) $(KING) $(QUEEN) $(ROOK) $(BISHOP) $(PAWN) $(HUMAN) $(TINYXML) $(TINYXML_ERROR) $(TINYXML_PARSER) $(TINYXML_STR)

# These are all the object files that go into the library
LIB_OBJS = $(VIEW_OBJ)ChessView.o \
      $(VIEW_OBJ)ChessGuiBoardCell.o \
      $(VIEW_OBJ)ChessGuiBoard.o \
      $(VIEW_OBJ)ChessGui.o \
      $(VIEW_OBJ)ChessGuiImages.o \
      $(VIEW_OBJ)SelectDialog.o



################################################################################
# Pseudo-targets

run: $(EXE)
	$(EXE)

bin: $(EXE)

# Run the executable for memory testing
# Instructions: Uncomment and edit the command below so that it runs the  
# memory-check executable in Human-Human mode (i.e., add necessary command  
# line arguments to the end of valgrind the command below).	
memcheck: $(MEXE)
	valgrind --tool=memcheck --leak-check=yes --max-stackframe=5000000 --show-reachable=yes --suppressions=string.supp $(MEXE) #command-line args go here

# Clean removes all of the .o files, libraries, and executables
clean:
	@rm -f $(MODEL_OBJ)*.o
	@rm -f $(VIEW_OBJ)*.o
	@rm -f $(CONT_OBJ)*.o
	@rm -f $(EXE)
	@rm -f $(MEXE)
	@rm -f obj/*.o
	@rm -f lib/*.a


################################################################################
# Targets for executables and main object files

# Explanation: There are two different executables, with two different main 
# object files, because main.cpp needs to be built differently depending on 
# whether you are doing memory testing or not. This is because the GTK library,
# and other GUI tools, have memory leaks that we cannot figure out how to 
# suppress. Therefore, when building an executable for memory testing, we use a
# macro (MEMCHECK) to tell the compiler to not include the code that builds the
# GUI. So when we check for memory leaks during passoff, we don't have to use
# the GUI.

# Main executable
# Note: Once you have added the ability to make a library out of the View files, 
# the executable should be dependant on, and link in the library file, not the 
# .o files! That means, instead of linking in $(LIB_OBJS) below, you should link
# in the actual library file.
$(EXE): $(CHESSVIEW_LIB) $(MAIN_O) $(MY_OBJS)
	@# Re-link executable. Again, this should link the library file, not the .o's
	g++ -o $(EXE) $(INCLUDES) $(CFLAGS) $(LIBS) $(MAIN_O) $(MY_OBJS) $(CHESSVIEW_LIB)
	chmod ugo+x $(EXE)

# Executable for memory testing
$(MEXE): $(CHESSVIEW_LIB) $(MEMMAIN_O) $(MY_OBJS)
	@# Re-link executable. Again, this should link the library file, not the .o's
	g++ -o $(MEXE) $(INCLUDES) $(CFLAGS) $(LIBS) $(MEMMAIN_O) $(MY_OBJS) $(CHESSVIEW_LIB)
	chmod ugo+x $(MEXE)
	

# Main object file
$(MAIN_O): $(CONT_SRC)main.cpp $(VIEW_INC)ChessGuiImages.h $(VIEW_INC)ChessView.h
	g++ $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) -o $(MAIN_O) -c $(CONT_SRC)main.cpp

# Main .o for memory testing
$(MEMMAIN_O): $(CONT_SRC)main.cpp $(VIEW_INC)ChessGuiImages.h $(VIEW_INC)ChessView.h
	g++ -DMEMCHECK $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) -o $(MEMMAIN_O) -c $(CONT_SRC)main.cpp


# ChessView Library
lib : $(CHESSVIEW_LIB)

$(CHESSVIEW_LIB) : $(LIB_OBJS)
	@ mkdir -p lib
	ld -r -o $(CHESSVIEW_LIB) $(LIB_OBJS)



################################################################################
# Targets for YOUR object files...

$(CHESSCONTROLLER) : src/chesscontroller.cpp include/chesscontroller.h $(GAME)
	@ mkdir -p obj
	g++ -g -c -o $(CHESSCONTROLLER) $(INCLUDES) $(CFLAGS) $(LIBS) src/chesscontroller.cpp

$(GAME) : src/game.cpp include/game.h $(HISTORY) $(PIECE) $(MOVE) $(PLAYER)
	@ mkdir -p obj
	g++ -g -c -o $(GAME) $(INCLUDES) $(CFLAGS) $(LIBS) src/game.cpp

$(PIECE) : src/piece.cpp include/piece.h $(MOVE)
	@ mkdir -p obj
	g++ -g -c -o $(PIECE) $(INCLUDES) $(CFLAGS) $(LIBS) src/piece.cpp

$(HISTORY) : src/history.cpp include/history.h $(MOVE)
	@ mkdir -p obj
	g++ -g -c -o $(HISTORY) $(INCLUDES) $(CFLAGS) $(LIBS) src/history.cpp

$(MOVE) : src/move.cpp include/move.h
	@ mkdir -p obj
	g++ -g -c -o $(MOVE) $(INCLUDES) $(CFLAGS) $(LIBS) src/move.cpp

$(PLAYER) : src/player.cpp include/player.h
	@ mkdir -p obj
	g++ -g -c -o $(PLAYER) $(INCLUDES) $(CFLAGS) $(LIBS) src/player.cpp

$(IO) : src/io.cpp include/io.h $(GAME) $(HISTORY) $(PIECE) $(PAWN) $(ROOK) $(KNIGHT) $(BISHOP) $(QUEEN) $(KING) $(TINYXML)
	@ mkdir -p obj
	g++ -g -c -o $(IO) $(INCLUDES) $(CFLAGS) $(LIBS) src/io.cpp

$(SIMPLEAI) : include/ai.h src/simpleai.cpp include/simpleai.h
	@ mkdir -p obj
	g++ -g -c -o $(SIMPLEAI) $(INCLUDES) $(CFLAGS) $(LIBS) src/simpleai.cpp

$(KING) : src/king.cpp include/king.h $(PIECE)
	@ mkdir -p obj
	g++ -g -c -o $(KING) $(INCLUDES) $(CFLAGS) $(LIBS) src/king.cpp

$(QUEEN) : src/queen.cpp include/queen.h $(PIECE)
	@ mkdir -p obj
	g++ -g -c -o $(QUEEN) $(INCLUDES) $(CFLAGS) $(LIBS) src/queen.cpp

$(ROOK) : src/rook.cpp include/rook.h $(PIECE)
	@ mkdir -p obj
	g++ -g -c -o $(ROOK) $(INCLUDES) $(CFLAGS) $(LIBS) src/rook.cpp

$(KNIGHT) : src/knight.cpp include/knight.h $(PIECE)
	@ mkdir -p obj
	g++ -g -c -o $(KNIGHT) $(INCLUDES) $(CFLAGS) $(LIBS) src/knight.cpp

$(BISHOP) : src/bishop.cpp include/bishop.h $(PIECE)
	@ mkdir -p obj
	g++ -g -c -o $(BISHOP) $(INCLUDES) $(CFLAGS) $(LIBS) src/bishop.cpp

$(PAWN) : src/pawn.cpp include/pawn.h $(PIECE)
	@ mkdir -p obj
	g++ -g -c -o $(PAWN) $(INCLUDES) $(CFLAGS) $(LIBS) src/pawn.cpp

$(HUMAN) : src/human.cpp include/human.h $(PIECE)
	@ mkdir -p obj
	g++ -g -c -o $(HUMAN) $(INCLUDES) $(CFLAGS) $(LIBS) src/human.cpp

$(TINYXML) : utils/tinyxml/tinyxml.cpp utils/tinyxml/tinyxml.h
	@ mkdir -p obj
	g++ -c -o $(TINYXML) $(INCLUDES) $(CFLAGS) $(LIBS) utils/tinyxml/tinyxml.cpp

$(TINYXML_ERROR) : utils/tinyxml/tinyxmlerror.cpp
	@ mkdir -p obj
	g++ -c -o $(TINYXML_ERROR) $(INCLUDES) $(CFLAGS) $(LIBS) utils/tinyxml/tinyxmlerror.cpp

$(TINYXML_PARSER) : utils/tinyxml/tinyxmlparser.cpp
	@ mkdir -p obj
	g++ -c -o $(TINYXML_PARSER) $(INCLUDES) $(CFLAGS) $(LIBS) utils/tinyxml/tinyxmlparser.cpp

$(TINYXML_STR) : utils/tinyxml/tinystr.cpp utils/tinyxml/tinystr.h
	@ mkdir -p obj
	g++ -c -o $(TINYXML_STR) $(INCLUDES) $(CFLAGS) $(LIBS) utils/tinyxml/tinystr.cpp

################################################################################
# Targets for GUI-related object files
# Instructions: These will have to be recompiled as position-independant code, 
# so that they can be put into a shared library.

$(VIEW_OBJ)ChessView.o: $(VIEW_SRC)ChessView.cpp $(VIEW_INC)SelectDialog.h $(VIEW_INC)ChessView.h $(CONT_INC)IChessController.h
	g++ -c -o $(VIEW_OBJ)ChessView.o -fPIC $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) $(VIEW_SRC)ChessView.cpp

$(VIEW_OBJ)ChessGuiBoardCell.o: $(VIEW_SRC)ChessGuiBoardCell.cpp $(VIEW_INC)ChessGuiBoardCell.h $(VIEW_INC)ChessGuiImages.h
	g++ -c -o $(VIEW_OBJ)ChessGuiBoardCell.o -fPIC $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) $(VIEW_SRC)ChessGuiBoardCell.cpp

$(VIEW_OBJ)ChessGuiBoard.o: $(VIEW_SRC)ChessGuiBoard.cpp $(VIEW_INC)ChessGuiBoard.h $(VIEW_INC)ChessGui.h $(VIEW_INC)ChessGuiImages.h
	g++ -c -o $(VIEW_OBJ)ChessGuiBoard.o -fPIC $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) $(VIEW_SRC)ChessGuiBoard.cpp

$(VIEW_OBJ)ChessGui.o: $(VIEW_SRC)ChessGui.cpp $(VIEW_INC)ChessGui.h $(VIEW_INC)ChessGuiImages.h $(VIEW_INC)SelectDialog.h
	g++ -c -o $(VIEW_OBJ)ChessGui.o -fPIC $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) $(VIEW_SRC)ChessGui.cpp

$(VIEW_OBJ)ChessGuiImages.o: $(VIEW_SRC)ChessGuiImages.cpp $(VIEW_INC)ChessGuiImages.h $(VIEW_INC)Inline.h
	g++ -c -o $(VIEW_OBJ)ChessGuiImages.o -fPIC $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) $(VIEW_SRC)ChessGuiImages.cpp

$(VIEW_OBJ)SelectDialog.o: $(VIEW_SRC)SelectDialog.cpp
	g++ -c -o $(VIEW_OBJ)SelectDialog.o -fPIC $(DEBUG) $(INCLUDES) $(CFLAGS) $(LIBS) $(VIEW_SRC)SelectDialog.cpp

