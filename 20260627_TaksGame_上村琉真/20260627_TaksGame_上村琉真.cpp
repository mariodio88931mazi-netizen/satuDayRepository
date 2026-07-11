/*目的：
画像の切り替えと入力処理を利用してゲームを作成する。

条件：
画像を3枚以上使用すること
キーボードまたはマウス入力を使用すること
入力によって画像が変化すること
ゲーム開始から終了までの流れがあること*/
#include "DxLib.h"
using namespace std;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(TRUE);

    if (DxLib_Init() == -1)
        return -1;

    SetDrawScreen(DX_SCREEN_BACK);

    //  変数宣言
    int egg = LoadGraph("img/egg.png");
    int jrDorgon = LoadGraph("img/jr.Dorgon.jpg");
    int Dorgon = LoadGraph("img/Dorgon.png");

    int count = 0;
    int image = 0;

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        ClearDrawScreen();

        // SPACEキーを押した瞬間だけカウント
        if (CheckHitKey(KEY_INPUT_SPACE))
        {
            while (CheckHitKey(KEY_INPUT_SPACE))
            {
                ProcessMessage();
            }

            count++;
        }

        if (count >= 20)
            image = 2;
        else if (count >= 10)
            image = 1;
        else
            image = 0;

        switch (image)
        {
        case 0:
            DrawGraph(250, 100, egg, TRUE);
            break;

        case 1:
            DrawGraph(250, 100, jrDorgon, TRUE);
            break;

        case 2:
            DrawGraph(250, 100, Dorgon, TRUE);
            DrawString(220, 50, "育成成功！", GetColor(255, 255, 0));
            break;
        }

        DrawFormatString(20, 20, GetColor(255, 255, 255), " スペース:%d回", count);
        
        ScreenFlip();
    }

    DeleteGraph(egg);
    DeleteGraph(jrDorgon);
    DeleteGraph(Dorgon);

    DxLib_End();

    return 0;
}