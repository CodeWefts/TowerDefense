#pragma once
#include<iostream>
#include "float2.hpp"


class Point2D : public float2
{
private:
    /* data */
public:

    

    Point2D operator+(const Point2D& P)
    {
        Point2D res ;
        res.x = this->x + P.x;
        res.y = this->y + P.y;
        return res ;
    }
    Point2D operator-(const Point2D& P)
    {
        Point2D res ;
        res.x = this->x - P.x;
        res.y = this->y - P.y;
        return res ;
    }
        Point2D operator*(const Point2D& P)
    {
        Point2D res ;
        res.x = this->x * P.x;
        res.y = this->y * P.y;
        return res ;
    }
    Point2D operator/(const Point2D& P)
    {
        Point2D res ;
        res.x = this->x / P.x;
        res.y = this->y / P.y;
        return res ;
    }



    Point2D& operator+=(const Point2D& P)
    {
        this->x += P.x;
        this->y += P.y;
        return *this ;
    }

    Point2D& operator-=(const Point2D& P)
    {
        this->x -= P.x;
        this->y -= P.y;
        return *this ;
    }

    Point2D& operator*=(const Point2D& P)
    {
        this->x *= P.x;
        this->y *= P.y;
        return *this ;
    }
    Point2D& operator/=(const Point2D& P)
    {
        this->x /= P.x;
        this->y /= P.y;
        return *this ;
    }

    Point2D( float x, float y);
    Point2D(const float2& pos);
    Point2D(void);
    ~Point2D();
};    
   
