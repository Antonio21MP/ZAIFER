#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>
#include <vector>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "Ship.h"
#include "Enemy.h"
#include "EShip.h"
#include "Animal.h"
#include "Alien.h"
#include "AlienInvert.h"
#include "Meteor.h"
#include <sstream>
#include <fstream>
using namespace std;

char* imprimir;
char* one;
char* two;
char* three;
int frame = 0, seleccion = 0, record = 0, Primero = 0, Segundo = 0, Tercero = 0, Nvl = 0, meta = 0;
bool vivo = true;
ALLEGRO_EVENT_QUEUE *event_queue;


void CargarPuntajes(){

    ifstream in("Puntajes.txt");
    in>>Primero;
    in>>Segundo;
    in>>Tercero;

    in.close();
}
void AgregarPuntajes(){
    ofstream out("Puntajes.txt");

    if(record>Primero){
        out<<record<<endl;
        out<<Primero<<endl;
        out<<Segundo<<endl;
    }else if(record>Segundo){
        out<<Primero<<endl;
        out<<record<<endl;
        out<<Segundo<<endl;
    }else if(record>Tercero){
        out<<Primero<<endl;
        out<<Segundo<<endl;
        out<<record<<endl;
    }
    out.close();
}
void Gameover(){
    ALLEGRO_TIMEOUT timeout;
    ALLEGRO_BITMAP* finishid;
    ALLEGRO_FONT* font;
    al_init_timeout(&timeout, 0.06);

    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    finishid = al_load_bitmap("gameover.png");
    font = al_load_ttf_font("airstrikelaser.ttf",24,0);

    while(true){
            ALLEGRO_EVENT event;
            bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);
            if (get_event && event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                break;
            }
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_bitmap(finishid, 0, 0, 0);
            al_draw_text(font, al_map_rgb(255,255,255), 500, (500),ALLEGRO_ALIGN_CENTRE, "presione el boton x para retornar al menu");
            al_flip_display();
    }
    al_destroy_bitmap(finishid);
    al_destroy_font(font);
}

void NivelSuperado(){

    ALLEGRO_TIMEOUT timeout;
    ALLEGRO_BITMAP* nvl;
    ALLEGRO_FONT* font;
    al_init_timeout(&timeout, 0.06);
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    nvl = al_load_bitmap("nvlsuperado.png");
    font = al_load_ttf_font("airstrikelaser.ttf",24,0);
    int cargando = 0;
    while(true){

            cargando++;
            ALLEGRO_EVENT event;
            bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);
            if (get_event && event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                break;
            }
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_bitmap(nvl, 0, 0, 0);
            al_draw_text(font, al_map_rgb(255,255,255), 500, (500),ALLEGRO_ALIGN_CENTRE, "cargando siguiente nivel");

            if(cargando==300){
                break;
            }

            al_flip_display();
    }
    al_destroy_bitmap(nvl);
    al_destroy_font(font);
}

