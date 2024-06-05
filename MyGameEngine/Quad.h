#pragma once
#include "Direct3D.h"
#include"Camera.h"
#include "Texture.h"
#include <DirectXMath.h>

using namespace DirectX;

struct CONSTANT_BUFFER
{
	XMMATRIX	matWVP;
};

//頂点情報
struct VERTEX
{
	XMVECTOR position;
	XMVECTOR uv;
};

class Quad
{
	ID3D11Buffer* pVertexBuffer_;
	ID3D11Buffer* pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;	

	Texture* pTexture_;
public:
	Quad();
	~Quad();
	HRESULT Initialize();
	void Draw();
	void Draw(XMMATRIX& worldMatrix);
	void Release();


};