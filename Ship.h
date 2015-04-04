#ifndef SHIP_H
#define SHIP_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>
#include <vector>
using namespace std;

enum GAME_KEYS{
        KEY_LEFT,
        KEY_RIGHT,
        KEY_UP,
        KEY_DOWN,
        KEY_SPACE,
        KEY_ESC
};

class Ship
{
    public:
        int key[6] = { 0, 0, 0, 0, 0, 0 };
        //ALLEGRO_TIMER * timer;
        vector <ALLEGRO_BITMAP*> neutral_ship;
        vector<ALLEGRO_BITMAP*> right_ship;
        vector<ALLEGRO_BITMAP*> left_ship;
        vector<ALLEGRO_BITMAP*> explosion;
        //ALLEGRO_SAMPLE *audio=NULL;
        int direc_y = 600, direc_x = 500, direc_y_shut = 0, direc_x_shut = 0, dire_w = 0, dire_h = 0;
        int sprite_neutral= 0, sprite_rigth = 0, sprite_left = 0, sprite_explo = 0;
        bool presion_R = false, presion_L = false, shut = false, esc = false, colisionado = false;
        Ship(ALLEGRO_EVENT_QUEUE *event_queue);
        void act(ALLEGRO_EVENT *event, int frame);
        void draw();
        void destroy_ship();
        void destroy_all();
        bool collision(int eneX, int eneY, int eneW, int eneH);
        virtual ~Ship();

};

#endif // SHIP_H
