#include "ChildOden.h"
#include"Engine/FBX.h"
#include"Engine/Transform.h"
#include"Model.h"

ChildOden::ChildOden(GameObject* parent)
	:GameObject(parent,"ChildOden"),hModel(-1)
{
}

ChildOden::~ChildOden()
{
}

void ChildOden::Initialize()
{
	/*pFbx = new FBX;
	pFbx->Load("Assets//Oden.fbx");*/
	hModel = Model::Load("Assets\\Oden.fbx");
	transform_.scale_ = { 0.8,0.8f,0.8f };

	/*transform_.scale_.x = 2.5f
	transform_.scale_.y = 2.5f;
	transform_.scale_.z = 2.5f;*/
	

	transform_.position_ = { 4,-2.5,0 };//-2.5
}

void ChildOden::Update()
{
	transform_.position_.y += 0.1;
	if (transform_.position_.y > 15.0)
	{
		KillMe();
	}

}

void ChildOden::Draw()
{
	//pFbx->Draw(transform_);
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void ChildOden::Release()
{
}
