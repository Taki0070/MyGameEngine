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
	currentSceneID_ = SCENE_ID_TEST;//�ŏ��ɏo���V�[��
	nextSceneID_ = currentSceneID_;//���ꂪ�������A��Ɏ��̃V�[���͓������m�F
	Instantiate<TestScene>(this);
}

void SceneManager::Update()
{
    //���̃V�[�������݂̃V�[���ƈႤ �� �V�[����؂�ւ��Ȃ���΂Ȃ�Ȃ�
    if (currentSceneID_ != nextSceneID_)
    {
        //���̃V�[���̃I�u�W�F�N�g��S�폜( �q�I�u�W�F�N�g�����ׂč폜 )
        auto scene = childList_.begin();
        (*scene)->ReleaseSub();
        SAFE_DELETE(*scene);
        childList_.clear();
        //for (auto itr : childList_)
        //{
        //    itr->ReleaseSub(); //�@���Ԃ�����
        //    SAFE_DELETE(itr);//�@
        //    childList_.clear();//
        //}
          
        //���[�h�����f�[�^��S�폜
        Model::Release();



        
        //���̃V�[�����쐬
        switch (nextSceneID_)
        {
        case SCENE_ID_TEST: Instantiate<TestScene>(this); break;
        case SCENE_ID_PLAY: Instantiate<PlayScene>(this); break;
        }
        //�����V�[�����ł�����A�J�����g�V�[�����X�V
        currentSceneID_ = nextSceneID_;
    }
}

void SceneManager::Draw()
{
}

void SceneManager::Release()
{
}
