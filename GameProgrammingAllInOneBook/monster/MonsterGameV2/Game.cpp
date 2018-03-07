/* '02 Game.cpp' */

#include <fstream.h>

/* CGame complement header file. */
#include "Game.h"

/* Init members to initial status. */
CGame::CGame()
{
    m_Console = NULL;
    m_GameStatus = GameSplashScreen;
    m_LastAction = 0;
    m_Monsters = NULL;
}

/* Init members to initial status with console information. */
CGame::CGame(ConLib *Console)
{
    m_Console = Console;
    m_GameStatus = GameSplashScreen;
    m_LastAction = 0;
    m_Monsters = NULL;
}

/* Default destrucotr. */
CGame::~CGame()
{
    m_Console = NULL;
    m_GameStatus = GameSplashScreen;
    m_LastAction = 0;
    m_Monsters = NULL;
}

/* Starts a new game */
void CGame::StartNewGame (int Difficulty)
{
    int Monster;

    COORD Position;

    m_GameStatus = GameRunning;

    /* Set game difficulty */
    switch (Difficulty)
    {
    case GameEasy:
        m_MonstersNumber = 10;
        m_Player.SetLives (4);
        m_Player.SetLeaps (3);
        m_Arena.X = 25;
        m_Arena.Y = 15;
        break;

    case GameMedium:
        m_MonstersNumber = 25;
        m_Player.SetLives (3);
        m_Player.SetLeaps (2);
        m_Arena.X = 35;
        m_Arena.Y = 18;
        break;

    case GameDifficult:
        m_MonstersNumber = 35;
        m_Player.SetLives (2);
        m_Player.SetLeaps (1);
        m_Arena.X = 50;
        m_Arena.Y = 23;
        break;

    default:
        break;
    }

    /* Create player */
    m_Player.RandomLeap (m_Arena);
    m_Player.GetPosition (&Position);
    m_Player.SetScore (0);

    /* Create monsters */
    m_Monsters = new COORD [m_MonstersNumber];
    srand (time (NULL));

    /* Calculate random positions for monsters */
    for (Monster = 0; Monster < m_MonstersNumber; Monster++)
    {
        /* Make sure position is different than player�s position */
        do
        {
            m_Monsters [Monster].X = (rand () % (m_Arena.X - 1)) + 1;
            m_Monsters [Monster].Y = (rand () % (m_Arena.Y - 1)) + 1;
        }
        while ( (m_Monsters [Monster].X == Position.X) &&
                (m_Monsters [Monster].Y == Position.Y) );
    }
}

/*************************************************************************

  Processing Methods

**************************************************************************/

/* General function that does all tasks for this turn */
void CGame::Process (void)
{
    /* Since the splash screen must be shown when we begin, we must
       force it to be shown because there is no action pending */
    if (m_GameStatus == GameSplashScreen)
    {
        Show ();
    }

    /* If user presses a key, act accordingly */
    if (GetAction ())
    {
        switch (m_GameStatus)
        {
        case GameMainMenu:
            ProcessMenu ();
            break;

        case GameRunning:
            ProcessGame ();
            break;

        case GameLostLife:
            ProcessLostLife ();
            break;

        case GameLost:
            ProcessLost ();
            break;

        case GameWon:
            ProcessWon ();
            break;

        case GameSplashScreen:
            ProcessSplash ();
            break;

        default:
            break;
        }

        Show ();
    }
}

/* Process splash screen */
void CGame::ProcessSplash (void)
{
    /* If user pressed key, just move to main menu */
    if (m_LastAction)
    {
        m_GameStatus = GameMainMenu;
    }
}

