#include "RootJob.h"
#include"PlayScene.h"
#include"SceneManager.h"

RootJob::RootJob(GameObject* parent)
	:GameObject(parent,"RootJob")
{
}

RootJob::~RootJob()
{
}

void RootJob::Initialize()
{
	//PlayScene クラスも多分GameObjectを継承
	/*PlayScene* pPlayScene;
	pPlayScene = new PlayScene(this);
	pPlayScene->Initialize();
	childList_.push_back(pPlayScene);*/
	Instantiate<SceneManager>(this);
	//ここをシーンマネージャに

}

void RootJob::Update()
{
}

void RootJob::Draw()
{
}

void RootJob::Release()
{
}
