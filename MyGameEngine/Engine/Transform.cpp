#include "Transform.h"

Transform::Transform()
    :position_({ 0,0,0 }), rotate_({ 0,0,0 }), scale_({ 1,1,1 })
    , matTranslate_(XMMatrixIdentity()),
    matRotate_(XMMatrixIdentity()),
    matScale_(XMMatrixIdentity()),
    pParent_(nullptr)
{
   
}

Transform::~Transform()
{
}

void Transform::Calculation()
{
    //移動行列
    matTranslate_ = XMMatrixTranslation(position_.x, position_.y, position_.z);

    //回転行列作成
    XMMATRIX rx = XMMatrixRotationX(XMConvertToRadians(rotate_.x));
    XMMATRIX ry = XMMatrixRotationY(XMConvertToRadians(rotate_.y));
    XMMATRIX rz = XMMatrixRotationZ(XMConvertToRadians(rotate_.z));
    matRotate_ = rz * rx * ry;

    //拡大行列
    matScale_ = XMMatrixScaling(scale_.x, scale_.y, scale_.z);
}

XMMATRIX Transform::GetWorldMatrix()
{
    if (pParent_ != nullptr)
    {
        return matScale_ * matRotate_ * matTranslate_ ;// DirectX11 では S→R→T (スケール、ローテ、トランス)

    }
    else {//親がいないときは
        return matScale_ * matRotate_ * matTranslate_;
    }
}

XMMATRIX Transform::GetNormalMatrix()
{

    //平行移動は無視　回転がかける、スケールは元に戻す
   return(matRotate_ * XMMatrixInverse(nullptr, matScale_));
}
