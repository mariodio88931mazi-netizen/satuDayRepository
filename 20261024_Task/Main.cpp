#include "Dxlib.h"
#include "Config.h"
#include "Map.h"

int WINAPI Winmain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR ipCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	if (Dxlib_Init() == -1) return -1;
	SetSrawScreen(DX_SCREEN_BACK);

	Map map;

	if (!map.Init())
	{
		map.Finalize();
		DxLib_End();
		return -1;
	}
	// ÉQÅ[ÉÄÉãÅ[Év

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE))
	{

	}
}