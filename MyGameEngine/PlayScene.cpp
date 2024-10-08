#include "PlayScene.h"
#include"Player.h"


PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

PlayScene::~PlayScene()
{
}

void PlayScene::Initialize()
{
	//Player* pPlayer;//ポインタになる変数は最初に[p]をつける
	//pPlayer = new Player(this);//Playerとして子をつくる , Playerの親はPlyaerScene
	//pPlayer->Initialize();
	//childList_.push_back(pPlayer);

	Instantiate<Player>(this);
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
