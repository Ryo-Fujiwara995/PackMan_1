#pragma once
#include "Engine/GameObject.h"
class Stage;

class Player :
	public GameObject
{
	int hPlayer_;
	float speed_;
	Stage* pStage_;
	int hpMax_;//�ő�@Hp
	int hpCrr_;//���݂�Hp
public:
	Player(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

