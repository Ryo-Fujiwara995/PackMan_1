#include "GameoverSceneImage.h"
#include "Engine/Image.h"

GameoverSceneImage::GameoverSceneImage(GameObject* parent)
	: GameObject(parent, "GameOverSceneImage"), hGameOver_(-1), hPush_(-1)
{
}

void GameoverSceneImage::Initialize()
{
	//�Q�[���I�[�o�[��ʂɎg���摜
	Image::Load("Gameover.png");
	assert(hGameOver_ >= 0);

	Image::Load("Push.png");
	assert(hPush_ >= 0);
}

void GameoverSceneImage::Update()
{
}

void GameoverSceneImage::Draw()
{
	Image::SetTransform(hGameOver_, transform_);
	Image::Draw(hGameOver_);

	Image::SetTransform(hPush_, transform_);
	Image::Draw(hPush_);
}

void GameoverSceneImage::Release()
{
}
