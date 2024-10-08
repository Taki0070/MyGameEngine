#include "Input.h"
#include "Transform.h"



namespace Input
{
	LPDIRECTINPUT8   pDInput = nullptr;
	LPDIRECTINPUTDEVICE8 pKeyDevice = nullptr;
	BYTE keyState[256] = { 0 };
	BYTE prevKeyState[256];    //前フレームでの各キーの状態
	XMFLOAT3 mousePosition;


	//マウス
	LPDIRECTINPUTDEVICE8 pMouseDevice_;	
	DIMOUSESTATE mouseState_;				
	DIMOUSESTATE prevMouseState_;			
	POINT mousePos_;

	void Initialize(HWND hWnd)
	{
		DirectInput8Create(GetModuleHandle(nullptr),
			DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&pDInput, nullptr);

		pDInput->CreateDevice(GUID_SysKeyboard, &pKeyDevice, nullptr);
		pKeyDevice->SetDataFormat(&c_dfDIKeyboard);//これはキーボードと示している
		pKeyDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);//優先度 (、裏に行ってても動く)


		//マウス
		pDInput->CreateDevice(GUID_SysMouse, &pMouseDevice_, nullptr);
		pMouseDevice_->SetDataFormat(&c_dfDIMouse);
		pMouseDevice_->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	}

	void Update()
	{
		memcpy(prevKeyState, keyState,sizeof(keyState));
	
		pKeyDevice->Acquire();//マナー書くことが
		pKeyDevice->GetDeviceState(sizeof(keyState), &keyState);//これを読んだ瞬間　その時の配列が入る
	
		pMouseDevice_->Acquire();
		memcpy(&prevMouseState_, &mouseState_, sizeof(mouseState_));
		pMouseDevice_->GetDeviceState(sizeof(mouseState_), &mouseState_);
	
	}

	bool IsKey(int keyCode)
	{
		// 8bit は　[1000 0000]は128
		if (keyState[keyCode] && 128 )// あるかないか調べる時　bitの&計算 計算したい奴と元のやつ //&はどちらとも　1　の場合 1を出力
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
		//今は押してて、前回は押してない
		if (IsKey(keyCode)&& !(prevKeyState)[keyCode] &128)
		{
			return true;
		}
		return false;
	}
	
	
	bool IsMouseButton(int buttonCode)
	{
		//押してる
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