/* Gets menu option and either quit or start new game */
void CGame::ProcessMenu (void)
{
    switch (m_LastAction)
    {
    /* Quit game */
    case  VK_ESCAPE:
    case 'Q':
    case 'q':
        m_GameStatus = GameExit;
        break;

    /* Start new game */
    case '1':
        StartNewGame (GameEasy);
        m_GameStatus = GameRunning;
        break;

    case '2':
        StartNewGame (GameMedium);
        m_GameStatus = GameRunning;
        break;

    case '3':
        StartNewGame (GameDifficult);
        m_GameStatus = GameRunning;
        break;

	case 'L':
	case 'l':
        StartNewGame (GameEasy);	/* Make the base. */
		LoadGame();					/* Load the saved parameters. */
        m_GameStatus = GameRunning; /* Set the status to running. */
		break;
    default:
        break;
    }
}

/* Moves player and monsters */
void CGame::ProcessGame (void)
{
    COORD Movement;
    int Monster, MonstersAlive;

    Movement.X = 0;
    Movement.Y = 0;

    /* Move player */
    switch (m_LastAction)
    {
    case VK_UP:
        Movement.Y = -1;
        break;

    case VK_DOWN:
        Movement.Y = 1;
        break;

    case VK_LEFT:
        Movement.X = -1;
        break;

    case VK_RIGHT:
        Movement.X = 1;
        break;

    case VK_HOME:
        Movement.X = -1;
        Movement.Y = -1;
        break;

    case VK_PRIOR:
        Movement.X = 1;
        Movement.Y = -1;
        break;

    case VK_END:
        Movement.X = -1;
        Movement.Y = 1;
        break;

    case VK_NEXT:
        Movement.X = 1;
        Movement.Y = 1;
        break;

    case VK_INSERT:
        if (m_Player.GetLeaps () > 0)
        {
            m_Player.RandomLeap (m_Arena);
            m_Player.SetLeaps (m_Player.GetLeaps () - 1);
        }
		{
			/* Show that no leaps are left. */
		}
        break;

    case VK_ESCAPE:
        EndGame ();
        m_GameStatus = GameMainMenu;
        break;

	case 'S':
	case 's':
		SaveGame();
		break;

	case 'R':	/* Terminate the current game and re-load the previously saved one. */
	case 'r':
        StartNewGame (GameEasy);	/* Make the base. */
		LoadGame();					/* Load the saved parameters. */
        m_GameStatus = GameRunning; /* Set the status to running. */
		break;

    default:
        break;
    }

    /* There was movement */
    if ( (Movement.X != 0) || (Movement.Y != 0) )
    {
        COORD PlayerPosition;
        m_Player.GetPosition (&PlayerPosition);

        /* If inside bounds move */
        if ((Movement.X + PlayerPosition.X > 0) &&
            (Movement.Y + PlayerPosition.Y > 0) &&
            (Movement.X + PlayerPosition.X < m_Arena.X) &&
            (Movement.Y + PlayerPosition.Y < m_Arena.Y) )
        {
            m_Player.Move (Movement);
        }

        /* Do monster AI and check for any collision */
        MoveMonsters ();
        CheckCollisions ();

        /* Check to see if any monster is alive */
        MonstersAlive = 0;
        for (Monster = 0; Monster < m_MonstersNumber; Monster ++)
        {
            /* Check if monster is dead */
            if (m_Monsters [Monster].X != 0)
            {
                MonstersAlive = 1;
                    break;
            }
        }

        if (MonstersAlive == 0)
        {
            m_GameStatus = GameWon;
        }
    }
}

/* Move monsters according to player position */
void CGame::MoveMonsters (void)
{
    COORD Distance, Position;
    int Monster;

    m_Player.GetPosition (&Position);

    for (Monster = 0; Monster < m_MonstersNumber; Monster++)
    {
        /* Check if monster is not dead dead */
        if (m_Monsters [Monster].X != 0)
        {
            Distance.X = Position.X - m_Monsters [Monster].X;
            Distance.Y = Position.Y - m_Monsters [Monster].Y;
            
            /* Make sure movement is unitary */
            if (Distance.X > 0)
            {
                Distance.X = 1;
            }

            if (Distance.X < 0)
            {
                Distance.X = -1;
            }

            if (Distance.Y > 0)
            {
                Distance.Y = 1;
            }

            if (Distance.Y < 0)
            {
                Distance.Y = -1;
            }
            
            /* Move monsters */
            m_Monsters [Monster].X += Distance.X;
            m_Monsters [Monster].Y += Distance.Y;
        }
    }
}

