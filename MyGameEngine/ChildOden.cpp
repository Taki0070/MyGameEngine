#include "ChildOden.h"
#include"Engine/FBX.h"
#include"Engine/Transform.h"
#include"Engine/FBX.h"
#include"Model.h"
#include"Enemy.h"
#include"Engine/SphereCollider.h"

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
	
	//transform_.position_ = { 5.0f,-2.5f,0.0f };
	this->transform_.position_.x = 0.0f;
	this->transform_.position_.y = -1.0f;
	this->transform_.position_.z = 0;
	//transform_.position_ = { 4,-2.5,0 };//-2.5

	SphereCollider* col = new SphereCollider(0.4f);
	//this->AddCollider(col);

}

void ChildOden::Update()
{

	transform_.position_.y += 0.1;
	Enemy* enemy = (Enemy*)FindObject("Enemy");

	float r1 = 0.4;//
	float r2 = 0.4;//Enemy‘¤
	XMFLOAT3 P1 = enemy->GetPosition();
	XMFLOAT3 P2 = transform_.position_;
	XMVECTOR Dist = XMVector3Length (
		                    XMVectorSet(P1.x, P1.y, P1.z, 1) - XMVectorSet(P2.x, P2.y, P2.z, 1));
	float d = XMVectorGetX(Dist);
	if (d <= r1 + r2)
	{
		KillMe();
	}

	if (transform_.position_.y > 5.0)
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

void ChildOden::OnCollision(GameObject* pTarget)
{
	KillMe();
	pTarget->KillMe();
}



