#pragma once
#include "Engine/GameObject.h"

//テストシーンを管理するクラス
class GameoverSceneImage : public GameObject
{
	int hGameOver_;
	int hPush_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	GameoverSceneImage(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};