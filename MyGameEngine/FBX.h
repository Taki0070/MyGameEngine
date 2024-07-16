#pragma once
#include "Direct3D.h"
#include <fbxsdk.h>
#include <DirectXMath.h>
#include "Texture.h"
#include "Transform.h"
#include <vector>
#include <filesystem>

//#pragma comment(lib, "LibFbxSDK-MD.lib")
#pragma comment(lib, "LibFbxSDK-MD.lib")
#pragma comment(lib, "LibXml2-MD.lib")
#pragma comment(lib, "zlib-MD.lib")

class FBX
{
	struct CONSTANT_BUFFER
	{
		XMMATRIX	matWVP; //���[���h�r���[�v���W�F�N�V����
		XMMATRIX	matNormal;   //�@���x�N�g���̕ϊ��p
	};

	//���_���
	struct VERTEX
	{
		XMVECTOR position;
		//XMVECTOR uv;
		//XMVECTOR normal; //�m�[�}���ǉ��i�@���x�N�g���j
	};

	ID3D11Buffer* pVertexBuffer_; //���_�o�b�t�@�p������ 
	ID3D11Buffer* pIndexBuffer_; //�C���f�b�N�X�o�b�t�@�p������
	ID3D11Buffer* pConstantBuffer_; //�R���X�^���g�o�b�t�@�p������
	int vertexCount_;	//���_��
	int polygonCount_;	//�|���S����

	void InitVertex(fbxsdk::FbxMesh* mesh);
	void InitIndex(fbxsdk::FbxMesh* mesh);
	void InitConstantBuffer();
public:
	FBX();
	HRESULT Load(std::string fileName);
	void    Draw(Transform& transform);
	void    Release();
};