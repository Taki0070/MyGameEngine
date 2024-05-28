#pragma once
#include <d3d11.h>
#include "Quad.h"
//�����J
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
//�ϐ�
//namespace Direct3D
//{
//	ID3D11Device* pDevice = nullptr;		//�f�o�C�X
//	ID3D11DeviceContext* pContext = nullptr;		//�f�o�C�X�R���e�L�X�g
//	IDXGISwapChain* pSwapChain = nullptr;		//�X���b�v�`�F�C��
//	ID3D11RenderTargetView* pRenderTargetView = nullptr;	//�����_�[�^�[�Q�b�g�r���[
//
//	ID3D11VertexShader* pVertexShader = nullptr;	//���_�V�F�[�_�[
//	ID3D11PixelShader* pPixelShader = nullptr;		//�s�N�Z���V�F�[�_�[
//	ID3D11InputLayout* pVertexLayout = nullptr;	//���_�C���v�b�g���C�A�E�g
//	ID3D11RasterizerState* pRasterizerState = nullptr;	//���X�^���C�U�[
//
//	//   ID3D11Device* pDevice;		                   //�f�o�C�X
//	   //ID3D11DeviceContext* pContext;                //�f�o�C�X�R���e�L�X�g
//	   //IDXGISwapChain* pSwapChain;                  //�X���b�v�`�F�C��
//	   //ID3D11RenderTargetView* pRenderTargetView;	//�����_�[�^�[�Q�b�g�r���[
//
//	
//
//}
namespace Direct3D
{
	
	extern ID3D11Device* pDevice;
	extern ID3D11DeviceContext* pContext;
	//������
	void Initialize(int winW, int winH, HWND hWnd);

	//�V�F�[�_�[����
	void InitShader();

	//�`��J�n
	void BeginDraw();

	//�`��I��
	void EndDraw();

	//���
	void Release();


};

