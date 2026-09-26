#pragma once

#include "Config.h"


class Map;


class Player
{
private:

    //========================================
    // 座標
    //========================================

    float x;
    float y;


    //========================================
    // 速度
    //========================================

    float velocityX;
    float velocityY;

    ///=======================================
    ///ジャンプアクション
    ///=======================================
    bool isJumping;
    float jumpHeight;
    float jumpVelocity;


    //========================================
    // アニメーション
    //========================================

    float animTimer;

    int animNowType;
    int animNowPattern;
    int animNowIndex;


    //========================================
    // 描画位置補正
    //========================================

    int drawOffsetX;
    int drawOffsetY;


    //========================================
    // プレイヤー画像
    //========================================

    int playerImg[Config::ANIM_PATTERN_NUM * Config::ANIM_TYPE_NUM];


public:

    Player();
    ~Player();

    void SetGround(bool ground);

    void SetHeadHit(bool hit);


    //========================================
    // 初期化
    //========================================

    bool Init();


    //========================================
    // 更新
    //========================================

    void Update(float deltaTime, const Map& map);


    //========================================
    // 描画
    //========================================

    void Draw();
};