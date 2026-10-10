#pragma once

#include <vector>
#include <string>
using namespace std;

class Map
{
private:
	//マップチップの番号
	vector<vector<int>> mapData;

	//マップの縦横のマスの数
	vector<vector<int>> hitData;
	int mapWidth;
	int mapHeight;

	//マップの大きさ
	static constexpr int CHIP_SIZE = 64;

	//csvファイルの読み込み
	bool LoadCSV(const char* fileName, std::vector<std::vector<int>>& data);
public:
	Map();

	/// <summary>
	/// 初期化
	/// </summary>
	/// <returns>読み込み不正</returns>
	bool Init();
	//マップの描画
	
	/// <summary>
	/// マップの描画
	/// </summary>
	/// <param name="cameraX">カメラ座標X</param>
	/// <param name="cameraY">カメラ座標Y</param>
	void Draw(float cameraX, float cameraY);
	/// <summary>
	/// 通行できるかどうか
	/// </summary>
	/// <param name="tileX">タイルX座標</param>
	/// <param name="tileY">タイルY座標</param>
	/// <returns>通行可能判定</returns>
	bool IsSolid(int tileX, int tileY);

	/// <summary>
	/// ワールド座標から当たり判定を調べる
	/// </summary>
	/// <param name="wroldX">ワールド座標X</param>
	/// <param name="wroldY">ワールド座標Y</param>
	/// <returns></returns>
	bool IsSolidAt(float wroldX, float wroldY);

};