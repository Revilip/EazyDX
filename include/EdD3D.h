#ifndef EDD3D_H
#define EDD3D_H
#include <d3dx9.h>

class EdD3D
{
    public:
        EdD3D();
        virtual ~EdD3D();
        static void SetD3DDevice(LPDIRECT3DDEVICE9);

    protected:
        static LPDIRECT3DDEVICE9 static_pd3dDevice;

    private:
};

#endif // EDD3D_H
