#pragma once
#include "Engine/GameObject.h"

//どっかにFbxってのが宣言されていると
class FBX;//前方宣言

class Player :
    public GameObject
{
    int hModel;
    //FBX* pOden;//
public:
    Player(GameObject* parent);
    ~Player();

    void Initialize() override;//純粋仮想関数
    void Update() override;
    void Draw() override;
    void Release() override;
    void SetPosition(float x, float y);
};

