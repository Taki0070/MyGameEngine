#pragma once
#include "Engine/GameObject.h"

class FBX;

class ChildOden :
    public GameObject
        
{   
    FBX* pFbx;
    public:
        ChildOden(GameObject* parent);
        ~ChildOden();

        void Initialize() override;//�������z�֐�
        void Update() override;
        void Draw() override;
        void Release() override;

};

