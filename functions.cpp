// Misc stuff

void update_time()
{
  tickselapsed = SDL_GetTicks() - lastticks;
  ticksfactor = tickselapsed/1000.0;
  fps = 1/ticksfactor;
  lastticks = SDL_GetTicks();
}

void draw_bg()
{
  blit( 0, 0, bg_img, screen );
}


void draw_GUI()
{
  for(int i = 0; i<strings; i++)
  {
    for(int n = 0; n<tabs; n++)
    {
      notedisplay[n][i] = false;
    }
  }

  transpose.update();
  noteguidebutton.update();
  sharpbutton.update();

  for(int i = 0; i<strings; i++)
  {
    for(int n = 0; n<tabs; n++)
    {
      fret[n][i].update();
    }
  }
  for(int i = 0; i<strings; i++)
  {
    tuning[i].update();
  }
}

void draw_stave()
{
  blitrect (fretleft -0.5*fretspace  ,stavetop               ,tabs*fretspace*1.5   ,1   ,255,255,255);
  blitrect (fretleft -0.5*fretspace  ,stavetop+ 1*fretspace  ,tabs*fretspace*1.5   ,1   ,255,255,255);
  blitrect (fretleft -0.5*fretspace  ,stavetop+ 2*fretspace  ,tabs*fretspace*1.5   ,1   ,255,255,255);
  blitrect (fretleft -0.5*fretspace  ,stavetop+ 3*fretspace  ,tabs*fretspace*1.5   ,1   ,255,255,255);
  blitrect (fretleft -0.5*fretspace  ,stavetop+ 4*fretspace  ,tabs*fretspace*1.5   ,1   ,255,255,255);
  blit( fretleft-3.5*fretspace+5, stavetop-22, gclef_img, screen );
}

SDL_Color colour1 = {0,0,0};
void displaytext(char text[60], int x, int y, int r, int g, int b)
{
  colour1 = (SDL_Color){r,g,b}; // set colour1 to the correct r,g,b values
  SDL_Surface *temp_text_surface = NULL;  //make a surface for the text
  temp_text_surface = TTF_RenderText_Solid(font1, text, colour1);  //render the text with the right font and colour into the surface
  blit(x, y, temp_text_surface, screen);  //blit it
  SDL_FreeSurface(temp_text_surface); 	//after blitting, free the surface
}

void draw_textnum(float x, float y, char buffer[25], float num, char buffer2[25])
{
  char buffer3[40];
  sprintf (buffer3, "%s%.0f%s", buffer, num, buffer2);
  displaytext (buffer3, x, y, 255, 255, 255);
}
