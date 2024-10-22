#include "SceneManager.h"
#include"TestScene.h"
#include"PlayScene.h"
#include"Engine/Direct3D.h"
#include"Model.h"

SceneManager::SceneManager(GameObject* parent)
    :GameObject(parent,"SceneManager")
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Initialize()
{
	currentSceneID_ = SCENE_ID_TEST;//最初に出すシーン
	nextSceneID_ = currentSceneID_;//これが違ったら、常に次のシーンは同じか確認
	Instantiate<TestScene>(this);
}

void SceneManager::Update()
{
    //次のシーンが現在のシーンと違う ＝ シーンを切り替えなければならない
    if (currentSceneID_ != nextSceneID_)
    {
        //そのシーンのオブジェクトを全削除( 子オブジェクトをすべて削除 )
        auto scene = childList_.begin();
        (*scene)->ReleaseSub();
        SAFE_DELETE(*scene);
        childList_.clear();
        //for (auto itr : childList_)
        //{
        //    itr->ReleaseSub(); //　実態を消す
        //    SAFE_DELETE(itr);//　
        //    childList_.clear();//
        //}
          
        //ロードしたデータを全削除
        Model::Release();



        
        //次のシーンを作成
        switch (nextSceneID_)
        {
        case SCENE_ID_TEST: Instantiate<TestScene>(this); break;
        case SCENE_ID_PLAY: Instantiate<PlayScene>(this); break;
        }
        //無事シーンができたら、カレントシーンを更新
        currentSceneID_ = nextSceneID_;
    }
}

void SceneManager::Draw()
{
}

void SceneManager::Release()
{
}
