#include"Model.h"
#include"Engine/Direct3D.h"



namespace Model
{
	std::vector<ModelData*>modelList;
}

int Model::Load(std::string filename)
{
	ModelData* pData = new ModelData;//消えてもしくないものを new する　、あとで自分で消さなければならぬ
	pData->filename_ = filename;
	pData->pFbx_ = nullptr;//読み込み解消

	for (auto& e : modelList)//
	{
		if (e->filename_ == filename){//読み込み済み
			pData->pFbx_ = e->pFbx_;//同じFBXにいれる
			break;//同名のファイルが読み込み済み
		}
	}
	if (pData->pFbx_ == nullptr)//同名のファイルはリストリストになし
	{
		pData->pFbx_ = new FBX;
		pData->pFbx_->Load(filename);
	}
	modelList.push_back(pData);
	return (modelList.size() - 1);//最後〜

}

void Model::SetTransform(int hModel, Transform transform)
{
	modelList[hModel]->transform_ = transform;

}

void Model::Draw(int hModel)
{
	modelList[hModel]->pFbx_->Draw(modelList[hModel]->transform_);
}

void Model::Release()
{
	bool isReferred = false;
	for (int j = 0; j < modelList.size(); j++)
	{
		for (int i = j +1 ;i < modelList.size(); i++)
		{
			if (modelList[j]->pFbx_ == modelList[i]->pFbx_)
			{
				isReferred = true;
				break;
			}
		}
		if (isReferred == false)
		{
			SAFE_DELETE(modelList[j]->pFbx_);
		}
		SAFE_DELETE(modelList[j]);
	}
	modelList.clear();

}