/* Check for collisions between monsters and player */
void CGame::CheckCollisions ()
{
    COORD Position;
    int   MonsterA, MonsterB;

    m_Player.GetPosition (&Position);

    for (MonsterA = 0; MonsterA < m_MonstersNumber; MonsterA ++)
    {
        /* Check if monster is not dead */
        if (m_Monsters [MonsterA].X != 0)
        {
            /* Check for collision with player */
            if ((m_Monsters [MonsterA].X == Position.X) &&
                (m_Monsters [MonsterA].Y == Position.Y) )
            {
                m_Monsters [MonsterA].X = 0;
                m_Monsters [MonsterA].Y = 0;

                /* Set to see if player has any remaining lives */
                if (m_Player.GetLives () - 1 <= 0)
                {
                    m_GameStatus = GameLost;
                }
                else
                {
                    m_GameStatus = GameLostLife;
                }

                return;
            }

            /* Check for collisions with other monsters */
            for (MonsterB = MonsterA+1; MonsterB < m_MonstersNumber; MonsterB++)
            {
                /* Check if monster is not dead */
                if (m_Monsters [MonsterB].X != 0)
                {
                    /* Check for collision with monsters */
                    if ((m_Monsters [MonsterA].X == m_Monsters [MonsterB].X) &&
                        (m_Monsters [MonsterA].Y == m_Monsters [MonsterB].Y) )
                    {
                        m_Monsters [MonsterA].X = m_Monsters [MonsterB].X = 0;
                        m_Monsters [MonsterA].Y = m_Monsters [MonsterB].Y = 0;
                        m_Player.SetScore (m_Player.GetScore () + MonsterKillBonus);
                    }
                }
            }
        }
    }
}


/* Removes a life from the player */
void CGame::ProcessLostLife (void)
{
    int     IsValid = 0;
    int     Monster;
    COORD   Position;

    /* Remove a life from player, if ran out of lives, end game */
    m_Player.SetLives (m_Player.GetLives () - 1);

//  if (m_Player.GetLives () - 1 <= -1)
    if (m_Player.GetLives () - 1 < 0)
    {
        m_GameStatus = GameLost;
    }
    else
    {
        m_GameStatus = GameRunning;
        IsValid = 0;

        /* Calculate random position for Player */
        do
        {
            m_Player.RandomLeap (m_Arena);
            m_Player.GetPosition (&Position);

            /* Make sure position is different than other monsters position */
            for (Monster = 0; Monster < m_MonstersNumber; Monster++)
            {
                /* Check if monster is not dead */
                if (m_Monsters [Monster].X != 0)
                {
                    if ((m_Monsters [Monster].X != Position.X) &&
                    (    m_Monsters [Monster].Y != Position.Y) )
                    {
                        IsValid = 1;
                    }
                    else
                    {
                        IsValid = 0;
                    }
                }
            }
        }
        while ( IsValid == 0 );
    }
}

/* End game and return to main menu */
void CGame::ProcessLost (void)
{
    /* If user pressed key, just move to main menu */
    if (m_LastAction)
    {
        m_GameStatus = GameMainMenu;
    }

    EndGame ();
    Show ();
}

/* End game and return to main menu */
void CGame::ProcessWon (void)
{
    /* If user pressed key, just move to main menu */
    if (m_LastAction)
    {
        m_GameStatus = GameHighScore;
    }
}


/* End game and return to main menu */
void CGame::ProcessHallOfFame (void)
{
    /* If user pressed key, just move to main menu */
    if (m_LastAction)
    {
        m_GameStatus = GameMainMenu;
    }

    EndGame ();
}


/* Finish the game */
void CGame::EndGame (void)
{
    if (m_Monsters != NULL)
    {
        delete [] m_Monsters;
    }

    m_Monsters = NULL;
}

