#pragma once
#include "Engine/GameObject.h"
class RootJob
	:public GameObject
{
public:

	RootJob(GameObject* parent);
	~RootJob();

	void Initialize() override;//ƒˆ‰¼‘zŠÖ”
	void Update() override;
	void Draw() override;
	void Release() override;
};

