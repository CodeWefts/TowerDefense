
#include"Point2D.hpp"




Point2D::Point2D(const float2& pos)
{
    this->x = pos.x ; 
    this->y = pos.y ; 
}

Point2D::Point2D( float x, float y)
{
    this->x = x;
    this->y = y ;
}
 Point2D::Point2D(void)
{
    this->x = 0;
    this->y = 0;
}

Point2D::~Point2D()
{
}