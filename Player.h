#pragma once
#include "Engine/GameObject.h"
class Stage;

class Player :
	public GameObject
{
	int hPlayer_;
	float speed_;
	Stage* pStage_;
	int hpMax_;//最大　Hp
	int hpCrr_;//現在のHp
public:
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