void Zona_1(){
    int space_sprite = 0;
    frame = 0;
    meta = 0;
    record = 0;
    ALLEGRO_FONT *font;
    vector<ALLEGRO_BITMAP*>background;
    //ALLEGRO_TIMER *timer;
    ALLEGRO_SAMPLE* audio=NULL;
    ALLEGRO_SAMPLE* fondo=NULL;
    ALLEGRO_TIMEOUT timeout;
    al_init_timeout(&timeout, 0.06);
    al_init_image_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(3);
    al_init_font_addon();
    al_init_ttf_addon();
    //timer = al_create_timer(1.0/50.0);
    background.push_back(al_load_bitmap("space0.png"));
    background.push_back(al_load_bitmap("space1.png"));
    background.push_back(al_load_bitmap("space2.png"));
    background.push_back(al_load_bitmap("space3.png"));
    background.push_back(al_load_bitmap("space0.png"));
    font = al_load_ttf_font("airstrikelaser.ttf",24,0);
    audio = al_load_sample("boom1.wav");
    fondo = al_load_sample("Planetrise v1_0.ogg");
    Ship *nave = new Ship(event_queue);

    Enemy *enemigo1 = new EShip();
    Enemy *enemigo2 = new EShip();
    Enemy *enemigo3 = new EShip();
    Enemy *enemigo4 = new EShip();
    Enemy *enemigo5 = new EShip();
    Enemy *enemigo6 = new EShip();
    Enemy *enemigo7 = new EShip();

    enemigo2->direc_x = 60;
    enemigo3->direc_x = 900;
    enemigo4->direc_x = 200;
    enemigo5->direc_x = 650;
    enemigo6->direc_x = 360;
    enemigo7->direc_x = 780;
    al_play_sample(fondo, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
   while(true){
        //cout<<seleccion<<endl;
        frame++;
        //cout<<frame<<endl;
        if(frame%25==0){
            record++;
        }
        if(frame%32==0){
            meta++;
        }
        //cout<<perseguidor<<endl;

        stringstream impreso;
        impreso<<record;
        string convertido = impreso.str();
        imprimir = (char*)&convertido[0];
        ALLEGRO_EVENT event;
        bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);
        if (get_event && event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            seleccion = 0;
            //AgregarPuntajes();
            break;
            }
        if(frame%15==0){
            if(space_sprite<2){
                space_sprite++;
            }else{
                space_sprite=0;
                }
        }
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(background[space_sprite],0,0,0);
        nave->act(&event, frame);
        nave->draw();
        if(nave->collision(enemigo1->direc_x,enemigo1->direc_y,enemigo1->direc_w,enemigo1->direc_h)||
        nave->collision(enemigo2->direc_x,enemigo2->direc_y,enemigo2->direc_w,enemigo2->direc_h)||
        nave->collision(enemigo3->direc_x,enemigo3->direc_y,enemigo3->direc_w,enemigo3->direc_h)||
        nave->collision(enemigo5->direc_x,enemigo5->direc_y,enemigo5->direc_w,enemigo5->direc_h)||
        nave->collision(enemigo6->direc_x,enemigo6->direc_y,enemigo6->direc_w,enemigo6->direc_h)||
        nave->collision(enemigo7->direc_x,enemigo7->direc_y,enemigo7->direc_w,enemigo7->direc_h)||
        nave->collision(enemigo4->direc_x,enemigo4->direc_y,enemigo4->direc_w,enemigo4->direc_h)){
        nave->destroy_ship();
        al_play_sample(audio, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
        if(frame%10==0){
        Gameover();
        AgregarPuntajes();
        seleccion = 0;
        vivo = false;
        break;
        }
        }

        if(enemigo1->direc_y<680){
            enemigo1->act(frame, 22);
        }else{
            enemigo1->direc_y = -50;
        }
        if(enemigo2->direc_y<680){
            enemigo2->act(frame,28);
        }else{
            enemigo2->direc_y = -50;
        }

        if(enemigo3->direc_y<680){
            enemigo3->act(frame, 31);
        }else{
            enemigo3->direc_y = -50;
        }
        if(enemigo4->direc_y<680){
            enemigo4->act(frame, 39);
        }else{
            enemigo4->direc_y = -50;
        }
        if(enemigo5->direc_y<680){
            enemigo5->act(frame, 44);
        }else{
            enemigo5->direc_y = -50;
        }
        if(enemigo6->direc_y<680){
            enemigo6->act(frame, 50);
        }else{
            enemigo6->direc_y = -50;
        }
        if(enemigo7->direc_y<680){
            enemigo7->act(frame, 47);
        }else{
            enemigo7->direc_y = -50;
        }
        al_draw_text(font, al_map_rgb(255,255,255), 50, (4),ALLEGRO_ALIGN_CENTRE, "SCORE:");
        al_draw_text(font, al_map_rgb(255,255,255), 150, (4),ALLEGRO_ALIGN_CENTRE, imprimir);
        al_draw_text(font, al_map_rgb(255,255,255), 900, (4),ALLEGRO_ALIGN_CENTRE, "NIVEL: 1");

        if(meta==50){
            NivelSuperado();
            Nvl = 2;
            break;
        }

        al_flip_display();
        }
        for(int i=0; i<background.size(); i++)
        al_destroy_bitmap(background[i]);
        nave->destroy_all();
        enemigo1->destroy_all();
        enemigo2->destroy_all();
        enemigo3->destroy_all();
        enemigo4->destroy_all();
        enemigo5->destroy_all();
        enemigo6->destroy_all();
        enemigo7->destroy_all();
        al_destroy_font(font);
        al_destroy_sample(audio);
        al_destroy_sample(fondo);
}

void Zona_2(){
    int space_sprite = 0;
    frame = 0;
    ALLEGRO_FONT *font;
    vector<ALLEGRO_BITMAP*>background;
    //ALLEGRO_TIMER *timer;
    ALLEGRO_SAMPLE* audio;
    ALLEGRO_SAMPLE* fondo;
    ALLEGRO_TIMEOUT timeout;
    al_init_timeout(&timeout, 0.06);
    al_init_image_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(3);
    al_init_font_addon();
    al_init_ttf_addon();
    //timer = al_create_timer(1.0/50.0);
    background.push_back(al_load_bitmap("space00.png"));
    background.push_back(al_load_bitmap("space01.png"));
    background.push_back(al_load_bitmap("space02.png"));
    background.push_back(al_load_bitmap("space03.png"));
    background.push_back(al_load_bitmap("space00.png"));
    font = al_load_ttf_font("airstrikelaser.ttf",24,0);
    audio = al_load_sample("boom1.wav");
    fondo = al_load_sample("MysticalCaverns.ogg");
    Ship *nave = new Ship(event_queue);

    Enemy *enemigo1 = new Meteor();
    Meteor *enemigoD = new Meteor();
    Meteor *enemigoI = new Meteor();
    Enemy *enemigo3 = new Meteor();
    Enemy *enemigo4 = new Meteor();
    Enemy *enemigo5 = new Meteor();
    Enemy *enemigo6 = new Meteor();
    Enemy *enemigo7 = new Meteor();

    enemigoD->direc_x = -10;
    enemigoD->direc_y = 200;
    enemigoI->direc_x = 920;
    enemigoI->direc_y = 600;


    enemigo1->direc_x = 0;
    enemigo3->direc_x = 180;
    enemigo4->direc_x = 360;
    enemigo5->direc_x = 540;
    enemigo6->direc_x = 720;
    enemigo7->direc_x = 900;
    al_play_sample(fondo, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
    while(true){
        //cout<<seleccion<<endl;
        frame++;

        if(frame%25==0){
            record++;
        }

        if(frame%32==0){
            meta++;
        }
        //cout<<perseguidor<<endl;

        stringstream impreso;
        impreso<<record;
        string convertido = impreso.str();
        imprimir = (char*)&convertido[0];
        ALLEGRO_EVENT event;
        bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);
        if (get_event && event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            seleccion = 0;
            //AgregarPuntajes();
            break;
            }
        if(frame%15==0){
            if(space_sprite<2){
                space_sprite++;
            }else{
                space_sprite=0;
                }
        }
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(background[space_sprite],0,0,0);
        nave->act(&event, frame);
        nave->draw();
        if(nave->collision(enemigo1->direc_x,enemigo1->direc_y,enemigo1->direc_w,enemigo1->direc_h)||
        nave->collision(enemigoD->direc_x,enemigoD->direc_y,enemigoD->direc_w,enemigoD->direc_h)||
        nave->collision(enemigoI->direc_x,enemigoI->direc_y,enemigoI->direc_w,enemigoI->direc_h)||
        nave->collision(enemigo3->direc_x,enemigo3->direc_y,enemigo3->direc_w,enemigo3->direc_h)||
        nave->collision(enemigo5->direc_x,enemigo5->direc_y,enemigo5->direc_w,enemigo5->direc_h)||
        nave->collision(enemigo6->direc_x,enemigo6->direc_y,enemigo6->direc_w,enemigo6->direc_h)||
        nave->collision(enemigo7->direc_x,enemigo7->direc_y,enemigo7->direc_w,enemigo7->direc_h)||
        nave->collision(enemigo4->direc_x,enemigo4->direc_y,enemigo4->direc_w,enemigo4->direc_h)){
        nave->destroy_ship();
        al_play_sample(audio, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
        if(frame%10==0){
        Gameover();
        AgregarPuntajes();
        seleccion = 0;
        vivo = false;
        break;
        }
        }


        if(enemigo1->direc_y<680){
            enemigo1->act(frame, 35);
        }else{
            enemigo1->direc_y = -50;
        }
        if(frame>100)
        if(enemigoD->direc_x<920){
            enemigoD->act2(frame,37);
        }else{
            enemigoD->direc_x = -20;
        }
        if(frame>250)
        if(enemigoI->direc_x>-15){
            enemigoI->act3(frame,37);
        }else{
            enemigoI->direc_x = 920;
        }
        if(frame>50)
        if(enemigo3->direc_y<680){
            enemigo3->act(frame, 27);
        }else{
            enemigo3->direc_y = -50;
        }
        if(frame>180)
        if(enemigo4->direc_y<680){
            enemigo4->act(frame, 29);
        }else{
            enemigo4->direc_y = -50;
        }
        if(enemigo5->direc_y<680){
            enemigo5->act(frame, 41);
        }else{
            enemigo5->direc_y = -50;
        }
        if(enemigo6->direc_y<680){
            enemigo6->act(frame, 50);
        }else{
            enemigo6->direc_y = -50;
        }
        if(frame>200)
        if(enemigo7->direc_y<680){
            enemigo7->act(frame, 47);
        }else{
            enemigo7->direc_y = -50;
        }
        al_draw_text(font, al_map_rgb(255,255,255), 50, (4),ALLEGRO_ALIGN_CENTRE, "SCORE:");
        al_draw_text(font, al_map_rgb(255,255,255), 150, (4),ALLEGRO_ALIGN_CENTRE, imprimir);
        al_draw_text(font, al_map_rgb(255,255,255), 900, (4),ALLEGRO_ALIGN_CENTRE, "NIVEL: 2");

        if(meta==100){
            NivelSuperado();
            Nvl = 3;
            break;
        }

        al_flip_display();
        }
        for(int i=0; i<background.size(); i++)
        al_destroy_bitmap(background[i]);
        nave->destroy_all();
        enemigo1->destroy_all();
        enemigoD->destroy_all();
        enemigoI->destroy_all();
        enemigo3->destroy_all();
        enemigo4->destroy_all();
        enemigo5->destroy_all();
        enemigo6->destroy_all();
        enemigo7->destroy_all();
        al_destroy_font(font);
        al_destroy_sample(audio);
        al_destroy_sample(fondo);
}

void Zona_3(){
    int space_sprite = 0;
    frame = 0;
    ALLEGRO_FONT *font;
    ALLEGRO_SAMPLE* audio;
    ALLEGRO_SAMPLE* fondo;
    vector<ALLEGRO_BITMAP*>background;
    //ALLEGRO_TIMER *timer;
    ALLEGRO_TIMEOUT timeout;
    al_init_timeout(&timeout, 0.06);
    al_init_image_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(3);
    al_init_font_addon();
    al_init_ttf_addon();
    //timer = al_create_timer(1.0/50.0);
    background.push_back(al_load_bitmap("space000.png"));
    background.push_back(al_load_bitmap("space001.png"));
    background.push_back(al_load_bitmap("space002.png"));
    background.push_back(al_load_bitmap("space003.png"));
    background.push_back(al_load_bitmap("space000.png"));
    font = al_load_ttf_font("airstrikelaser.ttf",24,0);
    audio = al_load_sample("boom1.wav");
    fondo = al_load_sample("bleeding_out2_2.ogg");
    Ship *nave = new Ship(event_queue);

    Enemy *enemigo1 = new Animal();
    Animal  *enemigo2 = new Animal();
    Enemy *enemigo3 = new Alien();
    Enemy *enemigo4 = new Alien();
    Enemy *enemigo5 = new Alien();
    Enemy *enemigo6 = new AlienInvert();
    Enemy *enemigo7 = new AlienInvert();
    Enemy *enemigo8 = new AlienInvert();

    enemigo1->direc_x = 0;
    enemigo2->direc_x = 900;

    enemigo3->direc_x = 180;
    enemigo4->direc_x = 540;
    enemigo5->direc_x = 900;

    enemigo8->direc_y = 700;
    enemigo8->direc_x = 0;
    enemigo6->direc_y = 700;
    enemigo6->direc_x = 360;
    enemigo7->direc_y = 700;
    enemigo7->direc_x = 720;
    al_play_sample(fondo, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
    while(true){
        //cout<<seleccion<<endl;
        frame++;

        if(frame%25==0){
            record++;
        }
        //cout<<perseguidor<<endl;

        stringstream impreso;
        impreso<<record;
        string convertido = impreso.str();
        imprimir = (char*)&convertido[0];
        ALLEGRO_EVENT event;
        bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);
        if (get_event && event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            seleccion = 0;
            //AgregarPuntajes();
            break;
            }
        if(frame%15==0){
            if(space_sprite<2){
                space_sprite++;
            }else{
                space_sprite=0;
                }
        }
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(background[space_sprite],0,0,0);
        nave->act(&event, frame);
        nave->draw();
        if(nave->collision(enemigo1->direc_x,enemigo1->direc_y,enemigo1->direc_w,enemigo1->direc_h)||
        nave->collision(enemigo2->direc_x,enemigo2->direc_y,enemigo2->direc_w,enemigo2->direc_h)||
        nave->collision(enemigo3->direc_x,enemigo3->direc_y,enemigo3->direc_w,enemigo3->direc_h)||
        nave->collision(enemigo5->direc_x,enemigo5->direc_y,enemigo5->direc_w,enemigo5->direc_h)||
        nave->collision(enemigo6->direc_x,enemigo6->direc_y,enemigo6->direc_w,enemigo6->direc_h)||
        nave->collision(enemigo7->direc_x,enemigo7->direc_y,enemigo7->direc_w,enemigo7->direc_h)||
        nave->collision(enemigo8->direc_x,enemigo8->direc_y,enemigo8->direc_w,enemigo8->direc_h)||
        nave->collision(enemigo4->direc_x,enemigo4->direc_y,enemigo4->direc_w,enemigo4->direc_h))
        {
        nave->destroy_ship();
        al_play_sample(audio, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);
        if(frame%10==0){
        Gameover();
        AgregarPuntajes();
        seleccion = 0;
        vivo = false;
        break;
        }
            }

        if(enemigo1->direc_y<680){
            enemigo1->act(frame, 22);
        }else{
            enemigo1->direc_y = -50;
            enemigo1->direc_x = 0;
        }
        if(enemigo2->direc_y<680){
            enemigo2->act2(frame,28);
        }else{
            enemigo2->direc_y = -50;
            enemigo2->direc_x = 900;
        }
        if(enemigo3->direc_y<680){
            enemigo3->act(frame, 40);
        }else{
            enemigo3->direc_y = -50;
        }
        if(enemigo4->direc_y<680){
            enemigo4->act(frame, 45);
        }else{
            enemigo4->direc_y = -50;
        }
        if(enemigo5->direc_y<680){
            enemigo5->act(frame, 50);
        }else{
            enemigo5->direc_y = -50;
        }
        if(frame>90)
        if(enemigo6->direc_y>-15){
            enemigo6->act(frame, 55);
        }else{
            enemigo6->direc_y = 700;
        }

        if(frame>90)
        if(enemigo7->direc_y>-15){
            enemigo7->act(frame, 47);
        }else{
            enemigo7->direc_y = 700;
        }

        if(frame>90)
        if(enemigo8->direc_y>-15){
            enemigo8->act(frame, 48);
        }else{
            enemigo8->direc_y = 700;
        }
        al_draw_text(font, al_map_rgb(255,255,255), 50, (4),ALLEGRO_ALIGN_CENTRE, "SCORE:");
        al_draw_text(font, al_map_rgb(255,255,255), 150, (4),ALLEGRO_ALIGN_CENTRE, imprimir);
        al_draw_text(font, al_map_rgb(255,255,255), 900, (4),ALLEGRO_ALIGN_CENTRE, "NIVEL: 3");
        al_flip_display();
        }
        for(int i=0; i<background.size(); i++)
        al_destroy_bitmap(background[i]);
        nave->destroy_all();
        enemigo1->destroy_all();
        enemigo2->destroy_all();
        enemigo3->destroy_all();
        enemigo4->destroy_all();
        enemigo5->destroy_all();
        enemigo6->destroy_all();
        enemigo7->destroy_all();
        enemigo8->destroy_all();
        al_destroy_font(font);
        al_destroy_sample(audio);
        al_destroy_sample(fondo);
}

void Niveles(){
    if(Nvl==1&&vivo){
        Zona_1();
        //cout<<"salio"<<endl;
    }
    if(Nvl==2&&vivo){
        Zona_2();
    }
    if(Nvl==3&&vivo){
        Zona_3();
    }
}

void INSTRUC()
{
    ALLEGRO_TIMEOUT timeout;
    ALLEGRO_BITMAP *instruciones;
    al_init_timeout(&timeout, 0.06);
    al_init_image_addon();
    instruciones = al_load_bitmap("instrucciones.png");
        while(true){
            ALLEGRO_EVENT event;
            bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);
            if (get_event && event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                    seleccion = 0;
                    break;
                }
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_bitmap(instruciones, 0,0,0);
            al_flip_display();
        }
    al_destroy_bitmap(instruciones);
}
void Puntajes(){

    ALLEGRO_TIMEOUT timeout;
    ALLEGRO_FONT *font;
    al_init_timeout(&timeout, 0.06);
    al_init_font_addon();
    al_init_ttf_addon();
    font = al_load_ttf_font("airstrikelaser.ttf",45,0);

    //CONVERSION DEL PRIMER LUGAR
    stringstream First;
    First<<Primero;
    string firstconvert = First.str();
    one = (char*)&firstconvert[0];
    //CONVERSION DEL SEGUNDO LUGAR
    stringstream Second;
    Second<<Segundo;
    string secondconvert = Second.str();
    two = (char*)&secondconvert[0];
    //CONVERSION DEL TERCER LUGAR
    stringstream Third;
    Third<<Tercero;
    string thirdconvert = Third.str();
    three = (char*)&thirdconvert[0];

    while(true){
            ALLEGRO_EVENT event;
            bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);
            if (get_event && event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                    seleccion = 0;
                    break;
                }
            al_clear_to_color(al_map_rgb(0, 0, 0));
            //TITULO
            al_draw_text(font, al_map_rgb(255,255,255), 504, (100),ALLEGRO_ALIGN_CENTRE, "PUNTAJES");
            //PRIMERO
            al_draw_text(font, al_map_rgb(255,255,255), 400, (204),ALLEGRO_ALIGN_CENTRE, "1ro: ");
            al_draw_text(font, al_map_rgb(255,255,255), 600, (204),ALLEGRO_ALIGN_CENTRE, one);
            //SEGUNDO
            al_draw_text(font, al_map_rgb(255,255,255), 400, (304),ALLEGRO_ALIGN_CENTRE, "2ro: ");
            al_draw_text(font, al_map_rgb(255,255,255), 600, (304),ALLEGRO_ALIGN_CENTRE, two);
            //TERCERO
            al_draw_text(font, al_map_rgb(255,255,255), 400, (404),ALLEGRO_ALIGN_CENTRE, "3ro: ");
            al_draw_text(font, al_map_rgb(255,255,255), 600, (404),ALLEGRO_ALIGN_CENTRE, three);

            al_flip_display();
            }
    al_destroy_font(font);
}

