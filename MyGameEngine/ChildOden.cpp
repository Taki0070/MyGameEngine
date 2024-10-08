#include "ChildOden.h"
#include"Engine/FBX.h"


ChildOden::ChildOden(GameObject* parent)
	:GameObject(parent,"ChildOden")
{
}

ChildOden::~ChildOden()
{
}

void ChildOden::Initialize()
{
	pFbx = new FBX;
	pFbx->Load("Assets//Oden.fbx");
	transform_.scale_ = { 1.5f,1.5f,1.5f };
	/*transform_.scale_.x = 2.5f;
	transform_.scale_.y = 2.5f;
	transform_.scale_.z = 2.5f;*/
	

	transform_.position_ = { 5,-0.5,0 };//-2.5
}

void ChildOden::Update()
{
	transform_.rotate_.y += 1;
}

void ChildOden::Draw()
{
	pFbx->Draw(transform_);
}

void ChildOden::Release()
{
}
