#include "EdSprite.h"

EdSprite::EdSprite()
{
    if(static_pd3dDevice!=NULL)
    {
        D3DXCreateSprite(static_pd3dDevice,&m_dxsprite);
    }
    x=0.0f;
    y=0.0f;
    //ctor
}

EdSprite::~EdSprite()
{
    ED_SAFE_RELEASE(m_dxsprite);
    //dtor
}

void EdSprite::Render()
{
        m_dxsprite->Begin(D3DXSPRITE_ALPHABLEND);
        D3DXVECTOR3 v={x,y,0.0f};
        m_dxsprite->Draw(m_img.GetTexture(),&m_img.m_src_rect,NULL,&v,0xffffffff);
        m_dxsprite->End();
}
