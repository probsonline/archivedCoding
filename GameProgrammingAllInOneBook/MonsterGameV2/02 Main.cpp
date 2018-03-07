/* ‘02 Main.cpp’ */

#include <iostream>

/* ConLib header file */
#include "../ConLib/ConLib.h"

/* CGame header file */
#include "02 Game.h"

/* Start */
int main(int argc, char* argv[])
{
	ConLib		Console;
	CGame		Game (&Console);

	 /* Set window title */
	Console.SetTitle ("Monster - The simplest game");

	/* Start and run game */
	while (Game.GetStatus () != GameExit)
	{
		Game.Process ();
	}


	return 0;
}
