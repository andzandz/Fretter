
int upcount = 0, downcount = 0;
int handle_input()
{
  scrolled[SDL_BUTTON_WHEELUP] = false;
  scrolled[SDL_BUTTON_WHEELDOWN] = false;
  while( SDL_PollEvent( &event ) ) 
  {
    if(event.type == SDL_QUIT) quit = true;
    else if(event.type == SDL_KEYDOWN)
    {
      switch(event.key.keysym.sym)
      {
        case SDLK_w:	 upcount = 150;   break;
        case SDLK_UP: 	 upcount = 150;   break;
        case SDLK_s:	 downcount = 150;   break;
        case SDLK_DOWN:  downcount = 150;   break;
      }
    }
    
    else if(event.type == SDL_KEYUP)
    {
      switch(event.key.keysym.sym)
      {
        case SDLK_w:	 upcount = -1;    break;
        case SDLK_UP:	 upcount = -1;    break;
        case SDLK_s:	 downcount = -1;   break;
        case SDLK_DOWN:  downcount = -1;   break;
      }
    }
    
    else if(event.type == SDL_MOUSEMOTION)
    {
      //cout << "mousemove" << endl;
      mousex = event.motion.x;
      mousey = event.motion.y;
    }
    
    else if(event.type == SDL_MOUSEBUTTONDOWN)
    {
      mousepressed[event.button.button] = true;
      if(event.button.button == SDL_BUTTON_WHEELUP)   scrolled[SDL_BUTTON_WHEELUP]  =true;
      if(event.button.button == SDL_BUTTON_WHEELDOWN) scrolled[SDL_BUTTON_WHEELDOWN]=true;
    }
    
    else if(event.type == SDL_MOUSEBUTTONUP)
    {
      mousepressed[event.button.button] = false;
    }
  }
  if(upcount > 0) 
  {
    upcount -= tickselapsed;
    if(upcount < 1) 
    {
      scrolled[SDL_BUTTON_WHEELUP] = 1;
      upcount += 150;
    }
  }

  if(downcount > 0) 
  {
    downcount -= tickselapsed;
    if(downcount < 1) 
    {
      scrolled[SDL_BUTTON_WHEELDOWN] = 1;
      downcount += 150;
    }
  }
}
