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
	//Player* pPlayer;//�|�C���^�ɂȂ�ϐ��͍ŏ���[p]������
	//pPlayer = new Player(this);//Player�Ƃ��Ďq������ , Player�̐e��PlyaerScene
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