/*************************************************************************

  Show Methods

**************************************************************************/

/* Shows the correct screen depending on the status */
void CGame::Show (void)
{
    m_Console->SetBackgroundColor (0);
    m_Console->SetTextColor (ConRed | ConGreen | ConBlue);
    m_Console->Clear ();

    switch (m_GameStatus)
    {
    case GameSplashScreen:
        ShowSplash ();
        break;

    case GameMainMenu:
        ShowMenu ();
        break;

    case GameRunning:
        ShowGame ();
        break;

    case GameLostLife:
        ShowLostLife ();
        break;

    case GameWon:
        ShowWon ();
        break;

    case GameLost:
        ShowLost ();
        break;

    case GameExit:
        ShowExit ();
        break;

    default:
        break;
    }
}

/* Shows the splash screen with playing instructions */
void CGame::ShowSplash (void)
{
    m_Console->Clear ();
    m_Console->OutputString ("\tWelcome to Monster 1.0 \n\n");
    m_Console->OutputString ("Playing Monster is very easy. \n\n");

    m_Console->OutputString ("The objective of the game is to destroy \n");
    m_Console->OutputString ("all the monsters. Two or more monsters \n");
    m_Console->OutputString ("are destroyed when they move to the \n");
    m_Console->OutputString ("same cell in the field. You also lose a \n");
    m_Console->OutputString ("life if you move to a cell where a \n");
    m_Console->OutputString ("monster is. You move the player with the \n");
    m_Console->OutputString ("numerical keypad in the eight possible \n");
    m_Console->OutputString ("directions. You can also press Insert \n");
    m_Console->OutputString ("which will make you leap to a random \n");
    m_Console->OutputString ("place in the field.\n\n");

    m_Console->SetTextColor (ConRed);
    m_Console->OutputString ("NOTE: Make sure NumLock is turned off.\n\n");
    m_Console->SetTextColor (ConRed | ConGreen | ConBlue);

    m_Console->OutputString ("There are three difficulties available:\n\n");
    m_Console->OutputString (" Easy   : Monsters = 10   Arena = 25 x 15\n");
    m_Console->OutputString ("          Lives    = 4    Leaps = 3\n");
    m_Console->OutputString (" Medium : Monsters = 20   Arena = 35 x 18\n");
    m_Console->OutputString ("          Lives    = 3    Leaps = 2\n");
    m_Console->OutputString (" Hard   : Monsters = 30   Arena = 50 x 23\n");
    m_Console->OutputString ("          Lives    = 2    Leaps = 1\n");

    m_Console->SetTextColor (ConBlue);
    m_Console->OutputString ("\n\nPress any key to continue... \n");
    m_Console->SetTextColor (ConRed | ConGreen | ConBlue);
}

/* Shows the main menu */
void CGame::ShowMenu (void)
{
    COORD Position;

    m_Console->SetBackgroundColor (0);
    m_Console->SetTextColor (ConRed);
    m_Console->Clear ();

    m_Console->SetBackgroundColor (ConRed | ConGreen | ConBlue);

    m_Console->OutputString (" \n");
    m_Console->OutputString (" Monster - version 1.0 \n");
    m_Console->OutputString (" ");

    m_Console->SetBackgroundColor (0);
    m_Console->SetTextColor (ConRed | ConGreen | ConBlue);

    Position.X = 1;
    Position.Y = 4;
    m_Console->SetPosition (Position);
    m_Console->OutputString ("What do you want to do? ");

    Position.X = 3;         /* Set horizontal position for the Menu. */

    Position.Y = 6;
    m_Console->SetPosition (Position);
    m_Console->OutputString ("1 - Start new game - Easy");

    Position.Y = 7;
    m_Console->SetPosition (Position);
    m_Console->OutputString ("2 - Start new game - Medium");

    ++Position.Y;
    m_Console->SetPosition (Position);
    m_Console->OutputString ("3 - Start new game - Hard");

    ++Position.Y;
    m_Console->SetPosition (Position);
    m_Console->OutputString ("L - Load a saved game    ");

    ++Position.Y;
    m_Console->SetPosition (Position);
    m_Console->OutputString ("Q - Exit game");
}

