#pragma once
#include "Engine/GameObject.h"
#include <vector>
using namespace std;
using std::vector;
enum STAGE_OBJ {
	FLOOR,
	WALL,
};


class Stage :
	public GameObject
{
	int hFloor_;
	int hBlock_;
	vector<vector<int>> stageData_;
	int stageWidth_, stageHeight_;
public:
	//プライベートにアクセスするためのもの　ゲッター
	int GetStageWidth() { return stageWidth_; }
	int GetStageHeight() { return stageHeight_; }
	//間接的なゲッター
	bool IsWall(int _x, int _y);
	Stage(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;


};
