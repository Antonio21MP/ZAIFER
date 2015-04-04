#include "Meteor.h"

Meteor::Meteor()
{
    al_init_image_addon();
    enemy_image.push_back(al_load_bitmap("meteor01.png"));
    enemy_image.push_back(al_load_bitmap("meteor02.png"));
    enemy_image.push_back(al_load_bitmap("meteor03.png"));
    enemy_image.push_back(al_load_bitmap("meteor04.png"));
    enemy_image.push_back(al_load_bitmap("meteor01.png"));

    enemy_imageI.push_back(al_load_bitmap("meteorI01.png"));
    enemy_imageI.push_back(al_load_bitmap("meteorI02.png"));
    enemy_imageI.push_back(al_load_bitmap("meteorI03.png"));
    enemy_imageI.push_back(al_load_bitmap("meteorI04.png"));
    enemy_imageI.push_back(al_load_bitmap("meteorI01.png"));

    enemy_imageD.push_back(al_load_bitmap("meteorD01.png"));
    enemy_imageD.push_back(al_load_bitmap("meteorD02.png"));
    enemy_imageD.push_back(al_load_bitmap("meteorD03.png"));
    enemy_imageD.push_back(al_load_bitmap("meteorD04.png"));
    enemy_imageD.push_back(al_load_bitmap("meteorD01.png"));
}
void Meteor::act(int frame, int velocidad){

    if(frame%10==0){
            if(sprite_enemy<4){
                sprite_enemy++;
            }else{
                sprite_enemy = 0;
            }
            direc_y +=velocidad;
        }
        al_draw_bitmap(enemy_image[sprite_enemy], direc_x, direc_y, 0);
        direc_h = al_get_bitmap_height(enemy_image[sprite_enemy])-5;
        direc_w = al_get_bitmap_width(enemy_image[sprite_enemy])-8;

}
void Meteor::act2(int frame, int velocidad){
    if(frame%10==0){
            if(sprite_enemy<3){
                sprite_enemy++;
            }else{
                sprite_enemy = 0;
            }
            direc_x +=velocidad;
        }

        al_draw_bitmap(enemy_imageD[sprite_enemy], direc_x, direc_y, 0);
        direc_h = al_get_bitmap_height(enemy_imageD[sprite_enemy])-8;
        direc_w = al_get_bitmap_width(enemy_imageD[sprite_enemy])-5;
}

void Meteor::act3(int frame, int velocidad){
    if(frame%10==0){
            if(sprite_enemy<3){
                sprite_enemy++;
            }else{
                sprite_enemy = 0;
            }
            direc_x -=velocidad;
        }
        al_draw_bitmap(enemy_imageI[sprite_enemy], direc_x, direc_y, 0);
        direc_h = al_get_bitmap_height(enemy_imageI[sprite_enemy])-8;
        direc_w = al_get_bitmap_width(enemy_imageI[sprite_enemy])-5;
}

void Meteor::destroy_all(){
    for(int i=0; i<enemy_image.size(); i++){
        al_destroy_bitmap(enemy_image[i]);
        al_destroy_bitmap(enemy_imageD[i]);
        al_destroy_bitmap(enemy_imageI[i]);

    }
}
Meteor::~Meteor()
{
    //dtor
}
