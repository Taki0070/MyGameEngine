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
		this->transform_.pParent_ = &(parent->transform_);//親のtransのアドレスをいれる 子に
	}//ここを付けるとおでんが回ってしまう
}

GameObject::~GameObject()
{
}

void GameObject::UpdateSub()
{
	Update();
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