/* Shows the actual game */
void CGame::ShowGame (void)
{
    COORD Position;
    int Monster;

    /* Draw player position */
    m_Console->SetBackgroundColor (0);
    m_Console->SetTextColor (ConGreen);
    m_Player.GetPosition (&Position);
    m_Console->SetPosition (Position);
    m_Console->OutputString ("P");

    /* Draw field */
    int FieldX, FieldY;
    m_Console->SetBackgroundColor (ConRed | ConGreen | ConBlue);
    m_Console->SetTextColor       (ConRed | ConGreen | ConBlue);

    for (FieldY = 0; FieldY <= m_Arena.Y; FieldY++)
    {
        if ( (FieldY == 0) || (FieldY == m_Arena.Y) )
        {
            for (FieldX = 0; FieldX <= m_Arena.X; FieldX++)
            {
                Position.X = FieldX;
                Position.Y = FieldY;
                m_Console->SetPosition (Position);
                m_Console->OutputString ("#");
            }
        }
        else
        {
            Position.X = 0;
            Position.Y = FieldY;
            m_Console->SetPosition (Position);
            m_Console->OutputString ("#");
            Position.X = m_Arena.X;
            Position.Y = FieldY;
            m_Console->SetPosition (Position);
            m_Console->OutputString ("#");
        }
    }

    /* Draw monsters */
    m_Console->SetBackgroundColor (0);
    m_Console->SetTextColor (ConRed);
    for (Monster = 0; Monster < m_MonstersNumber; Monster++)
    {
        if (m_Monsters [Monster].X != 0)
        {
            m_Console->SetPosition (m_Monsters [Monster]);
            m_Console->OutputString ("M");
        }
    }

    /* Show lives and score */
    char GameStatus [100];

    sprintf (GameStatus, "Lives: %d  Score: %d  Leaps: %d  S-Save Game  R-Reload Game",
             m_Player.GetLives () - 1, m_Player.GetScore (),
             m_Player.GetLeaps ());

    Position.X = 2;
    Position.Y = 24;
    m_Console->SetPosition (Position);
    m_Console->SetTextColor (ConRed | ConGreen);
    m_Console->OutputString (GameStatus);
}


/* Shows game won box */
void CGame::ShowWon (void)
{
    ShowGame ();
    COORD Position;

    Position.X = 20;
    Position.Y = 11;
    m_Console->SetPosition (Position);
    m_Console->SetBackgroundColor (ConBlue);
    m_Console->SetTextColor (ConGreen);

    m_Console->OutputString ("########################################");
    ++Position.Y;
    m_Console->SetPosition (Position);
    m_Console->OutputString ("#          Congratulations!            #");
    ++Position.Y;
    m_Console->SetPosition (Position);
    m_Console->OutputString ("# You have killed all the monsters.    #");
    ++Position.Y;
    m_Console->SetPosition (Position);
    m_Console->OutputString ("########################################");
}

/* Shows life lost box */
void CGame::ShowLostLife (void)
{
    ShowGame ();
    COORD Position;

    Position.X = 20;
    Position.Y = 11;
    m_Console->SetPosition (Position);
    m_Console->SetBackgroundColor (ConBlue);
    m_Console->SetTextColor (ConRed);

    m_Console->OutputString ("########################################");
    ++Position.Y;
    m_Console->SetPosition (Position);
    m_Console->OutputString ("#          You have lost a life        #");
    ++Position.Y;
    m_Console->SetPosition (Position);
    m_Console->OutputString ("########################################");
}

