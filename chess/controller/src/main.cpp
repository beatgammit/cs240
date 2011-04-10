/* Author: Owen Merkling,,, <omerkling@gmail.com>, (C) 2008
 *
 * Copyright: For use by the students of CS 240 at BYU
 *
 * Last edited: Jacob Austin, 26 Mar 2011
 *
 * Instructions: Complete the connectController function
 */

#include <gtkmm/main.h>
#include <glib.h>
#include "ChessGuiImages.h"
#include "ChessView.h"
#include "IChessController.h"
#include "chesscontroller.h"

#include <iostream>
using namespace std;


/******************************************************************************/
/******************* EDIT THE connectController FUNCTION **********************/

//Create your instance of the IChessController interface here and connect it to
//the game object using the SetView method.  Don't forget to connect the game
//object to your IChessController object using the SetController method.
void connectController(ChessView& view, IChessController ** cont, int argc, char ** argv)
{
	*cont = new ChessController(argc, argv);
	(*cont)->SetView(&view);
	view.SetController(*cont);
}



/******************************************************************************/
/************ YOU DO NOT NEED TO EDIT ANYTHING BELOW HERE *********************/

///@def GLADE_FILE
///The loacation of the glade file relative to the loaction of the executable.
///See @link cs240chess.glade "Glade File" @endlink
#define GLADE_FILE "../view/cs240chess.glade"

///@def IMAGE_PATH
///Location of the default image directory relative to the exectuable
#define IMAGE_PATH "../view/images/"

///@def NO_GUI_LOG
///If defined all non-fatal logging messages from the GUI will be hidden
#define NO_GUI_LOG

///A dummy handler to hide non-fatal messeges from the GUI
///@ingroup chessgui
void ChessGui_log_handler(const gchar *log_domain,
						  GLogLevelFlags log_level,
						  const gchar *message, gpointer user_data)
{
	return;
}


int main(int argc,char ** argv)
{

	IChessController* controller = 0;

	#ifndef MEMCHECK

	///Parses path to executable for loading default images and gladeFile
	std::string path(argv[0]);
	int dirFinder = path.find_last_of('/');
	path=path.substr(0,dirFinder+1);


	///Resolves the path of the executable with GLADE_FILE
	std::string gladeFile(path + GLADE_FILE);

	#ifdef NO_GUI_LOG
	int logId = g_log_set_handler("ChessGui",G_LOG_LEVEL_MASK,ChessGui_log_handler,0);
	#endif

	#endif

	try
	{
		#ifdef MEMCHECK

		ChessView game;

		connectController(game, &controller, argc, argv);

		game.run();

		#else

		Gtk::Main myapp(argc,argv);

		///Loads default images based off the path to the executable and IMAGE_PATH
		ChessGuiImages::LoadImages(std::string(path+IMAGE_PATH));

		///Initialize Chess view using glade file
		ChessView game(gladeFile);


		connectController(game, &controller, argc, argv);


		///run game
		game.run(myapp);

		#endif

	}
	catch(std::exception & e)
	{
		g_warning(e.what());
		return 1;
	}
	catch(...)
	{
		g_warning("Unknown Error Occurred, Terminating");
		return 1;
	}


	#ifndef MEMCHECK
	#ifdef NO_GUI_LOG
	g_log_remove_handler("ChessGui",logId);
	#endif
	#endif

	delete controller;

	return 0;
}



