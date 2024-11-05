#include "TestScene.h"
#include"Engine/Input.h"
#include"PlayScene.h"
#include"SceneManager.h"
#include"Model.h"

TestScene::TestScene(GameObject* parent)
	:GameObject(parent, "TestScene"), hModel_(-1)
{
}

TestScene::~TestScene()
{
}

void TestScene::Initialize()
{
	hModel_ = Model::Load("Assets\\title.fbx");

	this->transform_.position_ = { -2,1.5,0 };
	this->transform_.scale_ = { 1,1,1 };
	this->transform_.rotate_.x = 180;
	this->transform_.rotate_.z = 180;
}

void TestScene::Update()
{
	if (Input::IsKey(DIK_SPACE)) {

		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void TestScene::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TestScene::Release()
{
}
