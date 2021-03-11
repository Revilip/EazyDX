#include "EdImage.h"

EdMap<EdString,EdTexImage> EdImage::static_tex_map;

EdImage::EdImage()
{
    //ctor
}

EdImage::~EdImage()
{
    //dtor
}

EdImage::EdImage(const EdImage& img)
{
    m_src = img.m_src;
    m_src_rect = img.m_src_rect;
}

EdImage& EdImage::operator=(const EdImage& img)
{
    m_src = img.m_src;
    m_src_rect = img.m_src_rect;
    return *this;
}

EdImage EdImage::FromFile(EdString filename,const EdRect& rect,int imgw,int imgh)
{
        LPDIRECT3DTEXTURE9 tex;
        EdMap<EdString,EdTexImage>::iterator iter = static_tex_map.find(filename);
        if(iter == static_tex_map.end())
        {
                D3DXCreateTextureFromFileEx(static_pd3dDevice,filename.c_str(),imgw,imgh,0,0,D3DFMT_UNKNOWN,D3DPOOL_MANAGED,D3DX_FILTER_NONE,D3DX_FILTER_NONE,NULL,NULL,NULL,&tex);
                static_tex_map.insert(EdMap<EdString,EdTexImage>::value_type(filename,tex));
        }
        EdImage img;
        img.m_src = filename;
        img.m_src_rect = rect;
        return img;
}

EdTexImage EdImage::GetTexture()
{
    EdMap<EdString,EdTexImage>::iterator iter = static_tex_map.find(m_src);
    if(iter!=static_tex_map.end())
    {
        return iter->second;
    }
    return NULL;
}

void EdImage::ResetList()
{
    for(EdMap<EdString,EdTexImage>::iterator iter = static_tex_map.begin();iter!=static_tex_map.end();++iter)
    {
        ED_SAFE_RELEASE(iter->second);
    }
}
