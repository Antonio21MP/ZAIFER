#ifndef ALIEN_H
#define ALIEN_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <vector>
#include "Enemy.h"

class Alien : public Enemy
{
    public:
        Alien();
        void act(int frame, int velocidad);
        void destroy_all();
        virtual ~Alien();
};

#endif // ALIEN_H
