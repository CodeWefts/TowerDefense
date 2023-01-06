#pragma once
#include<iostream>
#include <imgui.h>




class float2
{
private:
    /* data */
public:

    float x ;
    float y ;

    operator ImVec2() {
        return { x, y };
    }
   


   virtual float2 operator+(const float2& float2_2)
    {
        float2 res ;
        res.x = this->x + float2_2.x ;
        res.y = this->y + float2_2.y ; 

        return res ;
        
    }
    
    virtual float2 operator-(  float2& float2_2)
    {
        float2 res ;
        res.x = this->x - float2_2.x ;
        res.y = this->y - float2_2.y ; 

        return res ;
        
    }

  

    virtual float2 operator/(const float2& float2_2) 
    {
        float2 res ;
        res.x = this->x / float2_2.x ;
        res.y = this->y / float2_2.y ; 

        return res ;
        
    }

    virtual float2& operator+=(const float2& float2_2)
    {
        this->x += float2_2.x ;
        this->y += float2_2.y ;
        return *this ;
        
    }

    virtual float2& operator+=(const float& value)
    {
        this->x += value;
        this->y += value;
        return *this;

    }

    virtual float2& operator-=(const float& value)
    {
        this->x -= value;
        this->y -= value;
        return *this;

    }
    virtual float2& operator-=(const float2& float2_2)
    {
        this->x -= float2_2.x ;
        this->y -= float2_2.y ;
        return *this ;
        
    }

    virtual float2& operator*=(const float2& float2_2)
    {
        this->x *= float2_2.x ;
        this->y *= float2_2.y ;
        return *this ;
        
    }
    virtual float2& operator/=(const float2& float2_2)
    {
        this->x /= float2_2.x ;
        this->y /= float2_2.y ;
        return *this ;
        
    }

    virtual float2& operator=(const float2& float2_2)
    {
        this->x = float2_2.x;
        this->y = float2_2.y;
        return *this;

    }

    virtual float2 operator+(const float& value)
    {
        float2 newFloat2;

        newFloat2.x = this->x + value;
        newFloat2.y = this->y + value;


        return newFloat2;

    }

    virtual float2 operator-(const float& value)
    {
        float2 newFloat2;

        newFloat2.x = this->x - value;
        newFloat2.y = this->y - value;


        return newFloat2;

    }

    

    float2()
    {
        this->x = 0 ; 
        this->y = this->x;
    }
    float2(float x, float y )
    {
        this->x = x ; 
        this->y = y ; 
    }

    ~float2()
    {
    }

};

