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
    void SetPosition(float x, float y);
};

