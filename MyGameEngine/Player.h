#pragma once
#include "Engine/GameObject.h"

//�ǂ�����Fbx���Ă̂��錾����Ă����
class FBX;//�O���錾

class Player :
    public GameObject
{
    FBX* pOden;//
public:
    Player(GameObject* parent);
    ~Player();

    void Initialize() override;//�������z�֐�
    void Update() override;
    void Draw() override;
    void Release() override;
};

