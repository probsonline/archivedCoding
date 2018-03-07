/* ConLib.h */

/* avoid redefinition. */
#pragma once

/* Windows standard header file. */
#include <windows.h>

/* ConLib color codes. */
enum ConColor
{
	ConRed = 1,
	ConGreen=2,
	ConBlue=4
};

/* ConLib Control Class. */
class ConLib
{
	/* Screen and keyboard handles. */
	HANDLE m_Screen;
	HANDLE m_Keyboard;

	/* Color attributes. */
	WORD m_TextColor;
	WORD m_BackgroundColor;
		
public:

	/* Constructore /destructor. */
	ConLib();
	~ConLib();

	/* Set attributes. */
	void SetBackgroundColor (WORD Color);
	void SetTextColor		(WORD Color);
	void SetTitle			(char *Title);
	void SetPosition		(COORD Position);

	/* Output Methods. */
	void Clear(void);
	void OutputString(char * String);

	/* Input Methods. */
	void Read(char * Buffer, DWORD BufferSize);
	int GetKey(void);
};
