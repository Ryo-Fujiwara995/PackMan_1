#include "GameoverScene.h"
#include "Engine/Image.h"
#include "GameoverSceneImage.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

GameoverScene::GameoverScene(GameObject* parent)
	: GameObject(parent, "GameoverScene")
{
}

void GameoverScene::Initialize()
{
	Instantiate<GameoverSceneImage>(this);
}

void GameoverScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE) || Input::IsKeyDown(DIK_S)) {
		SceneManager* pSM = (SceneManager*)FindObject("SceneManager");
		pSM->ChangeScene(SCENE_ID_TITLE);
	}
}

void GameoverScene::Draw()
{
}

void GameoverScene::Release()
{
}
