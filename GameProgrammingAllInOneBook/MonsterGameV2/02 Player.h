#include <windows.h>
#include <time.h>

class CPlayer
{

private:
	COORD	m_Position;
	short	m_Lives;
	int		m_Score;
	int		m_Leaps;

public:
	CPlayer();		/* Constructore */
	~CPlayer();		/* Destructor */

	void Move(COORD Direction);
	void RandomLeap(COORD ArenaSize);

	void GetPosition(COORD *Position);
	void SetPosition(COORD *Position);

	/* Getter and setter methods for private data. */
	void  SetLives(short Lives);
	short GetLives(void);

	void  SetScore(int score);
	int   GetScore(void);

	void  SetLeaps(int Leaps);
	int   GetLeaps(void);
};