/* Shows game lost box */
void CGame::ShowLost (void)
{
    ShowGame ();

    COORD Position;

    Position.X = 20;
    Position.Y = 11;
    m_Console->SetPosition (Position);

    m_Console->SetBackgroundColor (ConBlue);
    m_Console->SetTextColor (ConRed);

    m_Console->OutputString ("########################################");
    ++Position.Y;
    m_Console->SetPosition (Position);
    m_Console->OutputString ("#              Tough luck!             #");
    ++Position.Y;
    m_Console->SetPosition (Position);
    m_Console->OutputString ("#    You have lost all your lives.     #");
    ++Position.Y;
    m_Console->SetPosition (Position);
    m_Console->OutputString ("########################################");
}

/* Shows exit text */
void CGame::ShowExit (void)
{
    m_Console->SetBackgroundColor (0);
    m_Console->SetTextColor (ConRed | ConGreen | ConBlue);
    m_Console->Clear ();
    m_Console->OutputString ("\n Monster 1.0 \n\n\n");
    m_Console->OutputString (" by: Kaleem Anwar (kalim.anwer@gmail.com)\n");
	m_Console->OutputString (" with thanks to \n");
    m_Console->OutputString (" Bruno Sousa (bsousa@fireworks-interactive.com)\n\n\n\n");

    m_Console->OutputString ("Thanks for playing!\n\n\n");
}


/*************************************************************************

  Getter Methods

**************************************************************************/

/* Return the game status information. */
int CGame::GetStatus(void)
{
    return m_GameStatus;
}


/* Get player action */
int CGame::GetAction (void)
{
    /* Get input from user */
    m_LastAction = m_Console->GetKey ();

    return m_LastAction;
}


/*************************************************************************

  Setter Methods

**************************************************************************/
/* Sets a pointer to the console. */
void CGame::SetConsole(ConLib *Console)
{
    m_Console = Console;
}






/*************************************************************************

  Loading and Saving Methods

**************************************************************************/
void CGame::SaveGame(void)
{
	fstream File;

	File.open ("Monster.sav", ios::out | ios::binary );

	if(File.is_open())
	{
		COORD	PlayerPosition;
		short	PlayerLives;
		int		PlayerScore;
		int		PlayerLeaps;

		PlayerLives = m_Player.GetLives();
		PlayerScore = m_Player.GetScore();
		PlayerLeaps = m_Player.GetLeaps();

		/* Get current player position. */
		m_Player.GetPosition(&PlayerPosition);

		/* Save the game to the file. */
		File.write( (char *) &m_Arena,			sizeof(COORD) );
		File.write( (char *) &PlayerPosition,	sizeof(COORD) );
		File.write( (char *) &PlayerLives,		sizeof(short));
		File.write( (char *) &PlayerScore,		sizeof(int));
		File.write( (char *) &PlayerLeaps,		sizeof(int));
		File.write( (char *) &m_MonstersNumber, sizeof(int));
        File.write( (char *) m_Monsters,      (sizeof(COORD) * m_MonstersNumber));
	}

	File.close();
}

void CGame::LoadGame(void)
{

	fstream File;

	File.open ("Monster.sav", ios::in | ios::binary);

	if (File.is_open ())
	{
		COORD	PlayerPosition;
		short	PlayerLives;
		int		PlayerScore;
		int		PlayerLeaps;

		/* Load the game from the file */
		File.read ((char *) &m_Arena,			sizeof (COORD));
		File.read ((char *) &PlayerPosition,	sizeof (COORD));
		File.read ((char *) &PlayerLives,		sizeof (short));
		File.read ((char *) &PlayerScore,		sizeof (int));
		File.read ((char *) &PlayerLeaps,		sizeof (int));
		File.read ((char *) &m_MonstersNumber,	sizeof (int));

		if (m_Monsters != NULL)
		{
			delete [] m_Monsters;
		}
	
		m_Monsters = new COORD [m_MonstersNumber];
		File.read ((char *) m_Monsters, sizeof (COORD) * m_MonstersNumber);

		/* Set information from player class */
		m_Player.SetPosition (&PlayerPosition);
		m_Player.SetLives	 ( PlayerLives);
		m_Player.SetLeaps	 ( PlayerLeaps);
		m_Player.SetScore	 ( PlayerScore);
	}

	File.close ();
}

