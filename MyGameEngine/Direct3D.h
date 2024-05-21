#pragma once
#include <d3d11.h>

//�����J
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

namespace Direct3D
{
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

