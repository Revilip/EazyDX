#ifndef EDSPRITE_H
#define EDSPRITE_H

#include <d3dx9.h>
#include "eddef.h"
#include "EdImage.h"
#include "EdD3D.h"

class EdSprite : public EdD3D
{
    public:
        EdImage m_img;
        float x,y;
        LPD3DXSPRITE m_dxsprite;
        EdSprite();
        virtual ~EdSprite();
        virtual void Render();

    protected:

    private:
};

#endif // EDSPRITE_H
