#pragma once
#include <d3d11.h>

//リンカ
#pragma comment(lib, "d3d11.lib")


const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

namespace Direct3D
{
	//初期化
	void Initialize(int winW, int winH, HWND hWnd);

	//描画開始
	void BeginDraw();

	//描画終了
	void EndDraw();

	//解放
	void Release();
};

