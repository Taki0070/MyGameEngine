#pragma once
#include <d3d11.h>
#include "Quad.h"
//リンカ
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
//変数
//namespace Direct3D
//{
//	ID3D11Device* pDevice = nullptr;		//デバイス
//	ID3D11DeviceContext* pContext = nullptr;		//デバイスコンテキスト
//	IDXGISwapChain* pSwapChain = nullptr;		//スワップチェイン
//	ID3D11RenderTargetView* pRenderTargetView = nullptr;	//レンダーターゲットビュー
//
//	ID3D11VertexShader* pVertexShader = nullptr;	//頂点シェーダー
//	ID3D11PixelShader* pPixelShader = nullptr;		//ピクセルシェーダー
//	ID3D11InputLayout* pVertexLayout = nullptr;	//頂点インプットレイアウト
//	ID3D11RasterizerState* pRasterizerState = nullptr;	//ラスタライザー
//
//	//   ID3D11Device* pDevice;		                   //デバイス
//	   //ID3D11DeviceContext* pContext;                //デバイスコンテキスト
//	   //IDXGISwapChain* pSwapChain;                  //スワップチェイン
//	   //ID3D11RenderTargetView* pRenderTargetView;	//レンダーターゲットビュー
//
//	
//
//}
namespace Direct3D
{
	
	extern ID3D11Device* pDevice;
	extern ID3D11DeviceContext* pContext;
	//初期化
	void Initialize(int winW, int winH, HWND hWnd);

	//シェーダー準備
	void InitShader();

	//描画開始
	void BeginDraw();

	//描画終了
	void EndDraw();

	//解放
	void Release();


};

