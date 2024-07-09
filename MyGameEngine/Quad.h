#pragma once
#include "Direct3D.h"
#include <DirectXMath.h>
#include "Texture.h"
#include<vector>
#include"Transform.h"

using namespace DirectX;

//コンスタントバッファー:　アプリ側から、シェーダーに毎フレーム渡したい情報
struct CONSTANT_BUFFER
{	
	XMMATRIX	matWVP;
	XMMATRIX	matW;
};

//XMFLOAT3でもよい。
//頂点情報
struct VERTEX
{
	XMVECTOR position;
	XMVECTOR uv;
	XMVECTOR normal; //ノーマル追加（法線ベクトル）
};

class Quad
{
protected:
	int vertexNum_;
	std::vector<VERTEX>vertices_;
	int indexNum_;
	std::vector<int>index_;

	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
	ID3D11Buffer* pIndexBuffer_;    //インデックスバッファ
	ID3D11Buffer* pConstantBuffer_;	//コンスタントバッファ

	Texture* pTexture_;
public:
	Quad();
	virtual ~Quad();
	virtual HRESULT Initialize();
	//void Draw();
	virtual void Draw(Transform& transform);
	//virtual void Draw(XMMATRIX& worldMatrix);
	void Release();

private:
	virtual void InitVertexData();
	HRESULT CreateVertexBuffer();
	virtual void InitIndexData();
	HRESULT CreateIndexBuffer();//インデックスバッファー作成
	HRESULT CreateConstantBuffer();//コンストバッファー作成
	HRESULT LoadTexture();//テクスチャロード

	//---Draw関数から呼ばれる関数---
	void PassDataToCB(Transform& transform);//コンストバッファ各種
	//void PassDataToCB(XMMATRIX worldMatrix);//コンストバッファ各種
	void SetBufferToPipeline();//各バッファをパオるライン
};