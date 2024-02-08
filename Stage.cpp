#include "vector"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/CsvReader.h"
#include "Stage.h"
#include "Player.h"

//namespace {
//	//const int STAGE_X{ 15 };
//	//const int STAGE_Y{ 15 };
//	//const int sArray[STAGE_X][STAGE_Y] = {};
//}


bool Stage::IsWall(int _x, int _y)
{
	//assert(_y >0,_x > 0);//_x,_y の 配列チェック
	if (stageData_[_y][_x] == STAGE_OBJ::WALL)//壁
		return true;
	else
		return false;

}

Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage"), hFloor_(-1), hBlock_(-1)
{
	//csv読み込み
	CsvReader csv;
	csv.Load("Stage.csv");

	stageWidth_ = csv.GetWidth();
	stageHeight_ = csv.GetHeight();
	//int w = csv.GetWidth();
	//int h = csv.GetHeight();

	//stage 
	for (int i = 0; i < stageHeight_; i++) {
		vector<int> sdata(stageWidth_, 0);
		stageData_.push_back(sdata);
	}

	for (int j = 0; j < stageHeight_; j++) {
		for (int i = 0; i < stageWidth_; i++) {
			stageData_[j][i] = csv.GetValue(i, j);
		}
	}
}

void Stage::Initialize()
{
	hFloor_ = Model::Load("Floor.fbx");
	assert(hFloor_ >= 0);
	hBlock_ = Model::Load("Wall.fbx");
	assert(hBlock_ >= 0);
	Camera::SetPosition({ 6.5, 15.0, -5 });
	Camera::SetTarget({ 6.5, 0, 5.5 });
	//レイキャストでもいける
}

void Stage::Update()
{
}

void Stage::Draw()
{
	Transform floorTrans;
	floorTrans.position_ = { 0,0,0 };

	for (int z = 0; z < stageHeight_; z++) {
		for (int x = 0; x < stageWidth_; x++) {
			floorTrans.position_ = { (float)x, 0, (float)(14 - z) };
			/*if (x == 0 || z == 0 || x == 14 || z == 14) {*/

			if (stageData_[z][x] == 1) {
				Model::SetTransform(hBlock_, floorTrans);
				Model::Draw(hBlock_);
			}
			else {
				Model::SetTransform(hFloor_, floorTrans);
				Model::Draw(hFloor_);
			}
		}
	}
}

void Stage::Release()
{
	//配列の掃除
	for (int i = 0; i < stageHeight_; i++) {
		stageData_[i].clear();
	}
	stageData_.clear();
}
