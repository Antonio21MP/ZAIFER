#ifndef ALIENINVERT_H
#define ALIENINVERT_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <vector>
#include "Enemy.h"

class AlienInvert : public Enemy
{
    public:
        AlienInvert();
        void act(int frame, int velocidad);
        void destroy_all();
        virtual ~AlienInvert();
};

#endif // ALIENINVERT_H
