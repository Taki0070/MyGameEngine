#include "Player.h"
#include"Engine/FBX.h"
#include"ChildOden.h"
#include"Engine/Input.h"
#include"Model.h"


Player::Player(GameObject* parent)
	:GameObject(parent, "Player"),hModel(-1)
{

}

Player::~Player()
{
}

void Player::Initialize()
{
	hModel = Model::Load("Assets\\Oden.fbx");
	/*pOden = new FBX;
	pOden->Load("Assets//Oden.fbx");*/
	//transform_.scale_ = { 8,8,8 };
	//transform_.position_ = { 0,-2.5,0 };

	this->transform_.scale_.x = 6;
	this->transform_.scale_.y = 6;
	this->transform_.scale_.z = 6;
	this->transform_.position_.x = 0 ;
	this->transform_.position_.y = -2.5;
	this->transform_.position_.z = 0;

	/*GameObject* pCo = Instantiate<ChildOden>(this);
	pCo->SetPosition(2, 0, -1);
	GameObject* pCo2 = Instantiate<ChildOden>(this);
	pCo2->SetPosition(-2, 0, -1);*/

}

void Player::Update()
{
	transform_.rotate_.y += 1;
	
	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.2f;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.2f;
	}

	if (Input::IsKey(DIK_SPACE))
	{
		GameObject *p = Instantiate<ChildOden>(this);
		p->SetPosition(transform_.position_);
		p->SetScale(0.2, 0.2, 0.2);
	}
	

	//transform_.position_.x += 0.1;
}

void Player::Draw()
{
	//pOden->Draw(transform_);
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void Player::Release()
{
	//pOden->Release();
	//delete pOden;
}

void Player::SetPosition(float x, float y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}


