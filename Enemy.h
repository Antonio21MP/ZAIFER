#ifndef ENEMY_H
#define ENEMY_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <vector>
using namespace std;
class Enemy
{
    public:
        vector <ALLEGRO_BITMAP*> enemy_image;
        int direc_y = -45, direc_x = 500, direc_w = 0, direc_h = 0;
        int frame = 0, sprite_enemy = 0;
        int redraw = 1;
        Enemy();
        virtual void act(int frame, int velocidad)=0;
        virtual void destroy_all()=0;
        virtual ~Enemy();
};

#endif // enemy_image_H
