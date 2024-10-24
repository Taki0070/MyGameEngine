#pragma once
#include <list>
#include <string>
#include"Transform.h"


class SphereCollider;

using std::string;
class GameObject
{
	bool isDead_;//������
	
protected:
	std::list<GameObject*> childList_;
	Transform              transform_;
	GameObject*            pParent_;
	string	               objectName_;//�I�u�W�F�N�g�̖��O
	SphereCollider*        pCollider_;

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

	void KillMe();

	//inline��`
	void SetPosition(XMFLOAT3 position) {
		transform_.position_ = position;
	}
	//�C�����C����`
	void SetPosition(float x, float y, float z) {
		SetPosition(XMFLOAT3(x, y, z));
	}

	void SetScale(float sx, float sy, float sz) {
		transform_.scale_ = { sx,sy,sz };
	}
	void SetRotateX(float xrotate) { transform_.position_.x = xrotate; };
	void SetRotateY(float yrotate) { transform_.position_.y = yrotate; };
	void SetRotateZ(float zrotate) { transform_.position_.z = zrotate; };

	GameObject* FindObject(string objName);
	GameObject* GetRootJob();
	GameObject* FindChildObject(string objName);
	void AddCollider(SphereCollider* pCollider);
	void Collision(GameObject* pTarget);
	void RoundRobin(GameObject* pTarget);
	virtual void OnCollision(GameObject* pTarget) {};

	template <class T>
	GameObject* Instantiate(GameObject* parent)
	{
		T* pObject;
		pObject = new T(parent);
		pObject->Initialize();
		childList_.push_back(pObject);
		return(pObject);
	}

	/*template <class T>
	T* Instantiate(GameObject* pParent)
	{
		T* pTmp = new T(pParent);
		if (pTmp != nullptr)
		{
			pTmp->Initialize();
			childList_.push_back(pTmp);
		}
		return pTmp;
	}*/

};
