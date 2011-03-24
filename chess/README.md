# Intro #

Chess is built on the laws of Chess.  These components are not implemented:

* En Passant
* Castling
* Pawn promotion (a Queen always replaces a promoted pawn)

For more information on the rules of chess, please see this Wikipedia article:
[http://en.wikipedia.org/wiki/Rules_of_chess]

Chess uses a pre-built GUI and is structured through layers.  For example, the GUI is only controlled by the GUI controller and never controlled by the underlying code.

Chess supports loading and saving games, complete undo, and a very basic AI.  Play modes include:

* Player v Player
* Player v Computer
* Computer v Player
* Computer v Computer


# Data Structures #

## Board ##

The board is stored in memory as an 8x8 2-dimensional array of pointers to Piece objects where:

* [0][0] => top left
* [7][0] => top right
* [0][7] => bottom left
* [7][7] => bottom right.

This structure was chosen for these reasons:

* Intuitive to get a piece at a position: (3, 4) => [3][4]
* Little or no risk for memory leaks because size stays the same
* Easy to determing moves of queen, rook, and bishop using loops

The array will be private, but this makes debugging very simple.


## Move ##

In chess, a move is simply a start point and an end point.  Storing the type of piece, the color of the piece, and the type and color of a captured piece is also very useful for undoing a move.  This class has these members:

* startX- Original x position
* startY- Original y position
* endX- New x position
* endY- New y position
* piece- The piece making the move
  * Follows the convention of the enumeration in ChessGuiDefines.h
  * e.g.- W_KING means white king
* capturedPiece- The piece (if any) that was captured in this move
  * Follows the convention of the enumeration in ChessGuiDefines.h
  * e.g.- B_PAWN means black pawn


## Move History ##

Moves are made by alternating turns, and undoing moves takes the same approach but in reverse.  For this reason, the move history is implemented as a stack.

In particular, each time a move is made, a Move object is pushed onto the stack and each time a move is undone, a Move object is popped from the stack.



# Classes #

## Game ##

Manages the game data and serves as the interface between the backend and the GUI.  Components include:

* Board
* Move History- An instance of History that tracks move history
* White Player- An instance of Player (can be either AI or Human)  
* Black Player- An instance of Player (can be either AI or Human)
* A stack of defeated pieces for each player
  * Not displayed on the board, but may be in the future
  * Little overhead, so the ability to use this with a different GUI is nice


### Board ###

Manages the board data.  The board is a 2-dimensional array of pointers to pieces.  This makes it much easier to access pieces from user input.  This class does not free the memory allocated when a piece is removed from play.  In fact, the movePiece is merely a convenience method for calling removePiece and addPiece.


### Piece ###

Superclass of all chess pieces.  All chess pieces have these virtual methods:

* test- Performs a unit test. For now, only the move method is tested
* isValidMove- Returns true if the move is legal
  * Assumes no other pieces are on the board if no board provided
  * Checks for collisions if a board is provided

#### Pawn ####

Overrides virtual methods in the Piece class.


#### Rook ####

Overrides virtual methods in the Piece class.


#### Knight ####

Overrides virtual methods in the Piece class.


#### Bishop ####

Overrides virtual methods in the Piece class.


#### Queen ####

Overrides virtual methods in the Piece class.


#### King ####

Overrides virtual methods in the Piece class.




### Player ###

Generic superclass for all players.  There are only two types of players:

* Human- Human player
* AI- Computer AI

Each Player has a method to get the type of player (whether AI or Human).

#### Human ####

A human player.  Nothing useful is stored here, but the inclusion of this class makes it easier for modular, layered programming. Perhaps this class could store such fields as a name, win/loss record, etc.


#### AI ####

The AI defines a simple superclass for all other types of computer AI.  So far there is only one type of AI, but this leaves the option open for dropping in different types of AI and giving the player a choice of AI to play against.

##### SimpleAI #####

This AI makes random, legal moves.




### History ###

A move history.  This manages all move history for both players.  The history is implemented as a stack and moves should be pushed alternating between players.

#### Move ####

Represents a single move.  This object stores which color the piece is, where it was moved from and where it was moved to.  If a piece was captured, this object also stores the type and color of piece that was captured.




### Save Game ###

Saves a game in XML format as directed by the format included in the project specifications.


### Load Game ###

Loads a game from an XML file assuming that the file is in the format included in the project specifications.
