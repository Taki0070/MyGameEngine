#pragma once
#include <list>
#include <string>
#include"Transform.h"

class GameObject
{
protected:
	std::list<GameObject*> childList_;
	Transform  transform_;
	GameObject* pParent_;
	std::string	objectName_;

public:
	GameObject();
	GameObject(GameObject* parent, const std::string& name);
	~GameObject();

	virtual void Initialize() = 0;//�������z�֐�
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Release() = 0;
	void UpdateSub();
	void DrawSub();
	void ReleaseSub();

	void SetPosition(XMFLOAT3 position) {
		transform_.position_ = position;
	}
	//�C�����C����`
	void SetPosition(float x, float y, float z) {
		SetPosition(XMFLOAT3(x, y, z));
	}


	template <class T>
	T* Instantiate(GameObject* pParent)
	{
		T* pTmp = new T(pParent);
		if (pTmp != nullptr)
		{
			pTmp->Initialize();
			childList_.push_back(pTmp);
		}
		return pTmp;
	}

};