#pragma once
#include"mftransform.h"
#include<string>
#include"Engine/FBX.h"


namespace Model
{ 
	struct ModelData//どこからでも見れる
	{
		FBX* pFbx_;
		Transform transform_;
		std::string filename_;
		ModelData()
			: pFbx_(nullptr), filename_("") {};//初期化
	};
	//モデルを一覧を保存する配列(ヴェく、リスト)
	int Load(std::string filename);
	void SetTransform(int hModel,Transform transform);
	void Draw(int hModel);
	void Release();

}

