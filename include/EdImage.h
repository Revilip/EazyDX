#ifndef EDIMAGE_H
#define EDIMAGE_H
#include <d3dx9.h>
#include "eddef.h"
#include "EdTools.h"
#include "EdRect.h"
#include "EdD3D.h"

typedef LPDIRECT3DTEXTURE9 EdTexImage;

class EdImage : public EdD3D
{
    public:
        EdString m_src;
        EdRect    m_src_rect;
        EdImage();
        EdImage(const EdImage& img);
        EdImage& operator=(const EdImage& img);
        EdTexImage GetTexture();

        static EdImage FromFile(EdString filename,const EdRect& rect,int imgw,int imgh);
        static EdMap<EdString,EdTexImage> static_tex_map;
        static void ResetList();

        virtual ~EdImage();

    protected:

    private:

};

#endif // EDIMAGE_H
