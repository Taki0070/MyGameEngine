#pragma once
#include "Engine/GameObject.h"
class RootJob
	:public GameObject
{
public:

	RootJob(GameObject* parent);
	~RootJob();

	void Initialize() override;//�������z�֐�
	void Update() override;
	void Draw() override;
	void Release() override;
};

