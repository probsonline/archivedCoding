#include <windows.h>
#include "mrDataTypes.h"
#include "mrError.h"
#pragma once

/* Mirus window framwork. */
class mrWindow
{
protected:
	WNDCLASS	m_kWndClass;
	HWND		m_hWindow;
	MSG			m_kMessage;

public:
	mrWindow();
	~mrWindow();

	/* Window manipulation functions. */
	mrError32 Create (HINSTANCE	hInstance, 
					  LPSTR		szTitle,
					  mrInt		iWidth	= CW_USEDEFAULT,
					  mrInt		iLength = CW_USEDEFAULT,
					  mrUInt32	iStyle	= WS_OVERLAPPEDWINDOW | WS_VISIBLE);

	static LRESULT CALLBACK WndProc(HWND	hWindow, 
									UINT	iMessage, 
									WPARAM	wParam,
									LPARAM	lParam);

	void Run(void);

	/* Custom functions. */
	virtual mrBool32 MessageHandler (UINT iMessage, WPARAM wParam, LPARAM lParam);

	virtual mrBool32 Frame (void) = 0;

	void SetPosition(mrInt iX, mrInt iY);
	void GetPosition(POINT * pkPosition);

	void SetSize(mrInt iWidth, mrInt iHeight);
	void GetSize(POINT * pkSize);

	void Show(mrInt iShow);
};
