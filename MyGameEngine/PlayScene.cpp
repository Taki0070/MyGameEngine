#include "PlayScene.h"
#include"Player.h"
#include"Enemy.h"
#include"Engine/Input.h"
#include"SceneManager.h"

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
	Instantiate<Enemy>(this);
}

void PlayScene::Update()
{
	if (Input::IsKey(DIK_P)) {

		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_OVER);
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
