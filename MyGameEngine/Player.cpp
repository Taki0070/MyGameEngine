#include "Player.h"
#include"Engine/FBX.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), pOden(nullptr)
{

}

Player::~Player()
{
}

void Player::Initialize()
{
	pOden = new FBX;
	pOden->Load("Assets//Oden.fbx");
	transform_.scale_ = { 8,8,8 };
	transform_.position_ = { 0,-2.5,0 };
}

void Player::Update()
{
	transform_.rotate_.y += 1;

}

void Player::Draw()
{
	pOden->Draw(transform_);
}

void Player::Release()
{
	pOden->Release();
	delete pOden;
}
