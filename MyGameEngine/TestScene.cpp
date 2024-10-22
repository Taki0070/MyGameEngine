#include "TestScene.h"
#include"Engine/Input.h"
#include"PlayScene.h"
#include"SceneManager.h"
TestScene::TestScene(GameObject* parent)
	:GameObject(parent,"TestScene")
{
}

TestScene::~TestScene()
{
}

void TestScene::Initialize()
{
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
}

void TestScene::Release()
{
}
