#include "GameObject.h"

GameObject::GameObject()
	:pParent_(nullptr)
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	:pParent_(parent), objectName_(name)
{
}

GameObject::~GameObject()
{
}

void GameObject::UpdateSub()
{
	Update();
	for (auto itr : childList_)//���ɂ��邷�ׂĂ�
	{
		itr->UpdateSub();
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
