void draw_textnum(float,float,char buffer[20], float, char buffer2[20]);
void displaytext(char text[60], int x, int y, int r, int g, int b);
bool inside_region(float,float,float,float,float,float);

const int tabs = 31;
const int strings = 6;
bool notedisplay[tabs][strings];

float fmodulus(float);
float KE2vel(float,float);
float vel2KE(float,float);
int polarity(int);
int polarity(float);

/////////////////////////////////////////////////////////////////////////////////////////////



class GUINum 
{
 public:
  float x, y, w, h;  //if inactive, value will be 0
  int note, octave, chars, value, maxval, increment, letter, onstring, onfret, sharp;
  bool active, mouse1pressedlast, fretbool, tuningbool, boolbutton, comboscroll;    //if the mouse was pressed last frame
  char prefixtext[25];
  char suffixtext[25];
  char option1[25], option2[25], option3[25];
  void update();
  GUINum(); 
}tuning[strings], fret[tabs][strings], transpose, noteguidebutton, sharpbutton;

GUINum::GUINum()
{
  maxval = 24;
}

void GUINum::update()
{
  w = chars * 9;
  h = 0.7 * 32;
  
  if( inside_region(x-3,y-3,w+3,h+3,mousex,mousey ) )
  {
    if( scrolled[SDL_BUTTON_WHEELUP]   ) 
    {
		if(tuningbool)          value += increment;
        else if(value < maxval) value += increment;
    }
    if( scrolled[SDL_BUTTON_WHEELDOWN] ) 
    {
      if(fretbool || tuningbool || comboscroll) 
      {
        if(value > 0) 
        value -= increment;
      }
      else
      { 
        if(value > -1*maxval)  value -= increment;
      }
    }
    if( mouse1pressedlast == false && mousepressed[1] == true) 
    {active = !active;}
  }
    
  if(fretbool)
  {
    octave = 0;
    note = value + tuning[onstring].value;
    while(note > 11)
    {
      octave++;
      note -= 12;
    }
    if(sharpbutton.value==0)
    {
      if(note == 0)  {letter = 1; sharp = false;  } 	//A
      if(note == 1)  {letter = 1; sharp = true;   }	//A# (Bb)
      if(note == 2)  {letter = 2; sharp = false;  } 	//B
      if(note == 3)  {letter = 3; sharp = false;  }
      if(note == 4)  {letter = 3; sharp = true;   }
      if(note == 5)  {letter = 4; sharp = false;  }
      if(note == 6)  {letter = 4; sharp = true;   }
      if(note == 7)  {letter = 5; sharp = false;  }
      if(note == 8)  {letter = 6; sharp = false;  }
      if(note == 9)  {letter = 6; sharp = true;   }
      if(note == 10) {letter = 7; sharp = false;  }
      if(note == 11) {letter = 7; sharp = true;   }
    }
    else
    {
      if(note == 0)  {letter = 1; sharp = false;  } 	//A
      if(note == 1)  {letter = 2; sharp = -1;     }	//A# (Bb)
      if(note == 2)  {letter = 2; sharp = false;  } 	//B
      if(note == 3)  {letter = 3; sharp = false;  }
      if(note == 4)  {letter = 4; sharp = -1;     }
      if(note == 5)  {letter = 4; sharp = false;  }
      if(note == 6)  {letter = 5; sharp = -1;     }
      if(note == 7)  {letter = 5; sharp = false;  }
      if(note == 8)  {letter = 6; sharp = false;  }
      if(note == 9)  {letter = 7; sharp = -1;     }
      if(note == 10) {letter = 7; sharp = false;  }
      if(note == 11) {letter = 8; sharp = -1;     }
    }

    letter += octave*7;
    letter += transpose.value * 7;
  
    if(active) 
    {
	  for (int z=0; z<strings; z++)
	  {
	    if(!notedisplay[onfret][z])
		{
		  notedisplay[onfret][z] = true;
          int ntop = stavetop+(8+z)*fretspace;
		  int nr = 128, ng = 128, nb = 255;
	      if(noteguidebutton.active)
          {
			if(sharpbutton.value==0)
			{
              if(note == 0)  {displaytext("A",  x-0, ntop, nr,ng,nb);} 	//draw note guide
              if(note == 1)  {displaytext("A#", x-0, ntop,nr,ng,nb);}
              if(note == 2)  {displaytext("B",  x-0, ntop, nr,ng,nb);} 
              if(note == 3)  {displaytext("C",  x-0, ntop, nr,ng,nb);}
              if(note == 4)  {displaytext("C#", x-0, ntop,nr,ng,nb);}
              if(note == 5)  {displaytext("D",  x-0, ntop, nr,ng,nb);}
              if(note == 6)  {displaytext("D#", x-0, ntop,nr,ng,nb);}
              if(note == 7)  {displaytext("E",  x-0, ntop, nr,ng,nb);}
              if(note == 8)  {displaytext("F",  x-0, ntop, nr,ng,nb);}
              if(note == 9)  {displaytext("F#", x-0, ntop,nr,ng,nb);}
              if(note == 10) {displaytext("G",  x-0, ntop, nr,ng,nb);}
              if(note == 11) {displaytext("G#", x-0, ntop,nr,ng,nb);}
			}
			else
			{
              if(note == 0)  {displaytext("A",  x-0, ntop, nr,ng,nb);} 	//draw note guide
              if(note == 1)  {displaytext("Bb", x-0, ntop,nr,ng,nb);}
              if(note == 2)  {displaytext("B",  x-0, ntop, nr,ng,nb);} 
              if(note == 3)  {displaytext("C",  x-0, ntop, nr,ng,nb);}
              if(note == 4)  {displaytext("Db", x-0, ntop,nr,ng,nb);}
              if(note == 5)  {displaytext("D",  x-0, ntop, nr,ng,nb);}
              if(note == 6)  {displaytext("Eb", x-0, ntop,nr,ng,nb);}
              if(note == 7)  {displaytext("E",  x-0, ntop, nr,ng,nb);}
              if(note == 8)  {displaytext("F",  x-0, ntop, nr,ng,nb);}
              if(note == 9)  {displaytext("Gb", x-0, ntop,nr,ng,nb);}
              if(note == 10) {displaytext("G",  x-0, ntop, nr,ng,nb);}
              if(note == 11) {displaytext("Ab", x-0, ntop,nr,ng,nb);}
			}
          }
		  break;
		}
	  }
      if( value < 10) draw_textnum(x  ,y, "", value, "" );
      else            draw_textnum(x-6,y, "", value, "" );
      int notey = stavetop + (6- letter*0.5)*fretspace;
      blit( x-0.25*fretspace, notey, note_img, screen );        //draw the note

	  if(notey > stavetop+1*fretspace) blitrect(x+(fretspace*0.75),notey-1.5*fretspace,1,2*fretspace+2,255,255,255);	//draw the "stalk" above
	  else							   blitrect(x-(fretspace*0.25),notey+8,1,2*fretspace+2,255,255,255);			//draw the "stalk" under
      if(sharp== 1) displaytext("#", x+fretspace, notey, 255,255,255); 		//draw sharp symbol
	  if(sharp==-1) displaytext("b", 1+x+fretspace, notey, 255,255,255);	//draw the flat symbol

      if( notey > stavetop + 4*fretspace )
      blitrect (x-(fretspace*0.50), stavetop + 5*fretspace, fretspace*1.5, 1 ,255,255,255); //extra stave lines
      if( notey > stavetop + 5*fretspace )
      blitrect (x-(fretspace*0.50), stavetop + 6*fretspace, fretspace*1.5, 1 ,255,255,255); //extra stave lines
      if( notey > stavetop + 6*fretspace )
      blitrect (x-(fretspace*0.50), stavetop + 7*fretspace, fretspace*1.5, 1 ,255,255,255); //extra stave lines

      if( notey < stavetop - 1*fretspace )
      blitrect (x-(fretspace*0.50), stavetop - 1*fretspace, fretspace*1.5, 1 ,255,255,255); //extra stave lines
      if( notey < stavetop - 2*fretspace )
      blitrect (x-(fretspace*0.50), stavetop - 2*fretspace, fretspace*1.5, 1 ,255,255,255); //extra stave lines
      if( notey < stavetop - 3*fretspace )
      blitrect (x-(fretspace*0.50), stavetop - 3*fretspace, fretspace*1.5, 1 ,255,255,255); //extra stave lines

    }
    else 
    {
      displaytext("-", x, y, 255,255,255);
	  if (onstring == strings-1)
	   if (!notedisplay[onfret][0])
	    if (!notedisplay[onfret][1])
	      if (!notedisplay[onfret][2])
	        if (!notedisplay[onfret][3])
	          if (!notedisplay[onfret][4])
            	 if (!notedisplay[onfret][5])
	               blit( x+2, stavetop+1.25*fretspace, rest_img, screen );	//draw rest symbol
    }
  }
  else if(tuningbool)
  {
    octave = 0;
    note = value;
    while(note > 11)
    {
      octave++;
      note -= 12;
    }
	if(sharpbutton.value==0)
	{
      if(note == 0)  {strncpy(prefixtext,"A" ,2); letter = 1; sharp = false;  }
      if(note == 1)  {strncpy(prefixtext,"A#",2); letter = 1; sharp = true;   }
      if(note == 2)  {strncpy(prefixtext,"B" ,2); letter = 2; sharp = false;  } 
      if(note == 3)  {strncpy(prefixtext,"C" ,2); letter = 3; sharp = false;  }
      if(note == 4)  {strncpy(prefixtext,"C#",2); letter = 3; sharp = true;   }
      if(note == 5)  {strncpy(prefixtext,"D" ,2); letter = 4; sharp = false;  }
      if(note == 6)  {strncpy(prefixtext,"D#",2); letter = 4; sharp = true;   }
      if(note == 7)  {strncpy(prefixtext,"E" ,2); letter = 5; sharp = false;  }
      if(note == 8)  {strncpy(prefixtext,"F" ,2); letter = 6; sharp = false;  }
      if(note == 9)  {strncpy(prefixtext,"F#",2); letter = 6; sharp = true;   }
      if(note == 10) {strncpy(prefixtext,"G" ,2); letter = 7; sharp = false;  }
      if(note == 11) {strncpy(prefixtext,"G#",2); letter = 7; sharp = true;   }
	} 
	else
	{
      if(note == 0)  {strncpy(prefixtext,"A" ,2); letter = 1; sharp = false;  }
      if(note == 1)  {strncpy(prefixtext,"Bb",2); letter = 1; sharp = -1;     }
      if(note == 2)  {strncpy(prefixtext,"B" ,2); letter = 2; sharp = false;  } 
      if(note == 3)  {strncpy(prefixtext,"C" ,2); letter = 3; sharp = false;  }
      if(note == 4)  {strncpy(prefixtext,"Db",2); letter = 3; sharp = -1;     }
      if(note == 5)  {strncpy(prefixtext,"D" ,2); letter = 4; sharp = false;  }
      if(note == 6)  {strncpy(prefixtext,"Eb",2); letter = 4; sharp = -1;     }
      if(note == 7)  {strncpy(prefixtext,"E" ,2); letter = 5; sharp = false;  }
      if(note == 8)  {strncpy(prefixtext,"F" ,2); letter = 6; sharp = false;  }
      if(note == 9)  {strncpy(prefixtext,"Gb",2); letter = 6; sharp = -1;     }
      if(note == 10) {strncpy(prefixtext,"G" ,2); letter = 7; sharp = false;  }
      if(note == 11) {strncpy(prefixtext,"Ab",2); letter = 7; sharp = -1;      }
	}
    letter += octave*7;
    draw_textnum(x  ,y, "", octave, prefixtext );
  }
  else if (boolbutton)
  {
    if(active)
	{
      blitrect( x , y, w, h, 128,0,64 );
      displaytext(prefixtext, x+6, y, 255,255,255);   
	}
	else
	{
      blitrect( x , y, w, h, 0,0,64 );
      displaytext(prefixtext, x+6, y, 255,255,255);
	}
  }
  else if (comboscroll)
  {
    blitrect( x , y, w, h, 128,0,64 );
    if(value==0) displaytext(option1, x+6, y, 255,255,255);  
    if(value==1) displaytext(option2, x+6, y, 255,255,255);  
    if(value==2) displaytext(option3, x+6, y, 255,255,255);  
  }
  else
  {
      blitrect( x , y, w, h, 128,0,64 );
      draw_textnum(x+6,y, prefixtext, value, suffixtext );
  }
  mouse1pressedlast = mousepressed[1];
}



