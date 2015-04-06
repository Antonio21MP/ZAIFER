//Copyright (C) 2015 Jose Antonio Mejia (Jose34mp).
//This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

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