void IniciarMenu(){

    enum MENU_KEYS{
        MENU_KEY_UP,
        MENU_KEY_DOWN,
        MENU_KEY_ENTER
    };
    bool key[3] = { false, false, false };
    int selected_sprite = 0, y=0;
    int opcion[4] = { 276, 350, 428, 510 };
    ALLEGRO_DISPLAY *display;
    ALLEGRO_TIMER *timer;
    ALLEGRO_SAMPLE_ID detener;
    ALLEGRO_SAMPLE  *audio=NULL;
    ALLEGRO_TIMEOUT timeout;

    ALLEGRO_BITMAP *menu;
    vector<ALLEGRO_BITMAP*> selected;

    al_init_timeout(&timeout, 0.06);

    al_init();
    //para que la imagen sea iniciada
    al_init_image_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(1);
    //para que imprima la pantalla
    al_install_keyboard();

    display = al_create_display(1024, 700);
    //para iniciar o crear el evento
    event_queue = al_create_event_queue();
    //para iniciar o crear el timer
    timer = al_create_timer(1.0/50.0);

    menu = al_load_bitmap("Menu.png");
    selected.push_back(al_load_bitmap("select0.png"));
    selected.push_back(al_load_bitmap("select1.png"));
    selected.push_back(al_load_bitmap("select2.png"));
    audio = al_load_sample("DarkIntro_0.ogg");
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_start_timer(timer);
    al_play_sample(audio, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,&detener);
    do{
        frame++;

        CargarPuntajes();
//        if(frame%20==0)
//        cout<<seleccion<<endl;


        if(frame%15==0){
        selected_sprite++;
        }
        ALLEGRO_EVENT event;
        bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);
        if (get_event && event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            break;
            }

        if (event.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                if (event.keyboard.keycode == ALLEGRO_KEY_UP)
                    key[MENU_KEY_UP] = true;

                if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
                    key[MENU_KEY_DOWN] = true;

                if (event.keyboard.keycode == ALLEGRO_KEY_ENTER){
                        key[MENU_KEY_ENTER] = true;
                    }
            }

         if (event.type == ALLEGRO_EVENT_KEY_UP)
            {
                if (event.keyboard.keycode == ALLEGRO_KEY_UP)
                    key[MENU_KEY_UP] = false;

                if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
                    key[MENU_KEY_DOWN] = false;

                if (event.keyboard.keycode == ALLEGRO_KEY_ENTER)
                    key[MENU_KEY_ENTER] = false;
            }
        if (key[MENU_KEY_UP])
            {
                if(frame%7==0)
                    y--;
                if(y>0)
                {
                    opcion[y];
                }else{
                    y = 0;
                }
            }

        if (key[MENU_KEY_DOWN])
            {
                if(frame%7==0)
                    y++;

                if(y<4)
                {
                    opcion[y];
                }else{
                    y = 3;
                }
            }
        if(key[MENU_KEY_ENTER])
        {
            if(opcion[y]==276){
                        //inicio = true;
                            cout<<"JUGAR"<<endl;
                            seleccion = 1;
                        }
                        if(opcion[y]==350){
                        //puntuacion = true;
                            cout<<"PUNTUACION"<<endl;
                            seleccion = 2;
                        }
                        if(opcion[y]==428){
                        //instrucciones = true;
                            cout<<"INSTRUCCIONES"<<endl;
                            seleccion = 3;
                        }
                        if(opcion[y]==510){
                        //salirm = true;
                            cout<<"SALIR"<<endl;
                            seleccion = 4;
                            }
        }
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu,0,0,0);

        if(selected_sprite<selected.size()){
            al_draw_bitmap(selected[selected_sprite],80,opcion[y],0);
        }else{
            selected_sprite = 0;
        }

        switch(seleccion)
        {
            //JUGAR
            case 1:
                Nvl = 1;
                vivo = true;
                al_stop_sample(&detener);
                Niveles();
                al_play_sample(audio, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,&detener);
            break;

            //PUNTUACIONES
            case 2:
                Puntajes();
            break;

            //INSTRUCCIONES
            case 3:
             INSTRUC();
            break;
        }

        //HACE QUE LAS TECLAS QUE SE PRESIONAN AL MOMENTO DE ENTRAR AL MENU VUELVAN A SU ESTADO ESTANDAR
        event.keyboard.keycode = -1218616196;
        key[MENU_KEY_ENTER] = false;
        //cout<<seleccion<<endl;

        al_flip_display();
    }while(seleccion!=4);

    for(int i=0; i<selected.size();i++)
    al_destroy_bitmap(selected[i]);

    al_destroy_bitmap(menu);
    al_destroy_timer(timer);
    al_destroy_sample(audio);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
}

int main()
{
    IniciarMenu();

    return 0;
}
