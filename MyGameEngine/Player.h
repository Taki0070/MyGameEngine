#pragma once
#include "Engine/GameObject.h"

//‚Ç‚Á‚©‚ÉFbx‚Á‚Ä‚Ì‚ªéŒ¾‚³‚ê‚Ä‚¢‚é‚Æ
class FBX;//‘O•ûéŒ¾

class Player :
    public GameObject
{
    int hModel;
    //FBX* pOden;//
public:
    Player(GameObject* parent);
    ~Player();

    void Initialize() override;//ƒˆ‰¼‘zŠÖ”
    void Update() override;
    void Draw() override;
    void Release() override;
    void SetPosition(float x, float y);
};

