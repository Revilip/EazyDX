#include <eazydx.h>
#include <EdMapSprite.h>

EdSprite* sp;
EdMapSprite* map_sp;

void mRender()
{
    sp->Render();
    map_sp->Render();
}

void OtherProc(HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam)
{

}

INT WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,INT)
{
    if(EdInitialize()){
        EdRect rt = EdRect{0,0,333,355};

        sp = new EdSprite();
        sp->m_img = EdImage::FromFile("test.png",rt,333,355);
        sp->x = 100.0f;
        sp->y = 200.0f;

        rt = EdRect{70,50,70+32,50+32};//SIZE OF THE MINIMUM UNIT, NOT THE WHOLE IMAGE!!!!!!!!!

        map_sp = new EdMapSprite(3,2);
        map_sp->m_img = EdImage::FromFile("test_tile.png",rt,333,355);
        map_sp->x = 50.0f;
        map_sp->SetData(0,0,0,0);
        map_sp->SetData(1,0,1,1);
        map_sp->SetData(2,0,2,2);
        map_sp->SetData(0,1,1,0);
        map_sp->SetData(1,1,0,2);
        map_sp->SetData(2,1,0,1);

        EdSetRenderFunction(mRender);
        EdMainLoop();
        delete sp;
        delete map_sp;
    }
    return 0;
}

