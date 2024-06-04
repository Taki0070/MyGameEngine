#pragma once
#include "Direct3D.h"
#include"Camera.h"
#include <DirectXMath.h>

using namespace DirectX;

struct CONSTANT_BUFFER
{
	XMMATRIX	matWVP;
};

class Quad
{
	ID3D11Buffer* pVertexBuffer_;
	ID3D11Buffer* pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;	
public:
	Quad();
	~Quad();
	HRESULT Initialize();
	void Draw();
	void Release();


};