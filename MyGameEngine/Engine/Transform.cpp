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
    //�ړ��s��
    matTranslate_ = XMMatrixTranslation(position_.x, position_.y, position_.z);

    //��]�s��쐬
    XMMATRIX rx = XMMatrixRotationX(XMConvertToRadians(rotate_.x));
    XMMATRIX ry = XMMatrixRotationY(XMConvertToRadians(rotate_.y));
    XMMATRIX rz = XMMatrixRotationZ(XMConvertToRadians(rotate_.z));
    matRotate_ = rz * rx * ry;

    //�g��s��
    matScale_ = XMMatrixScaling(scale_.x, scale_.y, scale_.z);
}

XMMATRIX Transform::GetWorldMatrix()
{
    if (pParent_ != nullptr)
    {
        return matScale_ * matRotate_ * matTranslate_ ;// DirectX11 �ł� S��R��T (�X�P�[���A���[�e�A�g�����X)

    }
    else {//�e�����Ȃ��Ƃ���
        return matScale_ * matRotate_ * matTranslate_;
    }
}

XMMATRIX Transform::GetNormalMatrix()
{

    //���s�ړ��͖����@��]��������A�X�P�[���͌��ɖ߂�
   return(matRotate_ * XMMatrixInverse(nullptr, matScale_));
}
