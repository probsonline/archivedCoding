#include <windows.h>
#include <stdio.h>

#include "Player.h"
#include "../ConLib/ConLib.h"

/* Game status enumeration */
enum GameStatus
{
    GameMainMenu    = 1,
    GameRunning     = 2,
    GamePaused      = 3,
    GameWon         = 4,
    GameLostLife    = 5,
    GameLost        = 6,
    GameExit        = 7,
    GameSplashScreen= 8,
	GameHighScore	= 9
};

enum GameDifficulty
{
    GameEasy = 1,
    GameMedium =2,
    GameDifficult=3
};

const int MonsterKillBonus = 15;

/* Game base class. */
class CGame
{
private:

    /* I/O information. */
    ConLib * m_Console;
    int		m_LastAction;

    /* Game information. */
    int     m_GameStatus;
    COORD   m_Arena;
    CPlayer m_Player;
    COORD * m_Monsters;
    int     m_MonstersNumber;

public:

    /* Constructors/destrucot. */
    CGame();
    CGame(ConLib* Console);
    ~CGame();

    /* Show the relative information based upon game status. */
    void ShowSplash (void);
    void ShowMenu (void);
    void ShowGame (void);
    void ShowWon (void);
    void ShowLostLife (void);
    void ShowLost (void);
    void ShowExit (void);
    void Show (void);
    
    /* Process the turn depending on game status */
    void ProcessSplash (void);
    void ProcessMenu (void);
    void ProcessGame (void);
    void ProcessWon (void);
    void ProcessLostLife (void);
    void ProcessLost (void);
    void ProcessExit (void);
//  void ProcessTurn (void);
    void Process (void);
    
	void ProcessHallOfFame(void);


    /* Set console information */
    void SetConsole (ConLib * Console);
    
    /* Game methods */
    void StartNewGame (int Difficulty);
    void EndGame (void);
    void CheckCollisions ();
    int  GetAction (void);
    int  GetStatus (void);
    void MoveMonsters (void);

	void LoadGame(void);
	void SaveGame(void);





};
