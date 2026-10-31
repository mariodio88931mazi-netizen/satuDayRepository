#include "Dxlib.h"
#include "Config.h"
#include "Map.h"

int WINAPI Winmain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR ipCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	if (Dxlib_Init() == -1) return -1;
	SetSrawScreen(DX_SCREEN_BACK);
}