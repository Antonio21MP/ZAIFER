#ifndef ANIMAL_H
#define ANIMAL_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <vector>
#include "Enemy.h"

class Animal : public Enemy
{
    public:
        Animal();
        void act(int frame, int velocidad);
        void act2(int frame, int velocidad);
        void destroy_all();
        virtual ~Animal();
};

#endif // ANIMAL_H
