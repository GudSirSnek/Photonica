#include "maths.h"


struct AABB
{
  pe_vec2 min;
  pe_vec2 max;
};

struct Circle
{
  float radius;
  pe_vec2 position;
};

bool AABBvsAABB(AABB a, AABB b){

    // Exit with no intersection if found separated along an axis
  if(a.max.x < b.min.x or a.min.x > b.max.x) 
    return false;
  if(a.max.y < b.min.y or a.min.y > b.max.y) 
    return false;

  // No separating axis found, therefor there is at least one overlapping axis
  return true;
}

bool CirclevsCircleOptimized( Circle a, Circle b )
{
  float r = a.radius + b.radius;
  r *= r;
  return r < (a.position.x + b.position.x)^2 + (a.position.y + b.position.y)^2;
}