#include "TitleScene.h"
#include "Engine/Image.h"
#include "TitleSceneImage.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
TitleScene::TitleScene(GameObject* parent)
	: GameObject(parent, "TitleScene")
{
}

void TitleScene::Initialize()
{
	Instantiate<TitleSceneImage>(this);
}

void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE)||Input::IsKeyDown(DIK_S)) {
		SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
		pSM->ChangeScene(SCENE_ID_PLAY);
	}
}

void TitleScene::Draw()
{

}

void TitleScene::Release()
{
}
