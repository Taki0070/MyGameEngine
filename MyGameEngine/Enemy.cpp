#include "Enemy.h"
#include"Model.h"
Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel(-1)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel = Model::Load("Assets\\Enemy\\snowman.fbx");
	transform_.position_.y = { 2.0f };
	transform_.scale_ = { 0.3f,0.3f,0.3f };
}

void Enemy::Update()
{
	
}

void Enemy::Draw()
{
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);

}

void Enemy::Release()
{
}

void Enemy::SetPosition(float x, float y)
{
	/*transform_.position_.x = x;
	transform_.position_.y = y;*/
}
