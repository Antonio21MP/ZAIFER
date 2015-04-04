#ifndef METEOR_H
#define METEOR_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <vector>
#include "Enemy.h"

class Meteor : public Enemy
{
    public:
        vector<ALLEGRO_BITMAP*> enemy_imageI;
        vector<ALLEGRO_BITMAP*> enemy_imageD;
        int sprite = 0;
        Meteor();
        virtual ~Meteor();
    void act(int frame, int velocidad);
    void act2(int frame, int velocidad);
    void act3(int frame, int velocidad);
    void destroy_all();
};

#endif // METEOR_H
