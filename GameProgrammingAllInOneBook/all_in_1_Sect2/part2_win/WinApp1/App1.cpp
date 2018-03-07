#include <windows.h>

LRESULT CALLBACK WndProc (HWND		hWindow,
						  UINT		iMessage,
						  WPARAM	wParam,
						  LPARAM	lParam
						  );

/* Main entry point for the application. */
int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPreInstance, 
				   LPSTR lpCmdLine, 
				   int nShowCmd)
{
	WNDCLASS kWin;

	/* Visual properties. */
	kWin.hCursor = LoadCursor(NULL, IDC_ARROW);
	kWin.hIcon	 = LoadIcon(NULL, IDI_APPLICATION);
	kWin.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);

	/* System properties. */
	kWin.hInstance = hInstance;
	kWin.lpfnWndProc = WndProc;
	kWin.lpszClassName = "First Window";

	/* Extra propertiesm, if not used, must be set to NULL. */
	kWin.lpszMenuName = NULL;
	kWin.cbClsExtra = NULL;
	kWin.cbWndExtra = NULL;
	kWin.style = NULL;

	/* Try to register the class. */
	if(RegisterClass(&kWin))
	{
		HWND hWindow;

		/* Create the windows. */
		hWindow = CreateWindow(kWin.lpszClassName, "A Blank White Window", 
								WS_OVERLAPPEDWINDOW | WS_VISIBLE, 
							   CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
							   NULL, NULL, hInstance, NULL);

		/* The Message loop. */
		MSG kMessage;

		/* Enter the message loop and deal with all messages sent to our window. */
		while(GetMessage(&kMessage, hWindow, 0, 0))
		{
			TranslateMessage(&kMessage);
			DispatchMessage(&kMessage);
		}
	}
	else
	{
		return -1;
	}


	return 0;
}

/* The message handler. */
LRESULT CALLBACK WndProc(HWND		hWindow,
						 UINT		iMessage,
						 WPARAM		wParam,
						 LPARAM		lParam)
{

	switch(iMessage)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return  DefWindowProc(hWindow, iMessage, wParam, lParam);
		break;
	}

	return 0;
}

