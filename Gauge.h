#pragma once
#include "Engine/GameObject.h"

//�e�X�g�V�[�����Ǘ�����N���X
class Gauge : public GameObject
{
	int hGaugeBar_;//�Q�[�W�摜
	int hGaugeFrame_;//�t���[���̉摜

	int gaugeMaxVal_;//�Q�[�W�̍ő�l
	int gaugeCrrVal_;//�J�����g�i���݂̒l = current value�j�̒l
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Gauge(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
	void SetGaugeVal(int _crr, int _max) {

		gaugeMaxVal_ = _max;
		gaugeCrrVal_ = _crr;
	}
};


