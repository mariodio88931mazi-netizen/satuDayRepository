#pragma once

#include <vector>
#include "Config.h"
class Map
{
private:
	// ファイルを読み込み

	/// <summary>
	/// ロードマップ
	/// </summary>
	/// <param name="filePath">マップCSV</param>
	/// <param name="mapData">マップチップイメージ</param>
	/// <returns>描画判定</returns>
	bool LoadMap(const char*filePath,std::vector<std::vector<int>>&mapData);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="mapData"></param>
	void DrawLayer(const std::vector<std::vector<int>>& mapData) const;

	/// <summary>
	/// 
	/// </summary>
	/// <param name="mapX"></param>
	/// <param name="mapY"></param>
	/// <returns></returns>
	bool IsValidMapPostion(int mapX, int mapY);

	// マップの内容
	std::vector<std::vector<int>> backMap;
	std::vector<std::vector<int>> baseMap;
	std::vector<std::vector<int>> nearMap;

	int mapXNum;
	int mapYNum;
	bool isInitialized;
public:
	Map();
	~Map();

	//画像とCSVを読み込み

	/// <summary>
	/// 描画
	/// </summary>
	/// <returns></returns>
	bool Init();

	void Draw() const;

	void Finalize();
};