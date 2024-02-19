#include "TitleSceneImage.h"
#include "Engine/Image.h"

TitleSceneImage::TitleSceneImage(GameObject* parent)
	: GameObject(parent, "TitleSceneImage"),hTitle_(-1),hPush_(-1)
{
}

void TitleSceneImage::Initialize()
{
	hTitle_ = Image::Load("Title2.png");
	assert(hTitle_ >= 0);

	//Push oo ‚à“ü‚ê‚éHH
	hPush_ = Image::Load("Push.png");
	assert(hPush_ >= 0);

}

void TitleSceneImage::Update()
{

}

void TitleSceneImage::Draw()
{
	Image::SetTransform(hTitle_, transform_);
	Image::Draw(hTitle_);

	Image::SetTransform(hPush_, transform_);
	Image::Draw(hPush_);
}

void TitleSceneImage::Release()
{
}
