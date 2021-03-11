#include "EdD3D.h"

LPDIRECT3DDEVICE9 EdD3D::static_pd3dDevice=NULL;

EdD3D::EdD3D()
{
    //ctor
}

EdD3D::~EdD3D()
{
    //dtor
}

void EdD3D::SetD3DDevice(LPDIRECT3DDEVICE9 pd3ddevice)
{
    static_pd3dDevice = pd3ddevice;
}
