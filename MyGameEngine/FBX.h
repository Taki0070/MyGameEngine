#pragma once
#include "Direct3D.h"
#include<fbxsdk.h>
#include <DirectXMath.h>
#include "Texture.h"
#include<vector>
#include"Transform.h"
#include<filesystem>

//#pragma comment(lib, "LibFbxSDK-MD.lib") ←エラーがでたら
#pragma comment(lib, "LibFbxSDK-MD.lib")
#pragma comment(lib, "LibXml2-MD.lib")
#pragma comment(lib, "zlib-MD.lib")

using namespace DirectX;

class FBX
{
	

	//コンスタントバッファー:　アプリ側から、シェーダーに毎フレーム渡したい情報
	struct CONSTANT_BUFFER
	{
		XMMATRIX	matWVP;
		XMMATRIX	matW;
	};

	//頂点情報
	struct VERTEX
	{
		XMVECTOR position;
	/*	XMVECTOR uv;
		XMVECTOR normal;*/ //ノーマル追加（法線ベクトル）
	};

	int vertexNum_;
	std::vector<VERTEX>vertices_;
	int indexNum_;
	std::vector<int>index_;


	ID3D11Buffer* pVertexBuffer_;//頂点バッファー用メモリ
	ID3D11Buffer* pIndexBuffer_;//インデックスバッファ用メモリ
	ID3D11Buffer* pConstantBuffer_;//コンスタントバッファ用メモリ

	int vertexCount_;	//頂点数
	int polygonCount_;	//ポリゴン数


	HRESULT InitVertex(fbxsdk::FbxMesh* mesh);
	HRESULT InitIndex(fbxsdk::FbxMesh* mesh);
	HRESULT InitConstantBuffer();

public:
	FBX();
	HRESULT Load(std::string fileName);
	void    Draw(Transform& transform);
	void    Release();
};

