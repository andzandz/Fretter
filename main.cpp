//License is WTFPL (see README.md), author Andy C. K / andzandz
//
//Messy; made from stripped down other project.

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string>
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//globals, except num GUI elements
bool paused = false;
bool quit   = false;
float friction = 0.5;        // * -vel, force applied to objects as friction

int bg_w, bg_h;

int lastticks = 0, tickselapsed, fps;
float ticksfactor;

SDL_Surface *bg_img = NULL;
SDL_Surface *note_img = NULL;
SDL_Surface *rest_img = NULL;
SDL_Surface *gclef_img = NULL;
SDL_Surface *screen = NULL;

//declarations since things have to be in order and _use eachother_ -.-

float mousex;   //metres
float mousey;
bool mousepressed[10];  //10 buttons just in case
bool scrolled[10];

int fretleft = 80, frettop = 400, fretspace = 20;
int stavetop = 100;

#include "sdl.cpp"
#include "classes.cpp"

#include "maths.cpp"
#include "input.cpp"

#include "init.cpp"         //start SDL, load files
#include "functions.cpp"    //misc: ticks system, bg, text




void create_objs()
{
  /*strncpy(GUIForceNum.prefixtext,"KeyForce: ",25);
  strncpy(GUIForceNum.suffixtext," N",25);
  GUIForceNum.x = 16; GUIForceNum.y = bg_h + 7;
  GUIForceNum.storedvalue = 25;
  GUIForceNum.increment = 5;
  GUIForceNum.chars = 14; GUIForceNum.active = true; */

  transpose.x = 10; transpose.y = 10;
  strncpy(transpose.prefixtext,"Transpose: ",12);
  strncpy(transpose.suffixtext," Octaves",10);
  transpose.value = 0;
  transpose.chars = 20;
  transpose.increment = 1;

  noteguidebutton.active = false;
  strncpy(noteguidebutton.prefixtext,"Note Guide",12);
  noteguidebutton.x = 310; noteguidebutton.y = 10;
  noteguidebutton.boolbutton = true;
  noteguidebutton.chars = 11;

  sharpbutton.value = rand()%2; sharpbutton.increment = 1;
  sharpbutton.maxval = 1;
  strncpy(sharpbutton.option1,"Sharps Only"  ,12);
  strncpy(sharpbutton.option2,"  Flats Only"   ,14);
  strncpy(sharpbutton.option3,"Random #/b",14);
  sharpbutton.x = 200; sharpbutton.y = 10;
  sharpbutton.comboscroll = true;
  sharpbutton.chars = 11;

  for(int i = 0; i<strings; i++)
  {
    tuning[i].x = fretleft - 2 * fretspace;
    tuning[i].y = frettop + i*fretspace;
    tuning[i].octave = 1;
    tuning[i].increment = 1;
    tuning[i].chars = 3;
    tuning[i].tuningbool = true;
    tuning[i].onstring = i;
  }
    tuning[5].value = 7;     //7 = E
    tuning[4].value = 7+5;   //A
    tuning[3].value = 7+10;  //D
    tuning[2].value = 7+15;  //G
    tuning[1].value = 7+15+4;  //B
    tuning[0].value = 7+20+4;  //B

  for(int n = 0; n<tabs; n++)
  {
    for(int i = 0; i<strings; i++)
    {
      fret[n][i].x = fretleft + n*fretspace*1.5;
      fret[n][i].y = frettop + i*fretspace;
      fret[n][i].value = 0;
      fret[n][i].increment = 1;
      fret[n][i].chars = 1;
      fret[n][i].active = false;
      fret[n][i].fretbool = true;
      fret[n][i].onstring = i;
	  fret[n][i].onfret = n;
    }
  }
}



int main(int argc, char *argv[])
{
  quit = false;
  paused = false;

  init();

  create_objs();

  while(quit==false)
  {
    update_time();
    handle_input();
    draw_bg();
    draw_stave();
    draw_GUI();

    SDL_Flip( screen ); // update the screen
  }

  TTF_Quit();
  SDL_Quit();
  return 0;
}
