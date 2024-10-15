#pragma once
#include"mftransform.h"
#include<string>
#include"Engine/FBX.h"


namespace Model
{ 
	struct ModelData//�ǂ�����ł������
	{
		FBX* pFbx_;
		Transform transform_;
		std::string filename_;
		ModelData()
			: pFbx_(nullptr), filename_("") {};//������
	};
	//���f�����ꗗ��ۑ�����z��(���F���A���X�g)
	int Load(std::string filename);
	void SetTransform(int hModel,Transform transform);
	void Draw(int hModel);
	void Release();

}

