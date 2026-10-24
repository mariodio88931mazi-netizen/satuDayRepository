#include "Map.h"
#include "Dxlib.h"

#include <fstream>
#include <sstream>
#include <string>

Map::Map() :
    mapXNum(0), mapYNum(0), isInitialized(false)
{
    for (int i = 0; i < Config::MAP_CHIP_IMAGE_COUNT; i++)
    {
        chipImages[i] = -1;
    }
}

Map::~Map()
{
    Finalize();
}

// 初期化
bool Map::Init()
{
    Finalize();

    // 画像をチップ単位に分割して読み込み
    if(LoadDivGraph(Config::MAP_CHIP_IMAGE_PATH,
        Consig::MAP_CHIP))
}
// マップの読み込み
// 描画
// 描画レイヤー
// 描画フラグ
// 終了処理