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
	//Player* pPlayer;//ポインタになる変数は最初に[p]をつける
	//pPlayer = new Player(this);//Playerとして子をつくる , Playerの親はPlyaerScene
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
