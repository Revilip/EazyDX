#ifndef EDMAPSPRITE_H
#define EDMAPSPRITE_H

#include "EdSprite.h"

class EdMapSprite : public EdSprite
{
    public:
        int map_w;
        int map_h;
        typedef struct
        {
            int x;
            int y;
        }map_src_position;
        map_src_position* map_data;

        map_src_position GetData(int,int);
        void SetData(int _x,int _y,int x_in_image,int y_in_image);

        EdMapSprite();
        EdMapSprite(int _w,int _h);
        virtual ~EdMapSprite();
        virtual void Render();

    protected:

    private:
};

#endif // EDMAPSPRITE_H
