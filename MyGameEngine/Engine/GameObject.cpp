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
		this->transform_.pParent_ = &(parent->transform_);//�e��trans�̃A�h���X������� �q��
	}//������t����Ƃ��ł񂪉���Ă��܂�
}

GameObject::~GameObject()
{
}

void GameObject::UpdateSub()
{
	Update();

	RoundRobin(GetRootJob());//�S���̓����蔻�������


	for (auto itr = childList_.begin(); itr != childList_.end(); itr++)//���ɂ��邷�ׂĂ�
	{
		(*itr)->UpdateSub();
	}

	for (auto itr = childList_.begin(); itr != childList_.end();) {
		if ((*itr)->isDead_)
		{
			(*itr)->ReleaseSub();
			//(*itr)->Release();
			SAFE_DELETE(*itr);
			itr = childList_.erase(itr);//��Ƃ΂�
	
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
	for (auto itr : childList_)//���ɂ��邷�ׂĂ�
	{
		//(*itr).DrawSub();
		itr->DrawSub();
	}
}

void GameObject::ReleaseSub()
{
	Release();
	for (auto itr : childList_)//���ɂ��邷�ׂĂ�
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
	if (pParent_ == nullptr) {//����y�A�����g�������Ƃ�
		return this;
	}
	return pParent_->GetRootJob();
}

GameObject* GameObject::FindChildObject(string objName)
{
	if (this->objectName_ == objName)//this�����Ƃ�
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
		return nullptr;//�Ȃɂ�������Ȃ��Ƃ�
	}

	return nullptr;
}

void GameObject::AddCollider(SphereCollider* pCollider)
{
	pCollider_ = pCollider;
}

void GameObject::Collision(GameObject* pTarget)
{
	//this ����
	if (this->pCollider_ == nullptr || pTarget->pCollider_ == nullptr || this == pTarget)
			return;
		//�����ƃ^�[�Q�b�g�̃R���C�_�[�@�����蔻��
	XMVECTOR Me = XMLoadFloat3(&(transform_.position_));
	XMVECTOR Ta = XMLoadFloat3(&(pTarget->transform_.position_));

	float dist = XMVectorGetX(XMVector3Length(Me - Ta));//this��Target�̋���
	float rdist = this->pCollider_->GetRadius() + pTarget->pCollider_->GetRadius();//this��Target�̃R���C�_�[�̔��a�̘a
	if (dist <= rdist)//��_�Ԃ̋��� <= ���a�̑����Z
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
	//�����ƃ^�[�Q�b�g���q�I�u�W�F�N�g�S���̓����蔻��
	for (auto& itr : pTarget->childList_)
	{
		RoundRobin(itr);
	}
}
