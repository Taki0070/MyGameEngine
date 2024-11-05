#include "OverScene.h"
#include"Engine/Input.h"
#include"PlayScene.h"
#include"SceneManager.h"
#include"Model.h"

OverScene::OverScene(GameObject* parent)
	:GameObject(parent, "OverScene"), hModel_(-1)
{
}

OverScene::~OverScene()
{
}

void OverScene::Initialize()
{
	hModel_ = Model::Load("Assets\\Over.fbx");

	this->transform_.position_ = { 0,8,0 };
	this->transform_.scale_ = { 10,10,1 };
	
}

void OverScene::Update()
{
	if (Input::IsKey(DIK_L)) {

		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TEST);
	}
}

void OverScene::Draw()
{

}

void OverScene::Release()
{
}

