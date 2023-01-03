#include"include/Vector2D.hpp"



Vector2D::Vector2D(const Point2D& P1,const Point2D& P2)
{
    this->x = P2.x - P1.x ;
    this->y = P2.y - P1.y ;
}

Vector2D::Vector2D(Point2D P1,Point2D P2)
{
    this->x = P2.x - P1.x ;
    this->y = P2.y - P1.y ;
}
/*Vector2D::Vector2D( float x, float y)
{
    this->pos= {x,y};
}*/
Vector2D::Vector2D(const float2& pos )
{
    this->x = pos.x ;
    this->y = pos.y ;
}
    
Vector2D::~Vector2D()
{
}



Vector2D getVectorFromPoint2d(const Point2D& A , const Point2D& B)
{   
    Vector2D output(B.x - A.x ,B.y - A.y) ;
    return output;
}