#pragma once
#include<iostream>





class float2
{
private:
    /* data */
public:

    float x ;
    float y ;


   virtual float2 operator+(const float2& float2_2)
    {
        float2 res ;
        res.x = this->x + float2_2.x ;
        res.y = this->y + float2_2.y ; 

        return res ;
        
    }
    
    virtual float2 operator-(const float2& float2_2)
    {
        float2 res ;
        res.x = this->x - float2_2.x ;
        res.y = this->y - float2_2.y ; 

        return res ;
        
    }

    virtual float2 operator*(const float2& float2_2)
    {
        float2 res ;
        res.x = this->x * float2_2.x ;
        res.y = this->y * float2_2.y ; 

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

    

    float2()
    {
        this->x = 0 ; 
        this->y = 0 ; 
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

