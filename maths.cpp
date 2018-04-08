bool inside_region(int x,int y, int w, int h, int x2,int y2,int w2,int h2)
{
if (x+w > x2)
  if (x < x2+w2)
    if (y+h > y2)
      if (y < y2+h2)
      	return(true);
      else return(false);
    else return(false);
  else return (false);
else return (false);
}

bool inside_region(float x,float y, float w, float h, float x2, float y2)
{
if (x2 > x && x2 < x+w)
  if (y2 > y && y2 < y+h)
    return(true);
  else return(false);
else return(false);
}

int imodulus(int in)		//magnitude of a value regardless of ±
{
if (in < 0) in *= -1;
return(in);
}

float fmodulus(float in)	//magnitude of a value regardless of ±
{
  if (in < 0) in *= -1;
  return(in);
}

int polarity(int in)
{
  if (in >= 0) return(1); 
  else return(-1);
}
int polarity(float in)
{
  if (in >= 0) return(1);
  else return(-1);
}




//begin the physics geekery



float KE2vel (float KE, float mass)
{
  //KE = .5 m v²
  //2KE/m = v²
  //root(2KE/m) = v
  float vel = sqrt( fmodulus(2*KE / mass) );
  if (KE < 0) vel *= -1;
  //cout << "gen'd v is " << vel << ",from KE: " << KE << endl;
  return(vel);
}

float vel2KE (float vel, float mass)
{
  float KE = 0.5 * mass * (vel*vel);
  if(vel < 0) KE *= -1;
  return(KE);
}
