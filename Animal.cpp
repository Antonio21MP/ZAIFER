#include "Animal.h"

Animal::Animal()
{
    al_init_image_addon();
    enemy_image.push_back(al_load_bitmap("select0.png"));
    enemy_image.push_back(al_load_bitmap("select1.png"));
    enemy_image.push_back(al_load_bitmap("select2.png"));
    enemy_image.push_back(al_load_bitmap("select0.png"));
}
void Animal::act(int frame, int velocidad)
{
    if(frame%10==0){
            if(sprite_enemy<3){
                sprite_enemy++;
            }else{
                sprite_enemy = 0;
            }
            direc_y +=velocidad;
            direc_x +=velocidad;
        }
        al_draw_bitmap(enemy_image[sprite_enemy], direc_x, direc_y, 0);
        direc_h = al_get_bitmap_height(enemy_image[sprite_enemy])-8;
        direc_w = al_get_bitmap_width(enemy_image[sprite_enemy])-8;

}
void Animal::act2(int frame, int velocidad)
{
    if(frame%10==0){
            if(sprite_enemy<3){
                sprite_enemy++;
            }else{
                sprite_enemy = 0;
            }
            direc_y +=velocidad;
            direc_x -=velocidad;
        }
        al_draw_bitmap(enemy_image[sprite_enemy], direc_x, direc_y, 0);
        direc_h = al_get_bitmap_height(enemy_image[sprite_enemy])-8;
        direc_w = al_get_bitmap_width(enemy_image[sprite_enemy])-8;

}

void Animal::destroy_all()
{
    for(int i=0; i<enemy_image.size(); i++)
        al_destroy_bitmap(enemy_image[i]);

}

Animal::~Animal()
{
    //dtor
}
