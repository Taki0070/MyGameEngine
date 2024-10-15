#pragma once
#include "Engine/GameObject.h"
#include"Engine/Transform.h"


class FBX;

class ChildOden :
    public GameObject
        
{   
    Transform transform_;
    int hModel;
    FBX* pFbx;
    
    public:
        ChildOden(GameObject* parent);
        ~ChildOden();

        void Initialize() override;//èÉêàâºëzä÷êî
        void Update() override;
        void Draw() override;
        void Release() override;

};

