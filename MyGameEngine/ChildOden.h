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

        void Initialize() override;//ƒˆ‰¼‘zŠÖ”
        void Update() override;
        void Draw() override;
        void Release() override;

};

