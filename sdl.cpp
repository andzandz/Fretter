int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;
int SCREEN_BPP = 32;
bool fullscreen = 0;

SDL_Event event;
TTF_Font *font1= NULL;	//set up "font1" font for drawing text

int temp_w, temp_h;
SDL_Surface *img_load( std::string file )
{
  cout << "a) ";
  //temporarily store the loaded image
  SDL_Surface* raw_img = NULL;

  cout << "b) ";
  //The optimized image to be used
  SDL_Surface* optimised_img = NULL;

  cout << "c) ";
  //load the image
  raw_img = IMG_Load( file.c_str() );
  
  cout << "d) ";
  //if no problems loading the image
  if( raw_img != NULL )
  {
    //make the optimised image
    optimised_img = SDL_DisplayFormat( raw_img );
    temp_w = optimised_img->w;	//to return widths
    temp_h = optimised_img->h;	//to return heights
    //Free the unneeded surface
    SDL_FreeSurface( raw_img );
  }

  cout << "e) ";
  //map the rgb value for transparency
  Uint32 transrgb = SDL_MapRGB( optimised_img->format, 0, 255, 0 );

  cout << "f) ";
  // make all pixels of color R 0xFF, G 0, B 0 in the optimized img transparent
  SDL_SetColorKey( optimised_img, SDL_SRCCOLORKEY, transrgb );
  
  cout << "g)\n";
  //Return the optimized image
  return optimised_img;
}

void blit( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
  //temp rect to hold the coordinates
  SDL_Rect co_ords;
 
  //Give the cd-ords to the rectangle
  co_ords.x = x;
  co_ords.y = y;
  
  //Blit the surface
  SDL_BlitSurface( source, NULL, destination, &co_ords );
}



void blitrect(int x, int y, int w, int h, int r, int g, int b)
{
  SDL_Rect rect1;
  rect1.x = x;
  rect1.y = y;
  rect1.w = w;
  rect1.h = h;

  //Uint32 colour = SDL_MapRGBA(fmt, r, g, b, Uint8 128);
  Uint32 colour = r*256*256 + g*256 + b;    //24bit colour, bits RRRRRRRRGGGGGGGGBBBBBBBB.
  SDL_FillRect( screen, &rect1, colour);
}


