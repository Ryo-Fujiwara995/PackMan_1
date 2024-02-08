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
	//�v���C�x�[�g�ɃA�N�Z�X���邽�߂̂��́@�Q�b�^�[
	int GetStageWidth() { return stageWidth_; }
	int GetStageHeight() { return stageHeight_; }
	//�ԐړI�ȃQ�b�^�[
	bool IsWall(int _x, int _y);
	Stage(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;


};
