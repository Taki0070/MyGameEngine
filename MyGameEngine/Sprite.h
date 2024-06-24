#pragma once
#include "Direct3D.h"
#include <DirectXMath.h>
#include "Texture.h"
#include"vector"
using std::vector;
using namespace DirectX;

	//コンスタントバッファー:アプリ側からシェーダーに毎フレーム渡したい情報
struct CONSTANT_BUFFER
{
	XMMATRIX	matW;
};

//XMFLOAT3でもよい。
//頂点情報
struct VERTEX
{
		XMVECTOR position;
		XMVECTOR uv;
		
};

class Sprite
{
	uint64_t vertexNum_;             //頂点数　多くて六つ
	vector<VERTEX> vertices_;        //頂点情報
	uint64_t indexNum_;             //インデックス数
	vector<int>indices_;            // インデックス情報

	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
	ID3D11Buffer* pIndexBuffer_;    //インデックスバッファ
	ID3D11Buffer* pConstantBuffer_;	//コンスタントバッファ

	Texture* pTexture_;//テクスチャ へのポインタ
public:
	Sprite();//コンスト
	~Sprite();//デススト
	HRESULT Initialize();//初期化用　コンストラクタできない奴はこっちで初期化
	void Draw(XMMATRIX& worldMatrix);//描画関数
	void Release();//解放
private:
	//--- Initializeから呼ばれる
	void InitVertexData();//頂点情報の準備
	HRESULT CreateVertexBuffer();//頂点バッファを作成

	void InitIndexData();//インデックス情報を準備
	HRESULT CreateIndexBuffer();//インデックスバッファー作成

	HRESULT CreateConstantBuffer();//コンストバッファー作成
	HRESULT LoadTexture();//テクスチャロード

	//---Draw関数から呼ばれる関数---
	void PassDataToCB(DirectX::XMMATRIX& worldMatrix);//コンストバッファ各種
	void SetBufferToPipeline();//各バッファをパオるライン
};


