#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"
#include "Engine/SceneManager.h"
#include "Stage.h"
#include "Gauge.h"
//make PackMan
//PackMan move
namespace {
	const float PLAYER_MOVE_SPEED{ 0.1f };
}

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hPlayer_(-1), speed_(PLAYER_MOVE_SPEED),
	pStage_(nullptr), hpMax_(100), hpCrr_(100) {

}

void Player::Initialize() {

	hPlayer_ = Model::Load("Player.fbx");
	assert(hPlayer_ >= 0);
	//初期位置
	transform_.position_.x = 0.5;
	transform_.position_.z = 1.5;
	pStage_ = (Stage*)FindObject("Stage");
}

void Player::Update() {
	//enum Dir {
	//	UP,LEFT,DOWN,RIGHT,NONE,
	//};
	//int moveDir = Dir::NONE;
	//↓多分使うと思われるやつ
	XMMATRIX rotY = XMMatrixIdentity();//行列1　単位行列
	XMVECTOR vFront{ 0,0,1,0 };//z方向
	XMVECTOR move{ 0,0,0,0 };
	//float speed_ = 0.05f;
	//今向いているベクトルから60.0f で回転させる

	if (Input::IsKey(DIK_UP) || Input::IsKey(DIK_W)) {
		//回転
		if (!XMVector3Equal(move, XMVectorZero())) {

		}
		move = XMVECTOR{ 0,0,1,0 };
		//moveDir = Dir::UP;
	}
	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A)) {
		move = XMVECTOR{ -1,0,0,0 };
		//moveDir = Dir::LEFT;
	}
	if (Input::IsKey(DIK_DOWN) || Input::IsKey(DIK_S)) {
		move = XMVECTOR{ 0,0,-1,0 };
		//moveDir = Dir::DOWN;
	}
	if (Input::IsKey(DIK_RIGHT) || Input::IsKey(DIK_D)) {
		move = XMVECTOR{ 1,0,0,0 };
		//moveDir = Dir::RIGHT;
	}
	//XMVECTOR <--> XMFLOAT 変換
	//XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	//pos = pos + speed_ * move;
	//XMVECTOR posTmp = XMVectorZero();//0ベクトルで初期化
	//////1 posTmp.x posTmp.z => int tx,ty :配列のインデックス
	//////仮にmapの配列をmap[][]とする
	//posTmp = posTmp + speed_ * move;
	//////移動先が、Floorだったら、移動しない
	////if()
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	XMVECTOR posTmp = XMVectorZero();//0ベクトルで初期化
	posTmp = pos + speed_ * move;

	int tx, ty;
	tx = (int)(XMVectorGetX(posTmp) + 1.0f);
	ty = pStage_->GetStageWidth() - (int)(XMVectorGetZ(posTmp) + 1.0f);
	if (!(pStage_->IsWall(tx, ty))) {
		pos = posTmp;
	}
	else {
		hpCrr_ = hpCrr_ - 1;
		if (hpCrr_ < 0) {
			hpCrr_ = 0;
			//if (hpCrr_ = 0) {
				//game over scene ni idou
				SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
				pSM->ChangeScene(SCENE_ID_TITLE);
			//}
			
		}
	}
	//移動先が、wallだったら、移動しない
	//if (pStage_[ty][tx] == STAGE_OBJ::FLOOR) {
	//	pos = pos;
	//}
	//atan2 X Y が解っているとき

	//Debug::Log("(iX, iZ) =");
	//Debug::Log(tx);
	//Debug::Log(".");
	//Debug::Log(ty);
	//pStage_;
	//Debug::Log(pStage_->IsWall(tx, ty), true);
	if (!XMVector3Equal(move, XMVectorZero())) {
		XMStoreFloat3(&(transform_.position_), pos);

		//XMMATRIX rot = XMMatrixRotationY(XM_PIDIV2);
		//XMVECTOR modifiedVec = XMVector3TransformCoord(move, rot);
		//Debug::Log(XMVectorGetX(modifiedVec));
		//Debug::Log(".");
		//Debug::Log(XMVectorGetZ(modifiedVec));

		float angle = atan2(XMVectorGetX(move), XMVectorGetZ(move));

		Debug::Log(" => ");
		Debug::Log(XMConvertToDegrees(angle), true);
		//{0,0,0,0,何もしないときの向き}
		//float rotAngle[5]{ 0,-90,180,90,180 };
		//transform_.rotate_.y = rotAngle[moveDir];
		//1 nomove 
		//回転//方向からとって来る//0と内積は×
		//XMVector3Dot(vFront, move);
		//XMVECTOR vdot = XMVector3Dot(vFront, move);
		//assert(XMVectorGetX(vdot) <= 1 && XMVectorGetX(vdot) >= -1);
		////Xをとって来る命令//ラジアンで帰ってくる0 - 2pai
		//float angle = acos(XMVectorGetX(vdot));

		//XMVECTOR vCross = XMVector3Cross(vFront, move);
		//if (XMVectorGetY(vCross) < 0) {
		//	angle *= -1;
		//}
		transform_.rotate_.y = XMConvertToDegrees(angle);
	}
	//ゲージのインスタンスをFindObjectでみつけて、ゲージ型にキャストして、
	//メンバ変数をよびだして、Packmanの今のHPをゲージに反映させる
	Gauge* pGauge = (Gauge*)FindObject("Gauge");
	pGauge->SetGaugeVal(hpCrr_, hpMax_);

}

void Player::Draw() {

	Model::SetTransform(hPlayer_, transform_);
	Model::Draw(hPlayer_);
}

void Player::Release() {

}