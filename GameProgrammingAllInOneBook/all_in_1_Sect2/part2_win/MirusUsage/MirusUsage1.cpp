#include "mirus.h"

/* Custom Derived class. */

class CustomWindow: public mrWindow
{
public:
	CustomWindow();
	~CustomWindow();

	mrBool32 Frame(void) 
	{
		return mrTrue;
	};
};

/* Default constructor and destructor. */
CustomWindow::CustomWindow(){}
CustomWindow::~CustomWindow(){}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nShowCmd)
{
	CustomWindow kWindow;

	/* Create the window. */
	kWindow.Create(hInstance, "First Mirus Window");

	/* Enter message loop. */
	kWindow.Run();

	return 0;
}
