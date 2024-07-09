#pragma once
#include "Quad.h"
#include"Transform.h"
class Dice :
	public Quad
{

public:
	Dice() :Quad() {};
	~Dice();
	//virtual HRESULT Initialize();
	//virtual void Draw(Transform& transform);
	void InitVertexData()override;
	void InitIndexData()override;

	//virtual void Draw(XMMATRIX& worldMatrix);
};
