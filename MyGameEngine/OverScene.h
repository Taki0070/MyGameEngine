#pragma once
#include"Engine/GameObject.h"
class OverScene
    :public GameObject
{
    int hModel_;
public:
    OverScene(GameObject* parent);
    ~OverScene();

    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;



};


