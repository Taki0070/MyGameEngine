#include "GameObject.h"
#include "Direct3D.h"

GameObject::GameObject()
	:pParent_(nullptr)
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	:pParent_(parent), objectName_(name),isDead_(false)
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
