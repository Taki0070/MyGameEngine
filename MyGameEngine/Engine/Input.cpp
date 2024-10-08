#include "Input.h"
#include "Transform.h"



namespace Input
{
	LPDIRECTINPUT8   pDInput = nullptr;
	LPDIRECTINPUTDEVICE8 pKeyDevice = nullptr;
	BYTE keyState[256] = { 0 };
	BYTE prevKeyState[256];    //�O�t���[���ł̊e�L�[�̏��
	XMFLOAT3 mousePosition;


	//�}�E�X
	LPDIRECTINPUTDEVICE8 pMouseDevice_;	
	DIMOUSESTATE mouseState_;				
	DIMOUSESTATE prevMouseState_;			
	POINT mousePos_;

	void Initialize(HWND hWnd)
	{
		DirectInput8Create(GetModuleHandle(nullptr),
			DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&pDInput, nullptr);

		pDInput->CreateDevice(GUID_SysKeyboard, &pKeyDevice, nullptr);
		pKeyDevice->SetDataFormat(&c_dfDIKeyboard);//����̓L�[�{�[�h�Ǝ����Ă���
		pKeyDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);//�D��x (�A���ɍs���ĂĂ�����)


		//�}�E�X
		pDInput->CreateDevice(GUID_SysMouse, &pMouseDevice_, nullptr);
		pMouseDevice_->SetDataFormat(&c_dfDIMouse);
		pMouseDevice_->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	}

	void Update()
	{
		memcpy(prevKeyState, keyState,sizeof(keyState));
	
		pKeyDevice->Acquire();//�}�i�[�������Ƃ�
		pKeyDevice->GetDeviceState(sizeof(keyState), &keyState);//�����ǂ񂾏u�ԁ@���̎��̔z�񂪓���
	
		pMouseDevice_->Acquire();
		memcpy(&prevMouseState_, &mouseState_, sizeof(mouseState_));
		pMouseDevice_->GetDeviceState(sizeof(mouseState_), &mouseState_);
	
	}

	bool IsKey(int keyCode)
	{
		// 8bit �́@[1000 0000]��128
		if (keyState[keyCode] && 128 )// ���邩�Ȃ������ׂ鎞�@bit��&�v�Z �v�Z�������z�ƌ��̂�� //&�͂ǂ���Ƃ��@1�@�̏ꍇ 1���o��
		{
			return true;
		}
		return false;
	}
	bool IsKeyUp(int keyCode)
	{
		if (IsKey(keyCode) && (prevKeyState)[keyCode] & 128)
		{
			return true;
		}
		return false;
	}
	bool IsKeyDown(int keyCode)
	{
		//���͉����ĂāA�O��͉����ĂȂ�
		if (IsKey(keyCode)&& !(prevKeyState)[keyCode] &128)
		{
			return true;
		}
		return false;
	}
	
	
	bool IsMouseButton(int buttonCode)
	{
		//�����Ă�
		if (mouseState_.rgbButtons[buttonCode] & 0x80)
		{
			return true;
		}
		return false;
	}

	bool IsMouseButtonDown(int buttonCode)
	{
		
		
		if (IsMouseButton(buttonCode) && !(prevMouseState_.rgbButtons[buttonCode] & 0x80))
		{
			return true;
		}
		return false;
	}


	bool IsMouseButtonUp(int buttonCode)
	{
		
		if (!IsMouseButton(buttonCode) && prevMouseState_.rgbButtons[buttonCode] & 0x80)
		{
			return true;
		}
		return false;
	}
	

	//XMFLOAT3 GetMousePosition()
	//{
	//	XMFLOAT3 result = XMFLOAT3((float)mousePos_.x, (float)mousePos_.y, 0);
	//	return result;
	//}

	void SetMousePosition(int x, int y)
	{
		mousePos_.x = x;
		mousePos_.y = y;
	}


	void Release()
	{
		SAFE_RELEASE(pDInput);
		SAFE_RELEASE(pKeyDevice);
		SAFE_RELEASE(pMouseDevice_);
	}
}