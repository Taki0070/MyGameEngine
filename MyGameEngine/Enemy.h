#pragma once
#include"Engine/GameObject.h"
class Enemy
	:public GameObject
{
    int hModel;
    //FBX* pOden;//
public:
    Enemy(GameObject* parent);
    ~Enemy();

    void Initialize() override;//�������z�֐�
    void Update() override;
    void Draw() override;
    void Release() override;
    XMFLOAT3 GetPosition() { return (transform_.position_); }
    void SetPosition(float x, float y);
};

