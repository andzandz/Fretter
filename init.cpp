void load_files()
{
  cout << "load bg," << endl;
  bg_img = img_load("bg.png"); 
  bg_w = temp_w; bg_h = temp_h;	//h & w
  cout << "load note," << endl;
  note_img = img_load("note.png"); 
  rest_img = img_load("rest.png"); 
  gclef_img = img_load("gclef.png");
  font1= TTF_OpenFont("Moderne Regular.ttf", 16);
}

bool init()
{
  cout << "1: init SDL..\n"; 
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) quit=true;
  
  cout << "2: start display..\n";
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    SDL_ShowCursor(SDL_ENABLE);
  
  cout << "3: initialising SDL_TTF" << endl;
    if (TTF_Init()==-1) {quit=true;}

  
  cout << "4: load files..\n";      
    load_files();
  cout << "5: resize display..\n";  
    SCREEN_WIDTH=bg_w;   SCREEN_HEIGHT=bg_h;
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
  srand((unsigned)time(0)); 
  cout << "6: start runloop..\n"; 
}
