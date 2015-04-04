#ifndef ESHIP_H
#define ESHIP_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <vector>
#include "Enemy.h"

class EShip : public Enemy
{
    public:
        EShip();
        void act(int frame, int velocidad);
        void destroy_all();
        virtual ~EShip();
};

#endif // ESHIP_H
