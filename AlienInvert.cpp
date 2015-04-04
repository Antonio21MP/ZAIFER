#include "AlienInvert.h"

AlienInvert::AlienInvert()
{
    al_init_image_addon();
    enemy_image.push_back(al_load_bitmap("alienX_01.png"));
    enemy_image.push_back(al_load_bitmap("alienX_02.png"));
    enemy_image.push_back(al_load_bitmap("alienX_01.png"));
}

void AlienInvert::act(int frame, int velocidad)
{
    if(frame%10==0){
            if(sprite_enemy<2){
                sprite_enemy++;
            }else{
                sprite_enemy = 0;
            }
            direc_y -=velocidad;

        }
        al_draw_bitmap(enemy_image[sprite_enemy], direc_x, direc_y, 0);
        direc_h = al_get_bitmap_height(enemy_image[sprite_enemy])-8;
        direc_w = al_get_bitmap_width(enemy_image[sprite_enemy])-8;

}
void AlienInvert::destroy_all()
{
    for(int i=0; i<enemy_image.size(); i++)
        al_destroy_bitmap(enemy_image[i]);

}
AlienInvert::~AlienInvert()
{
    //dtor
}
