#include "GameObject.h"
#include "Direct3D.h"
#include"SphereCollider.h"

GameObject::GameObject()
	:pParent_(nullptr)
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	:pParent_(parent), objectName_(name),isDead_(false),pCollider_(nullptr)
{
	if (parent != nullptr)
	{
		this->transform_.pParent_ = &(parent->transform_);//親のtransのアドレスをいれる 子に
	}//ここを付けるとおでんが回ってしまう
}

GameObject::~GameObject()
{
}

void GameObject::UpdateSub()
{
	Update();

	RoundRobin(GetRootJob());//全部の当たり判定をする


	for (auto itr = childList_.begin(); itr != childList_.end(); itr++)//中にあるすべてを
	{
		(*itr)->UpdateSub();
	}

	for (auto itr = childList_.begin(); itr != childList_.end();) {
		if ((*itr)->isDead_)
		{
			(*itr)->ReleaseSub();
			//(*itr)->Release();
			SAFE_DELETE(*itr);
			itr = childList_.erase(itr);//一個とばす
	
		}
		else
		{
			itr++;
		}
	}

}

void GameObject::DrawSub()
{
	Draw();
	for (auto itr : childList_)//中にあるすべてを
	{
		//(*itr).DrawSub();
		itr->DrawSub();
	}
}

void GameObject::ReleaseSub()
{
	Release();
	for (auto itr : childList_)//中にあるすべてを
	{
		itr->ReleaseSub();
	}
}

void GameObject::KillMe()
{
	isDead_ = true;
}

GameObject* GameObject::FindObject(string objName)
{
	GameObject* rootJob = GetRootJob();
	GameObject* res = rootJob->FindChildObject(objName);
	return (res);
}

GameObject* GameObject::GetRootJob()
{
	if (pParent_ == nullptr) {//あるペアレントを見たとき
		return this;
	}
	return pParent_->GetRootJob();
}

GameObject* GameObject::FindChildObject(string objName)
{
	if (this->objectName_ == objName)//this見たとき
	{
		return this;
	}
	else {
		for (auto itr : childList_)
		{
			GameObject* obj = itr->FindChildObject(objName);
			if (obj != nullptr) {
				return obj;
			}
		}
		return nullptr;//なにも見つからないとき
	}

	return nullptr;
}

void GameObject::AddCollider(SphereCollider* pCollider)
{
	pCollider_ = pCollider;
}

void GameObject::Collision(GameObject* pTarget)
{
	//this 自分
	if (this->pCollider_ == nullptr || pTarget->pCollider_ == nullptr || this == pTarget)
			return;
		//自分とターゲットのコライダー　あたり判定
	XMVECTOR Me = XMLoadFloat3(&(transform_.position_));
	XMVECTOR Ta = XMLoadFloat3(&(pTarget->transform_.position_));

	float dist = XMVectorGetX(XMVector3Length(Me - Ta));//thisとTargetの距離
	float rdist = this->pCollider_->GetRadius() + pTarget->pCollider_->GetRadius();//thisとTargetのコライダーの半径の和
	if (dist <= rdist)//二点間の距離 <= 半径の足し算
	{
		OnCollision(pTarget);		
	}
	
	
}

void GameObject::RoundRobin(GameObject* pTarget)
{//if (this->pCollider_ == nullptr || pTarget->pCollider_ == nullptr )
	if (this->pCollider_ == nullptr) {
		return;
	}
	if (pTarget->pCollider_ != nullptr){
		Collision(pTarget);
	}
	//自分とターゲットを子オブジェクト全部の当たり判定
	for (auto& itr : pTarget->childList_)
	{
		RoundRobin(itr);
	}
}
