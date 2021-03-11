#include "EdMapSprite.h"

EdMapSprite::EdMapSprite()
{
    map_w = 0;
    map_h = 0;
    map_data = NULL;
    //ctor
}

EdMapSprite::EdMapSprite(int _w,int _h)
{
    map_w = _w;
    map_h = _h;
    map_data  = new map_src_position{_w*_h};
}

EdMapSprite::~EdMapSprite()
{
    if(NULL!=map_data)
        delete map_data;
    //dtor
}

void EdMapSprite::Render()
{
    if(map_data==NULL)
        return;
    m_dxsprite->Begin(D3DXSPRITE_ALPHABLEND);
    D3DXVECTOR3 v={x,y,0.0f};
    int w=m_img.m_src_rect.right-m_img.m_src_rect.left;
    int h=m_img.m_src_rect.bottom-m_img.m_src_rect.top;
    EdRect rt;
    int n=map_w*map_h;
    for(int i=0;i<map_w;++i){
        for(int j=0;j<map_h;++j)
        {
            v.x = x+i*w;
            v.y = y+j*h;
            map_src_position p=GetData(i,j);
            rt.left = m_img.m_src_rect.left+ w*p.x;
            rt.top = m_img.m_src_rect.top + h*p.y;
            rt.bottom = m_img.m_src_rect.bottom + h*p.y;
            rt.right = m_img.m_src_rect.right + w*p.x;
            m_dxsprite->Draw(m_img.GetTexture(),&rt,NULL,&v,0xffffffff);
        }
    }
    m_dxsprite->End();
}

EdMapSprite::map_src_position EdMapSprite::GetData(int _x,int _y)
{
    if(_x<0||_y<0||_x>=map_w||_y>=map_h)
        return map_src_position{0,0};
    return map_data[_y*map_w+_x];
}

void EdMapSprite::SetData(int _x,int _y,int x_in_image,int y_in_image)
{
    if(_x<0||_y<0||_x>=map_w||_y>=map_h)
        return;
    map_data[_y*map_w+_x]=map_src_position{x_in_image,y_in_image};
}
