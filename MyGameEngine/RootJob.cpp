#include "RootJob.h"
#include"PlayScene.h"

RootJob::RootJob()
{
}

RootJob::~RootJob()
{
}

void RootJob::Initialize()
{
	//PlayScene ƒNƒ‰ƒX‚à‘½•ªGameObject‚ðŒp³
	/*PlayScene* pPlayScene;
	pPlayScene = new PlayScene(this);
	pPlayScene->Initialize();
	childList_.push_back(pPlayScene);*/
	Instantiate<PlayScene>(this);

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
