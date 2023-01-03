#pragma once
#include <iostream>
#include <math.h>

#include "Point2D.hpp"


class Vector2D : public float2
{
private:
    /* data */
public:
    
    Vector2D operator+(const Vector2D& P)
    {
        Vector2D res ;
        res.x = this->x + P.x;
        res.y = this->y + P.y;
        return res ;

    }
    Vector2D operator-(const Vector2D& P)
    {
        Vector2D res ;
        res.x = this->x - P.x;
        res.y = this->y - P.y;
        return res ;
    }
        Vector2D operator*(const Vector2D& P)
    {
        Vector2D res ;
        res.x = this->x * P.x;
        res.y = this->y * P.y;
        return res ;
    }
    Vector2D operator/(const Vector2D& P)
    {
        Vector2D res ;
        res.x = this->x / P.x;
        res.y = this->y / P.y;
        return res ;
    }



    Vector2D& operator+=(const Vector2D& P)
    {
        this->x += P.x;
        this->y += P.y;
        return *this ;
    }

    Vector2D& operator-=(const Vector2D& P)
    {
        this->x -= P.x;
        this->y -= P.y;
        return *this ;
    }

    Vector2D& operator*=(const Vector2D& P)
    {
        this->x *= P.x;
        this->y *= P.y;
        return *this ;
    }
    Vector2D& operator/=(const Vector2D& P)
    {
        this->x /= P.x;
        this->y /= P.y;
        return *this ;
    }

    Vector2D(const Point2D &P1, const Point2D &P2);
    Vector2D(Point2D P1, Point2D P2);

    Vector2D(float x, float y)
    {
        this->x = x ;
        this->y = y ;
    }


    Vector2D(/* args */)
    {
        this->x = 0;
        this->y = 0;
    }

    Vector2D(const float2 &pos);

    ~Vector2D();
};

  


