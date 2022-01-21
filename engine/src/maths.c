#include <maths.h>
#include <math.h>


float PE_Distance( pe_vec2 a, pe_vec2 b )
{
  return sqrt( (a.x - b.x)^2 + (a.y - b.y)^2 );
}