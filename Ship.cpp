#include "Ship.h"

Ship::Ship(ALLEGRO_EVENT_QUEUE *event_queue)
{
    al_init_image_addon();
//    al_install_audio();
//    al_init_acodec_addon();
//    al_reserve_samples(1);
    al_install_keyboard();
    //timer = al_create_timer(1.0/50.0);

    neutral_ship.push_back(al_load_bitmap("ship0.png"));
    neutral_ship.push_back(al_load_bitmap("ship1.png"));
    neutral_ship.push_back(al_load_bitmap("ship2.png"));
    neutral_ship.push_back(al_load_bitmap("ship3.png"));
    //VECTOR SPRITES DERECHA
    right_ship.push_back(al_load_bitmap("shipR0.png"));
    right_ship.push_back(al_load_bitmap("shipR1.png"));
    right_ship.push_back(al_load_bitmap("shipR2.png"));
    right_ship.push_back(al_load_bitmap("shipR3.png"));
    //VECTOR SPRITES IZQUIERDA
    left_ship.push_back(al_load_bitmap("shipL0.png"));
    left_ship.push_back(al_load_bitmap("shipL1.png"));
    left_ship.push_back(al_load_bitmap("shipL2.png"));
    left_ship.push_back(al_load_bitmap("shipL3.png"));

    explosion.push_back(al_load_bitmap("exp01.png"));
    explosion.push_back(al_load_bitmap("exp07.png"));
    explosion.push_back(al_load_bitmap("exp13.png"));
    explosion.push_back(al_load_bitmap("exp18.png"));
    explosion.push_back(al_load_bitmap("exp22.png"));

    //audio = al_load_sample("boom1.wav");

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    //al_register_event_source(event_queue, al_get_timer_event_source(timer));

}
void Ship::act(ALLEGRO_EVENT *event, int frame)
{
        if(!colisionado){
        if (key[KEY_LEFT])
            {
                if(direc_x>4)
                {
                    direc_x -= 4;
                }
                //cout<<direc_x<<endl;
            }

            if (key[KEY_RIGHT])
            {
                if(direc_x<928)
                {
                    direc_x += 4;
                }
                //cout<<direc_x<<endl;
            }

            if (key[KEY_UP])
            {
                if(direc_y>4)
                {
                    direc_y -= 4;
                }
                //cout<<direc_y<<endl;
            }

            if (key[KEY_DOWN])
            {
                if(direc_y<620)
                {
                    direc_y += 4;
                }
                //cout<<direc_y<<endl;
            }

            if(key[KEY_SPACE]){
            //cout<<"Space"<<endl;
            }

            if (key[KEY_ESC])
            {
                //cout<<"ESC"<<endl;
                esc = true;
            }

        if(frame%20==0)
        {
            if(presion_L == false && presion_R == true)
            {
                if(sprite_rigth<3)
                {
                    //cout<<"RIGHT"<<endl;
                    sprite_rigth++;
                    sprite_neutral = 0;
                    sprite_left = 0;
                }
                else
                {
                    //cout<<"RIGHT CONSTANTE"<<endl;
                    sprite_rigth = 2;
                }
            }

            if((presion_L == false && presion_R == false)||(presion_L == true && presion_R == true))
            {
                if(sprite_neutral<3)
                {
                    //cout<<"NEUTRAL"<<endl;
                    sprite_neutral++;
                    sprite_rigth = 0;
                    sprite_left = 0;
                }
                else
                {
                    //cout<<"NEUTRAL VUELVE A 0"<<endl;
                    sprite_neutral = 0;
                }
            }

            if(presion_L == true && presion_R == false)
            {
                if(sprite_left<3)
                {
                    //cout<<"IZQUIERDA"<<endl;
                    sprite_left++;
                    sprite_neutral = 0;
                    sprite_rigth = 0;
                }
                else
                {
                    //cout<<"IZQUIERDA CONSTANTE"<<endl;
                    sprite_left = 2;
                }
            }
        }
        }

        if (event->type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if (event->keyboard.keycode == ALLEGRO_KEY_LEFT)
            {
                key[KEY_LEFT] = 1;
                presion_L = true;
            }

            if (event->keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {
                key[KEY_RIGHT] = 1;
                presion_R = true;
            }

            if (event->keyboard.keycode == ALLEGRO_KEY_UP)
                key[KEY_UP] = 1;

            if (event->keyboard.keycode == ALLEGRO_KEY_DOWN)
                key[KEY_DOWN] = 1;

            if (event->keyboard.keycode == ALLEGRO_KEY_SPACE)
            {
                key[KEY_SPACE] = 1;
                //LUGAR DONDE EL DISPARO COPIA LA POSICION DE SHIP SOLO SI EL DISPARO
                //NO EXISTE O ESTA EN FALSE
//                if(!shut)
//                {
//                    direc_x_shut = direc_x;
//                    direc_y_shut = direc_y;
//                    shut = true;
//                }
            }
            if (event->keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                key[KEY_ESC] = 1;

        }

        //cuando las teclas estan sin precionar
        if (event->type == ALLEGRO_EVENT_KEY_UP)
        {
            if (event->keyboard.keycode == ALLEGRO_KEY_LEFT)
            {
                key[KEY_LEFT] = 0;
                presion_L = false;
            }

            if (event->keyboard.keycode == ALLEGRO_KEY_RIGHT)
            {
                key[KEY_RIGHT] = 0;
                presion_R = false;
            }

            if (event->keyboard.keycode == ALLEGRO_KEY_UP)
                key[KEY_UP] = 0;

            if (event->keyboard.keycode == ALLEGRO_KEY_DOWN)
                key[KEY_DOWN] = 0;

            if (event->keyboard.keycode == ALLEGRO_KEY_SPACE)
            {
                key[KEY_SPACE] = 0;
                //shut = false;
            }
            if (event->keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                key[KEY_ESC] = 0;

        }
    }
void Ship::draw()
{
    if(!colisionado){
    if((presion_L == false && presion_R == false)||(presion_L == true && presion_R == true))
        {
        al_draw_bitmap(neutral_ship[sprite_neutral], direc_x, direc_y, 0);
        dire_h = al_get_bitmap_height(neutral_ship[sprite_neutral])-8;
        dire_w = al_get_bitmap_width(neutral_ship[sprite_neutral])-10;
        }
    if(presion_L == false && presion_R == true)
        {
        al_draw_bitmap(right_ship[sprite_rigth], direc_x, direc_y, 0);
        dire_h = al_get_bitmap_height(right_ship[sprite_rigth])-8;
        dire_w = al_get_bitmap_width(right_ship[sprite_rigth])-10;
        }
    if(presion_L == true && presion_R == false)
        {
        al_draw_bitmap(left_ship[sprite_left], direc_x, direc_y, 0);
        dire_h = al_get_bitmap_height(left_ship[sprite_left])-8;
        dire_w = al_get_bitmap_width(left_ship[sprite_left])-10;
            }
    }

//    if(shut)
//            {
//                al_draw_bitmap(fireshut,direc_x_shut,direc_y_shut,0);
//            }
//        cout<<"H-> "<<dire_h<<endl;
//        cout<<"W-> "<<dire_w<<endl;
}
void Ship::destroy_ship(){
            if(sprite_explo<4){
            sprite_explo++;
            //cout<<"entro"<<endl;
            }else{
            sprite_explo = 0;
            }
        al_draw_bitmap(explosion[sprite_explo], direc_x, direc_y, 0);

}
void Ship::destroy_all()
{
    for(int i=0; i<neutral_ship.size(); i++){
        //al_destroy_timer(timer);
        al_destroy_bitmap(neutral_ship[i]);
        al_destroy_bitmap(right_ship[i]);
        al_destroy_bitmap(left_ship[i]);
        //al_destroy_sample(audio);
    }
    for(int i=0; i<explosion.size(); i++){
    al_destroy_bitmap(explosion[i]);
    }
}

bool Ship::collision(int eneX, int eneY, int eneW, int eneH)
{
    if((direc_x > eneX + eneW - 1) || (direc_y > eneY + eneH - 1)  || (eneX > direc_x + dire_w - 1) || (eneY > direc_y + dire_h - 1))
    {
        return  false;
    }
    //cout<<"colision"<<endl;
    //al_play_sample(audio, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
    colisionado = true;
    return  true;

}
Ship::~Ship()
{
    //dtor
}
